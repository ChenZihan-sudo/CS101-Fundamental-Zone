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

  ros::init(argc, argv, "static_coord_transform");
  ros::NodeHandle nh;

  tf2_ros::Buffer buffer;
  tf2_ros::TransformListener listener(buffer);

  ros::Rate r(1);
  while (ros::ok()) {
    geometry_msgs::PointStamped point_laser;
    point_laser.header.frame_id = "laser";
    point_laser.header.stamp = ros::Time::now();
point_laser.point
  }

  //   ros::ok()
}
