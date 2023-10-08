#include "ros/ros.h"

int main(int argc, char* argv[])
{
  setlocale(LC_ALL, "");
  ros::init(argc, argv, "get_param");

  int res3 = ros::param::param("param_int", -1);      // 存在
  int res4 = ros::param::param("param_int_asdf", -1); // 不存在返回默认
  ROS_INFO("Param get result:%d,%d", res3, res4);

  
}
