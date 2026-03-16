cmake_minimum_required(VERSION 3.8)
project(panda_moveit_config)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

find_package(moveit_ros_planning_interface REQUIRED)
find_package(moveit_py REQUIRED)


install(PROGRAMS
  scripts/arm_control_from_UI.py
  DESTINATION lib/${PROJECT_NAME}
)

install(
  DIRECTORY
    launch
    config
    scripts
    worlds
  DESTINATION share/${PROJECT_NAME}
)

install(FILES .setup_assistant DESTINATION share/${PROJECT_NAME})


ament_package()
