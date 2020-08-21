// Generated by gencpp from file nox_msgs/GetSceneRequest.msg
// DO NOT EDIT!


#ifndef NOX_MSGS_MESSAGE_GETSCENEREQUEST_H
#define NOX_MSGS_MESSAGE_GETSCENEREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/PoseStamped.h>

namespace nox_msgs
{
template <class ContainerAllocator>
struct GetSceneRequest_
{
  typedef GetSceneRequest_<ContainerAllocator> Type;

  GetSceneRequest_()
    : location()  {
    }
  GetSceneRequest_(const ContainerAllocator& _alloc)
    : location(_alloc)  {
  (void)_alloc;
    }



   typedef  ::geometry_msgs::PoseStamped_<ContainerAllocator>  _location_type;
  _location_type location;





  typedef boost::shared_ptr< ::nox_msgs::GetSceneRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::nox_msgs::GetSceneRequest_<ContainerAllocator> const> ConstPtr;

}; // struct GetSceneRequest_

typedef ::nox_msgs::GetSceneRequest_<std::allocator<void> > GetSceneRequest;

typedef boost::shared_ptr< ::nox_msgs::GetSceneRequest > GetSceneRequestPtr;
typedef boost::shared_ptr< ::nox_msgs::GetSceneRequest const> GetSceneRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::nox_msgs::GetSceneRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::nox_msgs::GetSceneRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace nox_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'nox_msgs': ['/media/yarten/DATA/Project/ROS/NOX_Project/nox/src/nox_msgs/msg'], 'nav_msgs': ['/opt/ros/melodic/share/nav_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/melodic/share/actionlib_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/melodic/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::nox_msgs::GetSceneRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::nox_msgs::GetSceneRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::nox_msgs::GetSceneRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::nox_msgs::GetSceneRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::nox_msgs::GetSceneRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::nox_msgs::GetSceneRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::nox_msgs::GetSceneRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "5e8ac99e71b788e7cf0b5b68b9c6b3f8";
  }

  static const char* value(const ::nox_msgs::GetSceneRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x5e8ac99e71b788e7ULL;
  static const uint64_t static_value2 = 0xcf0b5b68b9c6b3f8ULL;
};

template<class ContainerAllocator>
struct DataType< ::nox_msgs::GetSceneRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "nox_msgs/GetSceneRequest";
  }

  static const char* value(const ::nox_msgs::GetSceneRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::nox_msgs::GetSceneRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "geometry_msgs/PoseStamped location\n"
"\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/PoseStamped\n"
"# A Pose with reference coordinate frame and timestamp\n"
"Header header\n"
"Pose pose\n"
"\n"
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
;
  }

  static const char* value(const ::nox_msgs::GetSceneRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::nox_msgs::GetSceneRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.location);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GetSceneRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::nox_msgs::GetSceneRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::nox_msgs::GetSceneRequest_<ContainerAllocator>& v)
  {
    s << indent << "location: ";
    s << std::endl;
    Printer< ::geometry_msgs::PoseStamped_<ContainerAllocator> >::stream(s, indent + "  ", v.location);
  }
};

} // namespace message_operations
} // namespace ros

#endif // NOX_MSGS_MESSAGE_GETSCENEREQUEST_H
