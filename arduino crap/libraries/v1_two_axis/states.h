#ifndef _ROS_v1_two_axis_states_h
#define _ROS_v1_two_axis_states_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace v1_two_axis
{

  class states : public ros::Msg
  {
    public:
      uint32_t states_length;
      typedef int32_t _states_type;
      _states_type st_states;
      _states_type * states;

    states():
      states_length(0), states(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->states_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->states_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->states_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->states_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->states_length);
      for( uint32_t i = 0; i < states_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_statesi;
      u_statesi.real = this->states[i];
      *(outbuffer + offset + 0) = (u_statesi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_statesi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_statesi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_statesi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->states[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t states_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      states_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      states_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      states_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->states_length);
      if(states_lengthT > states_length)
        this->states = (int32_t*)realloc(this->states, states_lengthT * sizeof(int32_t));
      states_length = states_lengthT;
      for( uint32_t i = 0; i < states_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_states;
      u_st_states.base = 0;
      u_st_states.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_states.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_states.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_states.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_states = u_st_states.real;
      offset += sizeof(this->st_states);
        memcpy( &(this->states[i]), &(this->st_states), sizeof(int32_t));
      }
     return offset;
    }

    const char * getType(){ return "v1_two_axis/states"; };
    const char * getMD5(){ return "6744d26bbe2f5d4176b3dd441f4ce08d"; };

  };

}
#endif
