#include "ros/ros.h"
#include "comm_msg_custom/person.h"

void resolve_msg(const comm_msg_custom::person::ConstPtr &person_p) {
  ROS_INFO("Name:%s, Age:%d, Height:%.2f", person_p->name.c_str(),
           person_p->age, person_p->height);
}

int main(int argc, char *argv[]) {

  ROS_INFO("This is a listener node");
  setlocale(LC_ALL, "");

  ros::init(argc, argv, "topic_conn_listener");
  ros::NodeHandle nh;
  ros::Subscriber sub = nh.subscribe<comm_msg_custom::person>(
      "chat_test", 10, resolve_msg);

  ros::spin();

  return 0;
}
