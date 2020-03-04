#ifndef _ROS_robotiq_2f_gripper_control_Robotiq2FGripper_robot_output_h
#define _ROS_robotiq_2f_gripper_control_Robotiq2FGripper_robot_output_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robotiq_2f_gripper_control
{

  class Robotiq2FGripper_robot_output : public ros::Msg
  {
    public:
      typedef uint8_t _rACT_type;
      _rACT_type rACT;
      typedef uint8_t _rGTO_type;
      _rGTO_type rGTO;
      typedef uint8_t _rATR_type;
      _rATR_type rATR;
      typedef uint8_t _rPR_type;
      _rPR_type rPR;
      typedef uint8_t _rSP_type;
      _rSP_type rSP;
      typedef uint8_t _rFR_type;
      _rFR_type rFR;

    Robotiq2FGripper_robot_output():
      rACT(0),
      rGTO(0),
      rATR(0),
      rPR(0),
      rSP(0),
      rFR(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->rACT >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rACT);
      *(outbuffer + offset + 0) = (this->rGTO >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rGTO);
      *(outbuffer + offset + 0) = (this->rATR >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rATR);
      *(outbuffer + offset + 0) = (this->rPR >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rPR);
      *(outbuffer + offset + 0) = (this->rSP >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rSP);
      *(outbuffer + offset + 0) = (this->rFR >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rFR);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->rACT =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->rACT);
      this->rGTO =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->rGTO);
      this->rATR =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->rATR);
      this->rPR =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->rPR);
      this->rSP =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->rSP);
      this->rFR =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->rFR);
     return offset;
    }

    const char * getType(){ return "robotiq_2f_gripper_control/Robotiq2FGripper_robot_output"; };
    const char * getMD5(){ return "481503a99d995d0e403b7ee708c6862c"; };

  };

}
#endif
