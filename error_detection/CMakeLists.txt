cmake_minimum_required(VERSION 3.0.2)
project(error_detection)

find_package(catkin REQUIRED COMPONENTS
  roscpp
)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(error_detection src/error_detection.cpp)

add_dependencies(error_detection ${error_detection_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(error_detection
  ${catkin_LIBRARIES}
)