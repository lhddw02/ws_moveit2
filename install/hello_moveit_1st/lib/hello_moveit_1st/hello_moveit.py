#!/usr/bin/env python3

import sys
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped

from moveit.planning import MoveItPy
from moveit.core.kinematic_constraints import construct_joint_constraint

def plan_and_execute(robot, planning_component, logger): 
    """Helper to plan and execute a motion.""" 
    logger.info("Planning trajectory...") 
    plan_result = planning_component.plan() 

    if plan_result and plan_result.success: 
        logger.info("Executing trajectory...") 
        robot.execute(plan_result.trajectory) 
    else: logger.error("Planning failed!") 

class HelloMoveIt(Node): 
    def __init__(self): 
        super().__init__('hello_moveit') 

        # Create MoveItPy instance
        self.robot = MoveItPy(node_name="moveit_py")
        # Get planning component for the manipulator group
        self.arm = self.robot.get_planning_component("manipulator")
        self.logger = self.get_logger()
        # Define target pose
        target_pose = PoseStamped()
        target_pose.header.frame_id = "base_link"  # or your base link
        target_pose.pose.orientation.w = 1.0
        target_pose.pose.position.x = 0.28
        target_pose.pose.position.y = -0.2
        target_pose.pose.position.z = 0.5
        # Set goal state
        self.arm.set_goal_state(pose_stamped_msg=target_pose, pose_link="link7")  # replace with your EE link
        # Plan and execute
        plan_and_execute(self.robot, self.arm, self.logger)

def main(args=None):
    rclpy.init(args=args)
    node = HelloMoveIt()

    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()