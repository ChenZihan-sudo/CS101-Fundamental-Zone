#include "ros/ros.h"
#include "topic_conn_test_msg_custom/person.h"

int main(int argc, char* argv[])
{

  ROS_INFO("This is a talker node");
  setlocale(LC_ALL, "");

  ros::init(argc, argv, "topic_conn_talker");
  ros::NodeHandle nh;
  ros::Publisher publisher =
      nh.advertise<topic_conn_test_msg_custom::person>("chat_test", 10);

  topic_conn_test_msg_custom::person person;
  person.age = 50;
  person.height = 180.1;
  person.name = "Catcolia";

  ros::Rate r(1);

  while (ros::ok()) {

    publisher.publish(person);
    person.age += 1;

    ROS_INFO("Publish message.  Name:%s Age:%d Height:%f", person.name.c_str(),
             person.age, person.height);

    r.sleep();
    ros::spinOnce();
  }

  return 0;
}
