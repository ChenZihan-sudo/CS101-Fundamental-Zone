#include "comm_msg_custom/add_sums.h"
#include "ros/ros.h"

bool add_sums_req(comm_msg_custom::add_sums::Request& request,
                  comm_msg_custom::add_sums::Response& response)
{
  int num1 = request.num1;
  int num2 = request.num2;
  int num3 = request.num3;

  ROS_INFO("Get response. n1:%d n2:%d n3:%d", num1, num2, num3);

  if (num1 < 0 || num2 < 0 || num3 < 0) return false;

  response.sum = num1 + num2 + num3;

  return true;
}

int main(int argc, char* argv[])
{
  setlocale(LC_ALL, "");

  ros::init(argc, argv, "topic_conn_talker");
  ros::NodeHandle nh;
  ros::ServiceServer ss = nh.advertiseService("add_sums_svc", add_sums_req);

  ROS_INFO("This is a talker node.");
  ROS_INFO("Service started. %s", ss.getService().c_str());

  ros::spin();
}
