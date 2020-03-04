#ifndef _ROS_SERVICE_NextStep_h
#define _ROS_SERVICE_NextStep_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace v1_two_axis
{

static const char NEXTSTEP[] = "v1_two_axis/NextStep";

  class NextStepRequest : public ros::Msg
  {
    public:
      typedef int32_t _startByte_type;
      _startByte_type startByte;

    NextStepRequest():
      startByte(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_startByte;
      u_startByte.real = this->startByte;
      *(outbuffer + offset + 0) = (u_startByte.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_startByte.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_startByte.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_startByte.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->startByte);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_startByte;
      u_startByte.base = 0;
      u_startByte.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_startByte.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_startByte.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_startByte.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->startByte = u_startByte.real;
      offset += sizeof(this->startByte);
     return offset;
    }

    const char * getType(){ return NEXTSTEP; };
    const char * getMD5(){ return "5aebc74ccf3adf41000b023b14cb55e3"; };

  };

  class NextStepResponse : public ros::Msg
  {
    public:
      typedef int32_t _time_type;
      _time_type time;
      typedef int32_t _direction_type;
      _direction_type direction;

    NextStepResponse():
      time(0),
      direction(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_time;
      u_time.real = this->time;
      *(outbuffer + offset + 0) = (u_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_time.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time);
      union {
        int32_t real;
        uint32_t base;
      } u_direction;
      u_direction.real = this->direction;
      *(outbuffer + offset + 0) = (u_direction.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_direction.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_direction.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_direction.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->direction);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_time;
      u_time.base = 0;
      u_time.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_time.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_time.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_time.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->time = u_time.real;
      offset += sizeof(this->time);
      union {
        int32_t real;
        uint32_t base;
      } u_direction;
      u_direction.base = 0;
      u_direction.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_direction.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_direction.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_direction.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->direction = u_direction.real;
      offset += sizeof(this->direction);
     return offset;
    }

    const char * getType(){ return NEXTSTEP; };
    const char * getMD5(){ return "1a4d139afb4179efd8133f67ab1dee8b"; };

  };

  class NextStep {
    public:
    typedef NextStepRequest Request;
    typedef NextStepResponse Response;
  };

}
#endif
