// Generated by gencpp from file sick_scan/RadarPreHeaderStatusBlock.msg
// DO NOT EDIT!


#ifndef SICK_SCAN_MESSAGE_RADARPREHEADERSTATUSBLOCK_H
#define SICK_SCAN_MESSAGE_RADARPREHEADERSTATUSBLOCK_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace sick_scan
{
template <class ContainerAllocator>
struct RadarPreHeaderStatusBlock_
{
  typedef RadarPreHeaderStatusBlock_<ContainerAllocator> Type;

  RadarPreHeaderStatusBlock_()
    : uiTelegramCount(0)
    , uiCycleCount(0)
    , udiSystemCountScan(0)
    , udiSystemCountTransmit(0)
    , uiInputs(0)
    , uiOutputs(0)  {
    }
  RadarPreHeaderStatusBlock_(const ContainerAllocator& _alloc)
    : uiTelegramCount(0)
    , uiCycleCount(0)
    , udiSystemCountScan(0)
    , udiSystemCountTransmit(0)
    , uiInputs(0)
    , uiOutputs(0)  {
  (void)_alloc;
    }



   typedef uint32_t _uiTelegramCount_type;
  _uiTelegramCount_type uiTelegramCount;

   typedef uint32_t _uiCycleCount_type;
  _uiCycleCount_type uiCycleCount;

   typedef uint32_t _udiSystemCountScan_type;
  _udiSystemCountScan_type udiSystemCountScan;

   typedef uint32_t _udiSystemCountTransmit_type;
  _udiSystemCountTransmit_type udiSystemCountTransmit;

   typedef uint16_t _uiInputs_type;
  _uiInputs_type uiInputs;

   typedef uint16_t _uiOutputs_type;
  _uiOutputs_type uiOutputs;





  typedef std::shared_ptr< ::sick_scan::RadarPreHeaderStatusBlock_<ContainerAllocator> > Ptr;
  typedef std::shared_ptr< ::sick_scan::RadarPreHeaderStatusBlock_<ContainerAllocator> const> ConstPtr;

}; // struct RadarPreHeaderStatusBlock_

typedef ::sick_scan::RadarPreHeaderStatusBlock_<std::allocator<void> > RadarPreHeaderStatusBlock;

typedef std::shared_ptr< ::sick_scan::RadarPreHeaderStatusBlock > RadarPreHeaderStatusBlockPtr;
typedef std::shared_ptr< ::sick_scan::RadarPreHeaderStatusBlock const> RadarPreHeaderStatusBlockConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sick_scan::RadarPreHeaderStatusBlock_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sick_scan::RadarPreHeaderStatusBlock_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace sick_scan

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'sensor_msgs': ['/opt/ros/melodic/share/sensor_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/melodic/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg'], 'sick_scan': ['/home/rosuser/catkin_sick_scan/src/sick_scan/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan::RadarPreHeaderStatusBlock_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan::RadarPreHeaderStatusBlock_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan::RadarPreHeaderStatusBlock_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan::RadarPreHeaderStatusBlock_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan::RadarPreHeaderStatusBlock_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan::RadarPreHeaderStatusBlock_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sick_scan::RadarPreHeaderStatusBlock_<ContainerAllocator> >
{
  static const char* value()
  {
    return "fa00447ba5857e64792524ca30b37274";
  }

  static const char* value(const ::sick_scan::RadarPreHeaderStatusBlock_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xfa00447ba5857e64ULL;
  static const uint64_t static_value2 = 0x792524ca30b37274ULL;
};

template<class ContainerAllocator>
struct DataType< ::sick_scan::RadarPreHeaderStatusBlock_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sick_scan/RadarPreHeaderStatusBlock";
  }

  static const char* value(const ::sick_scan::RadarPreHeaderStatusBlock_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sick_scan::RadarPreHeaderStatusBlock_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#\n"
"#\n"
"#\n"
"uint32 uiTelegramCount # telegram number\n"
"uint32 uiCycleCount # \"scan number\"\n"
"uint32 udiSystemCountScan # system time since power on of scan gen. [us]\n"
"uint32 udiSystemCountTransmit # system time since power on of scan transmission [us]\n"
"uint16 uiInputs # state of digital inputs\n"
"uint16 uiOutputs # state of digital outputs\n"
;
  }

  static const char* value(const ::sick_scan::RadarPreHeaderStatusBlock_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sick_scan::RadarPreHeaderStatusBlock_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.uiTelegramCount);
      stream.next(m.uiCycleCount);
      stream.next(m.udiSystemCountScan);
      stream.next(m.udiSystemCountTransmit);
      stream.next(m.uiInputs);
      stream.next(m.uiOutputs);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct RadarPreHeaderStatusBlock_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sick_scan::RadarPreHeaderStatusBlock_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::sick_scan::RadarPreHeaderStatusBlock_<ContainerAllocator>& v)
  {
    s << indent << "uiTelegramCount: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.uiTelegramCount);
    s << indent << "uiCycleCount: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.uiCycleCount);
    s << indent << "udiSystemCountScan: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.udiSystemCountScan);
    s << indent << "udiSystemCountTransmit: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.udiSystemCountTransmit);
    s << indent << "uiInputs: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.uiInputs);
    s << indent << "uiOutputs: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.uiOutputs);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SICK_SCAN_MESSAGE_RADARPREHEADERSTATUSBLOCK_H
