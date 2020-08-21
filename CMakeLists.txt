#author:>---zhoutotong

CMAKE_MINIMUM_REQUIRED(VERSION 3.8)             #cmake 最低版本要求，低于2.6 构建过程会被终止。

PROJECT(tool_box)                         #定义工程名称

SET(CMAKE_BUILE_TYPE DEBUG)                     #指定编译类型
SET(CMAKE_C_FLAGS_DEBUG "-g -Wall")             #指定编译器


# 查找 Qt5 库支持
find_package(Qt5 COMPONENTS Core Gui Qml Quick REQUIRED Widgets Charts)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(current_dir ${CMAKE_CURRENT_SOURCE_DIR})

link_directories(
    ${current_dir}/ros_tools/devel/lib
)

# find_package(nox_msgs REQUIRED)
find_package(roscpp REQUIRED
)

include(/opt/nox/devel/share/nox/cmake/noxConfig.cmake)

# find_package(catkin REQUIRED COMPONENTS
#     nox
# )

message(nox:${nox_INCLUDE_DIRS})

include_directories(
    ./
    ./can_monitor
    ./commons   
    ./protocol_tool
    ./pid_tool
    ./ros_helper
    /opt/nox/src/nox_msgs/include
    /opt/nox/src/nox/include/
    /opt/nox/src/nox/include/nox
    /usr/include/python3.6m
    ${roscpp_INCLUDE_DIRS}
#   ${nox_msgs_INCLUDE_DIRS}
)

AUX_SOURCE_DIRECTORY(./ DIR_SRCS)
AUX_SOURCE_DIRECTORY(./commons COMMONS_SRCS)
AUX_SOURCE_DIRECTORY(./protocol_tool PROTOCOL_TOOL_SRCS)
AUX_SOURCE_DIRECTORY(./pid_tool PID_TOOL_SRCS)
AUX_SOURCE_DIRECTORY(./can_monitor CAN_MONITOR_SRCS)
AUX_SOURCE_DIRECTORY(./ros_helper ROS_HELPER_SRCS)


set(SOURCE_FILES
${DIR_SRCS}
${COMMONS_SRCS}
${PROTOCOL_TOOL_SRCS}
${PID_TOOL_SRCS}
${CAN_MONITOR_SRCS}
${ROS_HELPER_SRCS}
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} 
Qt5::Core 
Qt5::Gui 
Qt5::Widgets
Qt5::Charts
${roscpp_LIBRARIES}
)
# ADD_SUBDIRECTORY(<sub_dir01>)                       #添加子目录
# ADD_SUBDIRECTORY(<sub_dir02>)