#include "geometry_msgs/TransformStamped.h"
#include "ros/init.h"
#include "ros/ros.h"
#include "ros/time.h"
#include "tf2/LinearMath/Quaternion.h"
#include "tf2_ros/transform_broadcaster.h"
#include "turtlesim/Pose.h"

void doPose(const turtlesim::Pose::ConstPtr& pose)
{
  static tf2_ros::TransformBroadcaster broadcaster;
  geometry_msgs::TransformStamped tfs;

  tfs.header.frame_id = "world";
  tfs.header.stamp = ros::Time::now();

  tfs.child_frame_id = "turtle1";
  tfs.transform.translation.x = pose->x - 5.544;
  tfs.transform.translation.y = pose->y - 5.544;
  tfs.transform.translation.z = 0.0;

  tf2::Quaternion qtn;
  qtn.setRPY(0, 0, pose->theta);
  tfs.transform.rotation.x = qtn.getX();
  tfs.transform.rotation.y = qtn.getY();
  tfs.transform.rotation.z = qtn.getZ();
  tfs.transform.rotation.w = qtn.getW();

  broadcaster.sendTransform(tfs);
}

int main(int argc, char* argv[])
{
  setlocale(LC_ALL, "");
  ros::init(argc, argv, "turtle_pose_pub");
  ros::NodeHandle nh;
  ros::Subscriber sub = nh.subscribe<turtlesim::Pose>("/turtle1/pose", 1000, doPose);

  ros::spin();
}
