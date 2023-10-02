#include "geometry_msgs/Twist.h"
#include "ros/init.h"
#include "ros/ros.h"
#include <cstdlib>
#include <cstring>
#include <ctime>


int main(int argc, char* argv[])
{

  setlocale(LC_ALL, "");
  ROS_INFO("This is a talker node");

  ros::init(argc, argv, "turtle_draw_circle");

  ros::NodeHandle nh;
  ros::Publisher publisher = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 100);

  geometry_msgs::Twist twi;
  twi.angular.x = 0.0;
  twi.angular.y = 0.0;
  twi.angular.z = 0.0;

  twi.linear.x = 0.0;
  twi.linear.y = 0.0;
  twi.linear.z = 0.0;

  ros::Rate r(1);

  srand(time(0));

  while (ros::ok()) {

    publisher.publish(twi);
    ROS_INFO("Publish turtle control.");

    twi.angular.x = static_cast<float>((rand() % 100) - 50) / 100.f;
    twi.angular.y = static_cast<float>((rand() % 100) - 50) / 100.f;
    twi.angular.z = static_cast<float>((rand() % 100) - 50) / 100.f;

    twi.linear.x = static_cast<float>((rand() % 100) - 50) / 100.f;
    twi.linear.y = static_cast<float>((rand() % 100) - 50) / 100.f;
    twi.linear.z = static_cast<float>((rand() % 100) - 50) / 100.f;

    r.sleep();
    ros::spinOnce();
  }
}
