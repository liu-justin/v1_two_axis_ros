#ifndef _ROS_SERVICE_Home_h
#define _ROS_SERVICE_Home_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace v1_two_axis
{

static const char HOME[] = "v1_two_axis/Home";

  class HomeRequest : public ros::Msg
  {
    public:

    HomeRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return HOME; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class HomeResponse : public ros::Msg
  {
    public:
      typedef const char* _confirmation_type;
      _confirmation_type confirmation;

    HomeResponse():
      confirmation("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_confirmation = strlen(this->confirmation);
      varToArr(outbuffer + offset, length_confirmation);
      offset += 4;
      memcpy(outbuffer + offset, this->confirmation, length_confirmation);
      offset += length_confirmation;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_confirmation;
      arrToVar(length_confirmation, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_confirmation; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_confirmation-1]=0;
      this->confirmation = (char *)(inbuffer + offset-1);
      offset += length_confirmation;
     return offset;
    }

    const char * getType(){ return HOME; };
    const char * getMD5(){ return "5fdcda0f95399f6b72fea1643acc7e4b"; };

  };

  class Home {
    public:
    typedef HomeRequest Request;
    typedef HomeResponse Response;
  };

}
#endif
