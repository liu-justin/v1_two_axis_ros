#ifndef _ROS_SERVICE_EndpointsToSteps_h
#define _ROS_SERVICE_EndpointsToSteps_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace v1_two_axis
{

static const char ENDPOINTSTOSTEPS[] = "v1_two_axis/EndpointsToSteps";

  class EndpointsToStepsRequest : public ros::Msg
  {
    public:
      typedef float _startPointX_type;
      _startPointX_type startPointX;
      typedef float _startPointY_type;
      _startPointY_type startPointY;
      typedef float _endPointX_type;
      _endPointX_type endPointX;
      typedef float _endPointY_type;
      _endPointY_type endPointY;

    EndpointsToStepsRequest():
      startPointX(0),
      startPointY(0),
      endPointX(0),
      endPointY(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_startPointX;
      u_startPointX.real = this->startPointX;
      *(outbuffer + offset + 0) = (u_startPointX.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_startPointX.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_startPointX.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_startPointX.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->startPointX);
      union {
        float real;
        uint32_t base;
      } u_startPointY;
      u_startPointY.real = this->startPointY;
      *(outbuffer + offset + 0) = (u_startPointY.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_startPointY.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_startPointY.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_startPointY.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->startPointY);
      union {
        float real;
        uint32_t base;
      } u_endPointX;
      u_endPointX.real = this->endPointX;
      *(outbuffer + offset + 0) = (u_endPointX.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_endPointX.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_endPointX.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_endPointX.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->endPointX);
      union {
        float real;
        uint32_t base;
      } u_endPointY;
      u_endPointY.real = this->endPointY;
      *(outbuffer + offset + 0) = (u_endPointY.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_endPointY.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_endPointY.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_endPointY.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->endPointY);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_startPointX;
      u_startPointX.base = 0;
      u_startPointX.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_startPointX.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_startPointX.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_startPointX.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->startPointX = u_startPointX.real;
      offset += sizeof(this->startPointX);
      union {
        float real;
        uint32_t base;
      } u_startPointY;
      u_startPointY.base = 0;
      u_startPointY.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_startPointY.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_startPointY.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_startPointY.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->startPointY = u_startPointY.real;
      offset += sizeof(this->startPointY);
      union {
        float real;
        uint32_t base;
      } u_endPointX;
      u_endPointX.base = 0;
      u_endPointX.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_endPointX.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_endPointX.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_endPointX.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->endPointX = u_endPointX.real;
      offset += sizeof(this->endPointX);
      union {
        float real;
        uint32_t base;
      } u_endPointY;
      u_endPointY.base = 0;
      u_endPointY.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_endPointY.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_endPointY.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_endPointY.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->endPointY = u_endPointY.real;
      offset += sizeof(this->endPointY);
     return offset;
    }

    const char * getType(){ return ENDPOINTSTOSTEPS; };
    const char * getMD5(){ return "4531a34c2acfb515e3db3e6def66c299"; };

  };

  class EndpointsToStepsResponse : public ros::Msg
  {
    public:
      uint32_t R0Time_length;
      typedef int32_t _R0Time_type;
      _R0Time_type st_R0Time;
      _R0Time_type * R0Time;
      uint32_t R0Direction_length;
      typedef int32_t _R0Direction_type;
      _R0Direction_type st_R0Direction;
      _R0Direction_type * R0Direction;
      uint32_t RATime_length;
      typedef int32_t _RATime_type;
      _RATime_type st_RATime;
      _RATime_type * RATime;
      uint32_t RADirection_length;
      typedef int32_t _RADirection_type;
      _RADirection_type st_RADirection;
      _RADirection_type * RADirection;

    EndpointsToStepsResponse():
      R0Time_length(0), R0Time(NULL),
      R0Direction_length(0), R0Direction(NULL),
      RATime_length(0), RATime(NULL),
      RADirection_length(0), RADirection(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->R0Time_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->R0Time_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->R0Time_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->R0Time_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->R0Time_length);
      for( uint32_t i = 0; i < R0Time_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_R0Timei;
      u_R0Timei.real = this->R0Time[i];
      *(outbuffer + offset + 0) = (u_R0Timei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_R0Timei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_R0Timei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_R0Timei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->R0Time[i]);
      }
      *(outbuffer + offset + 0) = (this->R0Direction_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->R0Direction_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->R0Direction_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->R0Direction_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->R0Direction_length);
      for( uint32_t i = 0; i < R0Direction_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_R0Directioni;
      u_R0Directioni.real = this->R0Direction[i];
      *(outbuffer + offset + 0) = (u_R0Directioni.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_R0Directioni.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_R0Directioni.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_R0Directioni.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->R0Direction[i]);
      }
      *(outbuffer + offset + 0) = (this->RATime_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->RATime_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->RATime_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->RATime_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->RATime_length);
      for( uint32_t i = 0; i < RATime_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_RATimei;
      u_RATimei.real = this->RATime[i];
      *(outbuffer + offset + 0) = (u_RATimei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_RATimei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_RATimei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_RATimei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->RATime[i]);
      }
      *(outbuffer + offset + 0) = (this->RADirection_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->RADirection_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->RADirection_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->RADirection_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->RADirection_length);
      for( uint32_t i = 0; i < RADirection_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_RADirectioni;
      u_RADirectioni.real = this->RADirection[i];
      *(outbuffer + offset + 0) = (u_RADirectioni.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_RADirectioni.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_RADirectioni.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_RADirectioni.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->RADirection[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t R0Time_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      R0Time_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      R0Time_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      R0Time_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->R0Time_length);
      if(R0Time_lengthT > R0Time_length)
        this->R0Time = (int32_t*)realloc(this->R0Time, R0Time_lengthT * sizeof(int32_t));
      R0Time_length = R0Time_lengthT;
      for( uint32_t i = 0; i < R0Time_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_R0Time;
      u_st_R0Time.base = 0;
      u_st_R0Time.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_R0Time.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_R0Time.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_R0Time.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_R0Time = u_st_R0Time.real;
      offset += sizeof(this->st_R0Time);
        memcpy( &(this->R0Time[i]), &(this->st_R0Time), sizeof(int32_t));
      }
      uint32_t R0Direction_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      R0Direction_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      R0Direction_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      R0Direction_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->R0Direction_length);
      if(R0Direction_lengthT > R0Direction_length)
        this->R0Direction = (int32_t*)realloc(this->R0Direction, R0Direction_lengthT * sizeof(int32_t));
      R0Direction_length = R0Direction_lengthT;
      for( uint32_t i = 0; i < R0Direction_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_R0Direction;
      u_st_R0Direction.base = 0;
      u_st_R0Direction.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_R0Direction.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_R0Direction.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_R0Direction.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_R0Direction = u_st_R0Direction.real;
      offset += sizeof(this->st_R0Direction);
        memcpy( &(this->R0Direction[i]), &(this->st_R0Direction), sizeof(int32_t));
      }
      uint32_t RATime_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      RATime_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      RATime_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      RATime_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->RATime_length);
      if(RATime_lengthT > RATime_length)
        this->RATime = (int32_t*)realloc(this->RATime, RATime_lengthT * sizeof(int32_t));
      RATime_length = RATime_lengthT;
      for( uint32_t i = 0; i < RATime_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_RATime;
      u_st_RATime.base = 0;
      u_st_RATime.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_RATime.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_RATime.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_RATime.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_RATime = u_st_RATime.real;
      offset += sizeof(this->st_RATime);
        memcpy( &(this->RATime[i]), &(this->st_RATime), sizeof(int32_t));
      }
      uint32_t RADirection_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      RADirection_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      RADirection_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      RADirection_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->RADirection_length);
      if(RADirection_lengthT > RADirection_length)
        this->RADirection = (int32_t*)realloc(this->RADirection, RADirection_lengthT * sizeof(int32_t));
      RADirection_length = RADirection_lengthT;
      for( uint32_t i = 0; i < RADirection_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_RADirection;
      u_st_RADirection.base = 0;
      u_st_RADirection.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_RADirection.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_RADirection.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_RADirection.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_RADirection = u_st_RADirection.real;
      offset += sizeof(this->st_RADirection);
        memcpy( &(this->RADirection[i]), &(this->st_RADirection), sizeof(int32_t));
      }
     return offset;
    }

    const char * getType(){ return ENDPOINTSTOSTEPS; };
    const char * getMD5(){ return "7bebd90d0be5163698a05edbd0b5493c"; };

  };

  class EndpointsToSteps {
    public:
    typedef EndpointsToStepsRequest Request;
    typedef EndpointsToStepsResponse Response;
  };

}
#endif
