#include "geometry_msgs/TransformStamped.h"
#include "ros/ros.h"
#include "ros/time.h"
#include "tf2/LinearMath/Quaternion.h"
#include "tf2_ros/static_transform_broadcaster.h"
#include <string>



int main(int argc, char* argv[])
{
  setlocale(LC_ALL, "");

  std::string str("Static coordinate transform server.");
  ROS_INFO("%s\n", str.c_str());

  ros::init(argc, argv, "static_coord_transform");

  tf2_ros::StaticTransformBroadcaster broadcaster;
  geometry_msgs::TransformStamped ts;

  ts.header.seq = 100;
  ts.header.stamp = ros::Time::now();
  ts.header.frame_id = "base_link";

  ts.child_frame_id = "laser";

  ts.transform.translation.x = 0.2;
  ts.transform.translation.y = 0.0;
  ts.transform.translation.z = 0.5;

  tf2::Quaternion qtn;
  qtn.setRPY(0, 0, 0);
  ts.transform.rotation.x = qtn.getX();
  ts.transform.rotation.y = qtn.getY();
  ts.transform.rotation.z = qtn.getZ();
  ts.transform.rotation.w = qtn.getW();

  broadcaster.sendTransform(ts);
  ros::spin();

  return 0;
}
