#include "geometry_msgs/PointStamped.h"
#include "ros/init.h"
#include "ros/node_handle.h"
#include "ros/rate.h"
#include "ros/ros.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
#include "tf2_ros/buffer.h"
#include "tf2_ros/transform_listener.h"


int main(int argc, char* argv[])
{
  setlocale(LC_ALL, "");

  ros::init(argc, argv, "static_coord_transform_client");
  ros::NodeHandle nh;

  tf2_ros::Buffer buffer;
  tf2_ros::TransformListener listener(buffer);

  ros::Rate r(1);
  while (ros::ok()) {
    geometry_msgs::PointStamped point_laser;
    point_laser.header.frame_id = "laser";
    point_laser.header.stamp = ros::Time::now();
    point_laser.point.x = 1;
    point_laser.point.y = 2;
    point_laser.point.z = 7.3;

    try {
      geometry_msgs::PointStamped point_base;
      point_base = buffer.transform(point_laser, "base_link");
      ROS_INFO("转换后的数据:(%.2f,%.2f,%.2f),参考的坐标系是:%s", point_base.point.x,
               point_base.point.y,
               point_base.point.z, point_base.header.frame_id.c_str());

    } catch (const std::exception& e) {
      std::cout << e.what() << std::endl;
    }

    r.sleep();
    ros::spinOnce();
  }
}
