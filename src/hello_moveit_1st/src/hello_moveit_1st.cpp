#include <memory>

#include <rclcpp/rclcpp.hpp>
#include <moveit/move_group_interface/move_group_interface.hpp>

int main(int argc, char* argv[])
{
  // Initialize ROS and create the Node
  rclcpp::init(argc, argv);
  auto const node = std::make_shared<rclcpp::Node>(
      "hello_moveit", rclcpp::NodeOptions().automatically_declare_parameters_from_overrides(true));

  // Create a ROS logger
  auto const logger = rclcpp::get_logger("hello_moveit");

  // Create the MoveIt MoveGroup Interface
  using moveit::planning_interface::MoveGroupInterface;
  auto move_group_interface = MoveGroupInterface(node, "manipulator");

  auto current_pose = move_group_interface.getCurrentPose("link7").pose;
    RCLCPP_INFO(logger, "Current Position: [x=%.3f, y=%.3f, z=%.3f]",
                current_pose.position.x,
                current_pose.position.y,
                current_pose.position.z);
    RCLCPP_INFO(logger, "End Effector Orientation: [x=%.3f, y=%.3f, z=%.3f, w=%.3f]", 
                current_pose.orientation.x, 
                current_pose.orientation.y, 
                current_pose.orientation.z, 
                current_pose.orientation.w);
    RCLCPP_INFO(logger, "Planning begin....");

  // Set a target Pose
  auto const target_pose = [] {
    geometry_msgs::msg::Pose msg;
    msg.orientation.w = 1.0;
    msg.position.x = 0.28;
    msg.position.y = -0.2;
    msg.position.z = 0.5;
    return msg;
  }();
  move_group_interface.setPoseTarget(target_pose);

  // Create a plan to that target pose
  auto const [success, plan] = [&move_group_interface] {
    moveit::planning_interface::MoveGroupInterface::Plan msg;
    auto const ok = static_cast<bool>(move_group_interface.plan(msg));
    return std::make_pair(ok, msg);
  }();

  // Execute the plan
  if (success)
  {
    move_group_interface.execute(plan);
    auto current_pose = move_group_interface.getCurrentPose("link7").pose;
    RCLCPP_INFO(logger, "Current Position: [x=%.3f, y=%.3f, z=%.3f]",
                current_pose.position.x,
                current_pose.position.y,
                current_pose.position.z);
    RCLCPP_INFO(logger, "End Effector Orientation: [x=%.3f, y=%.3f, z=%.3f, w=%.3f]", 
                current_pose.orientation.x, 
                current_pose.orientation.y, 
                current_pose.orientation.z, 
                current_pose.orientation.w);
    RCLCPP_INFO(logger, "Planning and execution successful!");
  }
  else
  {
    RCLCPP_ERROR(logger, "Planning failed!");
  }

  // Shutdown ROS
  rclcpp::shutdown();
  return 0;
}