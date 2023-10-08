#include "comm_msg_custom/add_sums.h"
#include "ros/console.h"
#include "ros/ros.h"
#include "ros/service_client.h"
#include <cstdlib>

int main(int argc, char* argv[])
{
  if (argc <= 2) {
    ROS_INFO("Usage: add_sums_client -h");
    ROS_INFO("Usage: add_sums_client <num1> <num2> <num3>");

    std::string str_arg1 = *new std::string(argv[1]);
    ROS_INFO("String of arg1: %s", str_arg1.c_str());
    return 0;
  }

  if (argc != 4) {
    ROS_ERROR("Need 3 num args to sum.");
    ROS_INFO("Usage: add_sums_client <num1> <num2> <num3>");
    return 0;
  }

  setlocale(LC_ALL, "");

  ros::init(argc, argv, "topic_conn_listener");
  ros::NodeHandle nh;
  ros::ServiceClient sc =
      nh.serviceClient<comm_msg_custom::add_sums>("add_sums_svc");

  ROS_INFO("Wait for service started...");
  sc.waitForExistence();

  ros::service::waitForService("add_sums_svc");

  comm_msg_custom::add_sums add_sums;
  add_sums.request.num1 = atoi(argv[1]);
  add_sums.request.num2 = atoi(argv[2]);
  add_sums.request.num3 = atoi(argv[3]);

  bool result = ros::service::call("add_sums_svc", add_sums);

  if (!result) return 0;

  ROS_INFO("Response result: %d", add_sums.response.sum);

  return 0;
}
