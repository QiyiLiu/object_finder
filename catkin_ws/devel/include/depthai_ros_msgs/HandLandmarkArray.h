// Generated by gencpp from file depthai_ros_msgs/HandLandmarkArray.msg
// DO NOT EDIT!


#ifndef DEPTHAI_ROS_MSGS_MESSAGE_HANDLANDMARKARRAY_H
#define DEPTHAI_ROS_MSGS_MESSAGE_HANDLANDMARKARRAY_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <depthai_ros_msgs/HandLandmark.h>

namespace depthai_ros_msgs
{
template <class ContainerAllocator>
struct HandLandmarkArray_
{
  typedef HandLandmarkArray_<ContainerAllocator> Type;

  HandLandmarkArray_()
    : header()
    , landmarks()  {
    }
  HandLandmarkArray_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , landmarks(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef std::vector< ::depthai_ros_msgs::HandLandmark_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::depthai_ros_msgs::HandLandmark_<ContainerAllocator> >::other >  _landmarks_type;
  _landmarks_type landmarks;





  typedef boost::shared_ptr< ::depthai_ros_msgs::HandLandmarkArray_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::depthai_ros_msgs::HandLandmarkArray_<ContainerAllocator> const> ConstPtr;

}; // struct HandLandmarkArray_

typedef ::depthai_ros_msgs::HandLandmarkArray_<std::allocator<void> > HandLandmarkArray;

typedef boost::shared_ptr< ::depthai_ros_msgs::HandLandmarkArray > HandLandmarkArrayPtr;
typedef boost::shared_ptr< ::depthai_ros_msgs::HandLandmarkArray const> HandLandmarkArrayConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::depthai_ros_msgs::HandLandmarkArray_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::depthai_ros_msgs::HandLandmarkArray_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::depthai_ros_msgs::HandLandmarkArray_<ContainerAllocator1> & lhs, const ::depthai_ros_msgs::HandLandmarkArray_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.landmarks == rhs.landmarks;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::depthai_ros_msgs::HandLandmarkArray_<ContainerAllocator1> & lhs, const ::depthai_ros_msgs::HandLandmarkArray_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace depthai_ros_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::depthai_ros_msgs::HandLandmarkArray_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::depthai_ros_msgs::HandLandmarkArray_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::depthai_ros_msgs::HandLandmarkArray_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::depthai_ros_msgs::HandLandmarkArray_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::depthai_ros_msgs::HandLandmarkArray_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::depthai_ros_msgs::HandLandmarkArray_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::depthai_ros_msgs::HandLandmarkArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "9215903cb0dba0f3a32440758d1e30e6";
  }

  static const char* value(const ::depthai_ros_msgs::HandLandmarkArray_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x9215903cb0dba0f3ULL;
  static const uint64_t static_value2 = 0xa32440758d1e30e6ULL;
};

template<class ContainerAllocator>
struct DataType< ::depthai_ros_msgs::HandLandmarkArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "depthai_ros_msgs/HandLandmarkArray";
  }

  static const char* value(const ::depthai_ros_msgs::HandLandmarkArray_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::depthai_ros_msgs::HandLandmarkArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# A list of hand landmark detections\n"
"\n"
"std_msgs/Header header\n"
"# A list of the detected proposals. A multi-proposal detector might generate along with the 3D depth information\n"
"#   this list with many candidate detections generated from a single input.\n"
"HandLandmark[] landmarks\n"
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
"MSG: depthai_ros_msgs/HandLandmark\n"
"\n"
"# Center of the \n"
"\n"
"string label\n"
"\n"
"# Landmarks score.\n"
"float32 lm_score\n"
"\n"
"geometry_msgs/Pose2D[] landmark\n"
"\n"
"geometry_msgs/Point position\n"
"bool is_spatial\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Pose2D\n"
"# Deprecated\n"
"# Please use the full 3D pose.\n"
"\n"
"# In general our recommendation is to use a full 3D representation of everything and for 2D specific applications make the appropriate projections into the plane for their calculations but optimally will preserve the 3D information during processing.\n"
"\n"
"# If we have parallel copies of 2D datatypes every UI and other pipeline will end up needing to have dual interfaces to plot everything. And you will end up with not being able to use 3D tools for 2D use cases even if they're completely valid, as you'd have to reimplement it with different inputs and outputs. It's not particularly hard to plot the 2D pose or compute the yaw error for the Pose message and there are already tools and libraries that can do this for you.\n"
"\n"
"\n"
"# This expresses a position and orientation on a 2D manifold.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 theta\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Point\n"
"# This contains the position of a point in free space\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
;
  }

  static const char* value(const ::depthai_ros_msgs::HandLandmarkArray_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::depthai_ros_msgs::HandLandmarkArray_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.landmarks);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct HandLandmarkArray_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::depthai_ros_msgs::HandLandmarkArray_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::depthai_ros_msgs::HandLandmarkArray_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "landmarks[]" << std::endl;
    for (size_t i = 0; i < v.landmarks.size(); ++i)
    {
      s << indent << "  landmarks[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::depthai_ros_msgs::HandLandmark_<ContainerAllocator> >::stream(s, indent + "    ", v.landmarks[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // DEPTHAI_ROS_MSGS_MESSAGE_HANDLANDMARKARRAY_H