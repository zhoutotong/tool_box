// Generated by gencpp from file nox_msgs/Obstacle.msg
// DO NOT EDIT!


#ifndef NOX_MSGS_MESSAGE_OBSTACLE_H
#define NOX_MSGS_MESSAGE_OBSTACLE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <nox_msgs/Trajectory.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/Vector3.h>
#include <geometry_msgs/Polygon.h>
#include <geometry_msgs/Vector3.h>
#include <nox_msgs/Overlap.h>

namespace nox_msgs
{
template <class ContainerAllocator>
struct Obstacle_
{
  typedef Obstacle_<ContainerAllocator> Type;

  Obstacle_()
    : header()
    , id(0)
    , prediction()
    , pose()
    , length()
    , vertexes()
    , speed()
    , confidence(0.0)
    , type(0)
    , overlaps()  {
    }
  Obstacle_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , id(0)
    , prediction(_alloc)
    , pose(_alloc)
    , length(_alloc)
    , vertexes(_alloc)
    , speed(_alloc)
    , confidence(0.0)
    , type(0)
    , overlaps(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef uint64_t _id_type;
  _id_type id;

   typedef  ::nox_msgs::Trajectory_<ContainerAllocator>  _prediction_type;
  _prediction_type prediction;

   typedef  ::geometry_msgs::Pose_<ContainerAllocator>  _pose_type;
  _pose_type pose;

   typedef  ::geometry_msgs::Vector3_<ContainerAllocator>  _length_type;
  _length_type length;

   typedef  ::geometry_msgs::Polygon_<ContainerAllocator>  _vertexes_type;
  _vertexes_type vertexes;

   typedef  ::geometry_msgs::Vector3_<ContainerAllocator>  _speed_type;
  _speed_type speed;

   typedef double _confidence_type;
  _confidence_type confidence;

   typedef uint32_t _type_type;
  _type_type type;

   typedef std::vector< ::nox_msgs::Overlap_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::nox_msgs::Overlap_<ContainerAllocator> >::other >  _overlaps_type;
  _overlaps_type overlaps;



  enum {
    UNKNOWN = 0u,
    HUMAN = 1u,
    CAR = 2u,
  };


  typedef boost::shared_ptr< ::nox_msgs::Obstacle_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::nox_msgs::Obstacle_<ContainerAllocator> const> ConstPtr;

}; // struct Obstacle_

typedef ::nox_msgs::Obstacle_<std::allocator<void> > Obstacle;

typedef boost::shared_ptr< ::nox_msgs::Obstacle > ObstaclePtr;
typedef boost::shared_ptr< ::nox_msgs::Obstacle const> ObstacleConstPtr;

// constants requiring out of line definition

   

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::nox_msgs::Obstacle_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::nox_msgs::Obstacle_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace nox_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'nox_msgs': ['/media/yarten/DATA/Project/ROS/NOX_Project/nox/src/nox_msgs/msg'], 'nav_msgs': ['/opt/ros/melodic/share/nav_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/melodic/share/actionlib_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/melodic/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::nox_msgs::Obstacle_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::nox_msgs::Obstacle_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::nox_msgs::Obstacle_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::nox_msgs::Obstacle_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::nox_msgs::Obstacle_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::nox_msgs::Obstacle_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::nox_msgs::Obstacle_<ContainerAllocator> >
{
  static const char* value()
  {
    return "7cad779b70bea5a6fbcfdc5eee7fbf63";
  }

  static const char* value(const ::nox_msgs::Obstacle_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x7cad779b70bea5a6ULL;
  static const uint64_t static_value2 = 0xfbcfdc5eee7fbf63ULL;
};

template<class ContainerAllocator>
struct DataType< ::nox_msgs::Obstacle_<ContainerAllocator> >
{
  static const char* value()
  {
    return "nox_msgs/Obstacle";
  }

  static const char* value(const ::nox_msgs::Obstacle_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::nox_msgs::Obstacle_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n"
"\n"
"uint64 id                       # 障碍物ID（由LoMap生成）\n"
"\n"
"Trajectory prediction           # 障碍物预测路径（静态障碍物为空，或只有一个点）\n"
"\n"
"geometry_msgs/Pose pose         # 障碍物位姿\n"
"\n"
"geometry_msgs/Vector3 length    # 障碍物包围在x, y, z方向的长度（该方向是障碍物本身的坐标系）\n"
"\n"
"geometry_msgs/Polygon vertexes  # 障碍物顶点\n"
"\n"
"geometry_msgs/Vector3 speed     # 障碍物速度，秒速\n"
"\n"
"float64 confidence              # 障碍物可靠性\n"
"\n"
"uint32 type                     # 障碍物类型\n"
"\n"
"Overlap[] overlaps              # 障碍物的覆盖情况（给地图使用）\n"
"\n"
"# -----------------------------------\n"
"# 障碍物类型枚举: TODO\n"
"\n"
"uint32 UNKNOWN = 0\n"
"uint32 HUMAN = 1\n"
"uint32 CAR = 2\n"
"\n"
"# -----------------------------------\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
"\n"
"================================================================================\n"
"MSG: nox_msgs/Trajectory\n"
"# Description a trajectory with time and position information\n"
"\n"
"Header header\n"
"\n"
"TrajectoryPoint[] points\n"
"================================================================================\n"
"MSG: nox_msgs/TrajectoryPoint\n"
"# Description the point on a trajectory\n"
"\n"
"PathPoint info\n"
"float64 v\n"
"float64 a\n"
"float64 t\n"
"================================================================================\n"
"MSG: nox_msgs/PathPoint\n"
"# Description the point on a path\n"
"\n"
"geometry_msgs/Pose pose\n"
"float64 kappa\n"
"float64 dkappa\n"
"float64 s\n"
"float64 width   # 路点的宽度（指车道宽度）\n"
"Bound   bound   # 路点的边界（指整个路的边界，相对于该点的横向距离）\n"
"================================================================================\n"
"MSG: geometry_msgs/Pose\n"
"# A representation of pose in free space, composed of position and orientation. \n"
"Point position\n"
"Quaternion orientation\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Point\n"
"# This contains the position of a point in free space\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Quaternion\n"
"# This represents an orientation in free space in quaternion form.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"float64 w\n"
"\n"
"================================================================================\n"
"MSG: nox_msgs/Bound\n"
"float64 lower # lower bound\n"
"float64 upper # upper bound\n"
"================================================================================\n"
"MSG: geometry_msgs/Vector3\n"
"# This represents a vector in free space. \n"
"# It is only meant to represent a direction. Therefore, it does not\n"
"# make sense to apply a translation to it (e.g., when applying a \n"
"# generic rigid transformation to a Vector3, tf2 will only apply the\n"
"# rotation). If you want your data to be translatable too, use the\n"
"# geometry_msgs/Point message instead.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"================================================================================\n"
"MSG: geometry_msgs/Polygon\n"
"#A specification of a polygon where the first and last points are assumed to be connected\n"
"Point32[] points\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Point32\n"
"# This contains the position of a point in free space(with 32 bits of precision).\n"
"# It is recommeded to use Point wherever possible instead of Point32.  \n"
"# \n"
"# This recommendation is to promote interoperability.  \n"
"#\n"
"# This message is designed to take up less space when sending\n"
"# lots of points at once, as in the case of a PointCloud.  \n"
"\n"
"float32 x\n"
"float32 y\n"
"float32 z\n"
"================================================================================\n"
"MSG: nox_msgs/Overlap\n"
"uint64 id       # 覆盖信息本身的ID\n"
"uint64 on       # 被覆盖物的ID\n"
"uint8 type      # 被覆盖物的类型\n"
"float64 start   # 被覆盖的范围起始（时间或距离，由语境定义）\n"
"float64 end     # 被覆盖的范围终止\n"
"\n"
"# -----------------------------------\n"
"# Type to overlap\n"
"\n"
"uint8 UNKNOWN = 0\n"
"uint8 LANE = 1\n"
"\n"
"# -----------------------------------\n"
;
  }

  static const char* value(const ::nox_msgs::Obstacle_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::nox_msgs::Obstacle_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.id);
      stream.next(m.prediction);
      stream.next(m.pose);
      stream.next(m.length);
      stream.next(m.vertexes);
      stream.next(m.speed);
      stream.next(m.confidence);
      stream.next(m.type);
      stream.next(m.overlaps);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Obstacle_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::nox_msgs::Obstacle_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::nox_msgs::Obstacle_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "id: ";
    Printer<uint64_t>::stream(s, indent + "  ", v.id);
    s << indent << "prediction: ";
    s << std::endl;
    Printer< ::nox_msgs::Trajectory_<ContainerAllocator> >::stream(s, indent + "  ", v.prediction);
    s << indent << "pose: ";
    s << std::endl;
    Printer< ::geometry_msgs::Pose_<ContainerAllocator> >::stream(s, indent + "  ", v.pose);
    s << indent << "length: ";
    s << std::endl;
    Printer< ::geometry_msgs::Vector3_<ContainerAllocator> >::stream(s, indent + "  ", v.length);
    s << indent << "vertexes: ";
    s << std::endl;
    Printer< ::geometry_msgs::Polygon_<ContainerAllocator> >::stream(s, indent + "  ", v.vertexes);
    s << indent << "speed: ";
    s << std::endl;
    Printer< ::geometry_msgs::Vector3_<ContainerAllocator> >::stream(s, indent + "  ", v.speed);
    s << indent << "confidence: ";
    Printer<double>::stream(s, indent + "  ", v.confidence);
    s << indent << "type: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.type);
    s << indent << "overlaps[]" << std::endl;
    for (size_t i = 0; i < v.overlaps.size(); ++i)
    {
      s << indent << "  overlaps[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::nox_msgs::Overlap_<ContainerAllocator> >::stream(s, indent + "    ", v.overlaps[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // NOX_MSGS_MESSAGE_OBSTACLE_H