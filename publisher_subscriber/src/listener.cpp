#include "ros/ros.h"
#include "std_msgs/String.h"

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");

  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);

  /**
   * ros::spin() 将会进入循环， 一直调用回调函数chatterCallback(),每次调用1000个数据。
   * 当用户输入Ctrl+C或者ROS主进程关闭时退出，
   */
  ros::spin();

  return 0;
}
