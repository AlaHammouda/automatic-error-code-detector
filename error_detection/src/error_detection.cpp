#include <ros/ros.h>
#include <std_msgs/Bool.h>
#include <std_msgs/String.h>

class ErrorCodeDetector {
public:
  ros::NodeHandle nh_;
  ros::Publisher robot_stop_pub;
  ros::Subscriber error_code_sub;

  std_msgs::Bool stop_cmd;

  ErrorCodeDetector() {
    error_code_sub = nh_.subscribe("/long_term_slam/error_code", 1000,
                                   &ErrorCodeDetector::errorCodeCallback, this);
    robot_stop_pub = nh_.advertise<std_msgs::Bool>("/stop_signal", 1000);
  }

  void errorCodeCallback(const std_msgs::String::ConstPtr &msg) {
    if (msg->data == "WIPALTSLO0308" || msg->data == "WIPALTSLO0306" ||
        msg->data == "TIPALTSLO0309" || msg->data == "OIPALTSLO0300") {

      stop_cmd.data = true;
      ROS_WARN("Stopping the robot ...");
      robot_stop_pub.publish(stop_cmd);

      ROS_ERROR("Localization error code detected: %s", msg->data.c_str());
      ROS_ERROR("Please try to re-localize the robot manually: Estimate the "
                "initial position and drive it around for a few meters");
      ROS_ERROR("Please record rosbags for the issue and contact the technical "
                "support");
    }
  }
};

int main(int argc, char **argv) {
  ros::init(argc, argv, "error_detection_node");

  ErrorCodeDetector errorDetector;

  ros::spin();

  return 0;
}
