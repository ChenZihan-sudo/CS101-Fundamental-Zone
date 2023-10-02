#include "ros/ros.h"
#include <string>
#include <sys/types.h>

int main(int argc, char* argv[])
{
  setlocale(LC_ALL, "");
  ros::init(argc, argv, "set_update_param");

  std::vector<std::string> person;
  person.push_back("person_1");
  person.push_back("person_2");
  person.push_back("person_3");
  person.push_back("person_4");
  person.push_back("person_5");

  std::map<std::string, std::string> email;
  auto size = 0;
  for (auto str : person) {
    size++;
    email[str] = std::to_string(size) + "test@example.com";
  }

  ros::NodeHandle nh;
  nh.setParam("nh_name", person);
  nh.setParam("nh_email", email);
  nh.setParam("nh_int", 100);
  nh.setParam("nh_bool", true);
  nh.setParam("nh_double", 3.14);

  ros::param::set("param_name", person);
  ros::param::set("param_email", email);
  ros::param::set("param_int", 100);
  ros::param::set("param_bool", false);
  ros::param::set("param_double", 3.14);

  return 0;
}
