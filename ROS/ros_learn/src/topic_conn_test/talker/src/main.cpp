#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

int main(int argc, char *argv[]) {

  ROS_INFO("This is a talker node");
  setlocale(LC_ALL, "");

  ros::init(argc, argv, "topic_conn_talker");
  ros::NodeHandle nh;
  ros::Publisher publisher = nh.advertise<std_msgs::String>("chat_test", 10);

  ros::Rate r(1);

  std_msgs::String msg;
  std::string msg_front = "Hello 你好。";
  int count = 0;

  while (ros::ok()) {
    std::stringstream ss;
    ss << msg_front << count;
    msg.data = ss.str();

    publisher.publish(msg);
    ROS_INFO("Publish message. %s", msg.data.c_str());
    r.sleep();
    count++;
    ros::spinOnce();
  }

  return 0;
}