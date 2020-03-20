#ifndef _ROS_v1_two_axis_BlindMotorCommand_h
#define _ROS_v1_two_axis_BlindMotorCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace v1_two_axis
{

  class BlindMotorCommand : public ros::Msg
  {
    public:
      typedef int32_t _index_type;
      _index_type index;
      typedef bool _rotationDirection_type;
      _rotationDirection_type rotationDirection;

    BlindMotorCommand():
      index(0),
      rotationDirection(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_index;
      u_index.real = this->index;
      *(outbuffer + offset + 0) = (u_index.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_index.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_index.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_index.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->index);
      union {
        bool real;
        uint8_t base;
      } u_rotationDirection;
      u_rotationDirection.real = this->rotationDirection;
      *(outbuffer + offset + 0) = (u_rotationDirection.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rotationDirection);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_index;
      u_index.base = 0;
      u_index.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_index.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_index.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_index.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->index = u_index.real;
      offset += sizeof(this->index);
      union {
        bool real;
        uint8_t base;
      } u_rotationDirection;
      u_rotationDirection.base = 0;
      u_rotationDirection.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->rotationDirection = u_rotationDirection.real;
      offset += sizeof(this->rotationDirection);
     return offset;
    }

    const char * getType(){ return "v1_two_axis/BlindMotorCommand"; };
    const char * getMD5(){ return "70b6c99c3636069438948369e041b3ab"; };

  };

}
#endif
