// Generated by gencpp from file nox_msgs/Lane.msg
// DO NOT EDIT!


#ifndef NOX_MSGS_MESSAGE_LANE_H
#define NOX_MSGS_MESSAGE_LANE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/Vector3.h>

namespace nox_msgs
{
template <class ContainerAllocator>
struct Lane_
{
  typedef Lane_<ContainerAllocator> Type;

  Lane_()
    : points()
    , type(0)
    , reliability(0)  {
    }
  Lane_(const ContainerAllocator& _alloc)
    : points(_alloc)
    , type(0)
    , reliability(0)  {
  (void)_alloc;
    }



   typedef std::vector< ::geometry_msgs::Vector3_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::geometry_msgs::Vector3_<ContainerAllocator> >::other >  _points_type;
  _points_type points;

   typedef uint8_t _type_type;
  _type_type type;

   typedef int32_t _reliability_type;
  _reliability_type reliability;



  enum {
    TYPE_UNDEFINED = 0u,
    TYPE_WHITE = 16u,
    TYPE_YELLOW = 32u,
    TYPE_SOLID = 1u,
    TYPE_DASHED = 2u,
    TYPE_DOUBLE = 3u,
  };


  typedef boost::shared_ptr< ::nox_msgs::Lane_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::nox_msgs::Lane_<ContainerAllocator> const> ConstPtr;

}; // struct Lane_

typedef ::nox_msgs::Lane_<std::allocator<void> > Lane;

typedef boost::shared_ptr< ::nox_msgs::Lane > LanePtr;
typedef boost::shared_ptr< ::nox_msgs::Lane const> LaneConstPtr;

// constants requiring out of line definition

   

   

   

   

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::nox_msgs::Lane_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::nox_msgs::Lane_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::nox_msgs::Lane_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::nox_msgs::Lane_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::nox_msgs::Lane_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::nox_msgs::Lane_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::nox_msgs::Lane_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::nox_msgs::Lane_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::nox_msgs::Lane_<ContainerAllocator> >
{
  static const char* value()
  {
    return "b4275dfce71f7a5e68616ea4f370eefa";
  }

  static const char* value(const ::nox_msgs::Lane_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xb4275dfce71f7a5eULL;
  static const uint64_t static_value2 = 0x68616ea4f370eefaULL;
};

template<class ContainerAllocator>
struct DataType< ::nox_msgs::Lane_<ContainerAllocator> >
{
  static const char* value()
  {
    return "nox_msgs/Lane";
  }

  static const char* value(const ::nox_msgs::Lane_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::nox_msgs::Lane_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint8 TYPE_UNDEFINED =   0\n"
"uint8 TYPE_WHITE     =  16 # 0x10\n"
"uint8 TYPE_YELLOW    =  32 # 0x20\n"
"uint8 TYPE_SOLID     =   1 # 0x01\n"
"uint8 TYPE_DASHED    =   2 # 0x02\n"
"uint8 TYPE_DOUBLE    =   3 # 0x03\n"
"\n"
"geometry_msgs/Vector3[] points\n"
"uint8 type\n"
"int32 reliability\n"
"\n"
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
;
  }

  static const char* value(const ::nox_msgs::Lane_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::nox_msgs::Lane_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.points);
      stream.next(m.type);
      stream.next(m.reliability);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Lane_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::nox_msgs::Lane_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::nox_msgs::Lane_<ContainerAllocator>& v)
  {
    s << indent << "points[]" << std::endl;
    for (size_t i = 0; i < v.points.size(); ++i)
    {
      s << indent << "  points[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::geometry_msgs::Vector3_<ContainerAllocator> >::stream(s, indent + "    ", v.points[i]);
    }
    s << indent << "type: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.type);
    s << indent << "reliability: ";
    Printer<int32_t>::stream(s, indent + "  ", v.reliability);
  }
};

} // namespace message_operations
} // namespace ros

#endif // NOX_MSGS_MESSAGE_LANE_H
