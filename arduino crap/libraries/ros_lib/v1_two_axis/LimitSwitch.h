#ifndef _ROS_v1_two_axis_LimitSwitch_h
#define _ROS_v1_two_axis_LimitSwitch_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace v1_two_axis
{

  class LimitSwitch : public ros::Msg
  {
    public:
      typedef int32_t _motorIndex_type;
      _motorIndex_type motorIndex;
      typedef bool _tripped_type;
      _tripped_type tripped;

    LimitSwitch():
      motorIndex(0),
      tripped(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_motorIndex;
      u_motorIndex.real = this->motorIndex;
      *(outbuffer + offset + 0) = (u_motorIndex.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_motorIndex.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_motorIndex.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_motorIndex.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->motorIndex);
      union {
        bool real;
        uint8_t base;
      } u_tripped;
      u_tripped.real = this->tripped;
      *(outbuffer + offset + 0) = (u_tripped.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->tripped);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_motorIndex;
      u_motorIndex.base = 0;
      u_motorIndex.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_motorIndex.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_motorIndex.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_motorIndex.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->motorIndex = u_motorIndex.real;
      offset += sizeof(this->motorIndex);
      union {
        bool real;
        uint8_t base;
      } u_tripped;
      u_tripped.base = 0;
      u_tripped.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->tripped = u_tripped.real;
      offset += sizeof(this->tripped);
     return offset;
    }

    const char * getType(){ return "v1_two_axis/LimitSwitch"; };
    const char * getMD5(){ return "e176f5e39d5bcd8a5c7ed47f4ed01dbf"; };

  };

}
#endif
