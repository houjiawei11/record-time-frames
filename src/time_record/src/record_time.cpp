#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sensor_msgs/Image.h"
#include <iostream>
using namespace std;
#include "time.h"
#include <fstream>

bool first_flag=0;
double time1;
void Record(const sensor_msgs::ImagePtr msg)
{
  if(!first_flag)
  {
    time1=msg->header.stamp.toSec();
    first_flag=1;
  }
  double time=msg->header.stamp.toSec()-time1;
  fstream f1;
  f1.open("time1.txt",ios::app|ios::out);
  if(!f1.is_open()){cout<<"no file open!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;return ;}
  f1<<time<<endl;
  f1.close();
  cout<<time<<endl;
}
int main(int argc, char **argv)
{
  

  ros::init(argc, argv, "TimeRecord");

  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("/camera/rgb/image_rect_color", 1, Record);
  ROS_INFO("Record Time of Images");

  ros::spin();

  return 0;
}
