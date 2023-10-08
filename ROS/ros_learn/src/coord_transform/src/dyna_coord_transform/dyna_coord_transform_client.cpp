#include "geometry_msgs/PointStamped.h"
#include "geometry_msgs/PoseStamped.h"
#include "geometry_msgs/TransformStamped.h"
#include "geometry_msgs/Vector3Stamped.h"
#include "ros/init.h"
#include "ros/rate.h"
#include "ros/ros.h"
#include "ros/time.h"
#include "tf2/LinearMath/Matrix3x3.h"
#include "tf2/LinearMath/Quaternion.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
#include "tf2_ros/buffer.h"
#include "tf2_ros/transform_broadcaster.h"
#include "tf2_ros/transform_listener.h"
#include "turtlesim/Pose.h"
#include <exception>

int main(int argc, char* argv[])
{
  setlocale(LC_ALL, "");
  ros::init(argc, argv, "turtle_pose_get");
  ros::NodeHandle nh;

  tf2_ros::Buffer buffer;
  tf2_ros::TransformListener listener(buffer);
  ros::Rate r(10);

  while (ros::ok()) {

    geometry_msgs::PoseStamped point;

    point.header.frame_id = "turtle1";
    point.header.stamp = ros::Time();

    point.pose.position.x = 0.0;
    point.pose.position.y = 0.0;
    point.pose.position.z = 0.0;

    point.pose.orientation.x = 0.0;
    point.pose.orientation.y = 0.0;
    point.pose.orientation.z = 0.0;
    point.pose.orientation.w = 1.0;

    try {
      geometry_msgs::PoseStamped point_world = buffer.transform(point, "world");

      tf2::Quaternion qtn(point_world.pose.orientation.x,
                          point_world.pose.orientation.y,
                          point_world.pose.orientation.z,
                          point_world.pose.orientation.w);
      tf2::Matrix3x3 mat(qtn);
      tf2Scalar roll, pitch, yaw;
      mat.getRPY(roll, pitch, yaw);

      ROS_INFO("转换后的数据:(%.2f,%.2f,%.2f),angle r:%.2f p:%.2f y:%.2f",
               point_world.pose.position.x,
               point_world.pose.position.y,
               point_world.pose.position.z,
               roll, pitch, yaw);

    } catch (const std::exception& e) {
      std::cout << e.what() << std::endl;
    }

    r.sleep();
    ros::spinOnce();
  }
}
