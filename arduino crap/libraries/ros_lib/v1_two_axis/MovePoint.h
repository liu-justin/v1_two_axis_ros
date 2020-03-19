#ifndef _ROS_SERVICE_MovePoint_h
#define _ROS_SERVICE_MovePoint_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace v1_two_axis
{

static const char MOVEPOINT[] = "v1_two_axis/MovePoint";

  class MovePointRequest : public ros::Msg
  {
    public:
      typedef float _pointX_type;
      _pointX_type pointX;
      typedef float _pointY_type;
      _pointY_type pointY;

    MovePointRequest():
      pointX(0),
      pointY(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_pointX;
      u_pointX.real = this->pointX;
      *(outbuffer + offset + 0) = (u_pointX.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pointX.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pointX.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pointX.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pointX);
      union {
        float real;
        uint32_t base;
      } u_pointY;
      u_pointY.real = this->pointY;
      *(outbuffer + offset + 0) = (u_pointY.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pointY.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pointY.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pointY.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pointY);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_pointX;
      u_pointX.base = 0;
      u_pointX.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pointX.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pointX.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pointX.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pointX = u_pointX.real;
      offset += sizeof(this->pointX);
      union {
        float real;
        uint32_t base;
      } u_pointY;
      u_pointY.base = 0;
      u_pointY.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pointY.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pointY.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pointY.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pointY = u_pointY.real;
      offset += sizeof(this->pointY);
     return offset;
    }

    const char * getType(){ return MOVEPOINT; };
    const char * getMD5(){ return "90f0140c0df79b25d8fd4bf60dd4990b"; };

  };

  class MovePointResponse : public ros::Msg
  {
    public:
      typedef const char* _response_type;
      _response_type response;

    MovePointResponse():
      response("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_response = strlen(this->response);
      varToArr(outbuffer + offset, length_response);
      offset += 4;
      memcpy(outbuffer + offset, this->response, length_response);
      offset += length_response;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_response;
      arrToVar(length_response, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_response; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_response-1]=0;
      this->response = (char *)(inbuffer + offset-1);
      offset += length_response;
     return offset;
    }

    const char * getType(){ return MOVEPOINT; };
    const char * getMD5(){ return "6de314e2dc76fbff2b6244a6ad70b68d"; };

  };

  class MovePoint {
    public:
    typedef MovePointRequest Request;
    typedef MovePointResponse Response;
  };

}
#endif
