#include "ros/ros.h"
#include "std_msgs/String.h"

void resolve_msg(const std_msgs::String::ConstPtr &msg_p) {
  ROS_INFO("Get listener data.");
  ROS_INFO("Listener get data: %s", msg_p->data.c_str());
}

int main(int argc, char *argv[]) {

  ROS_INFO("This is a listener node");
  setlocale(LC_ALL, "");

  ros::init(argc, argv, "topic_conn_listener");
  ros::NodeHandle nh;
  ros::Subscriber sub =
      nh.subscribe<std_msgs::String>("chat_test", 10, resolve_msg);

  ros::spin();

  return 0;
}
