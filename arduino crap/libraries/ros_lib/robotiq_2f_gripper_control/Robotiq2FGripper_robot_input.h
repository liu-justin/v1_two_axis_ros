#ifndef _ROS_robotiq_2f_gripper_control_Robotiq2FGripper_robot_input_h
#define _ROS_robotiq_2f_gripper_control_Robotiq2FGripper_robot_input_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robotiq_2f_gripper_control
{

  class Robotiq2FGripper_robot_input : public ros::Msg
  {
    public:
      typedef uint8_t _gACT_type;
      _gACT_type gACT;
      typedef uint8_t _gGTO_type;
      _gGTO_type gGTO;
      typedef uint8_t _gSTA_type;
      _gSTA_type gSTA;
      typedef uint8_t _gOBJ_type;
      _gOBJ_type gOBJ;
      typedef uint8_t _gFLT_type;
      _gFLT_type gFLT;
      typedef uint8_t _gPR_type;
      _gPR_type gPR;
      typedef uint8_t _gPO_type;
      _gPO_type gPO;
      typedef uint8_t _gCU_type;
      _gCU_type gCU;

    Robotiq2FGripper_robot_input():
      gACT(0),
      gGTO(0),
      gSTA(0),
      gOBJ(0),
      gFLT(0),
      gPR(0),
      gPO(0),
      gCU(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->gACT >> (8 * 0)) & 0xFF;
      offset += sizeof(this->gACT);
      *(outbuffer + offset + 0) = (this->gGTO >> (8 * 0)) & 0xFF;
      offset += sizeof(this->gGTO);
      *(outbuffer + offset + 0) = (this->gSTA >> (8 * 0)) & 0xFF;
      offset += sizeof(this->gSTA);
      *(outbuffer + offset + 0) = (this->gOBJ >> (8 * 0)) & 0xFF;
      offset += sizeof(this->gOBJ);
      *(outbuffer + offset + 0) = (this->gFLT >> (8 * 0)) & 0xFF;
      offset += sizeof(this->gFLT);
      *(outbuffer + offset + 0) = (this->gPR >> (8 * 0)) & 0xFF;
      offset += sizeof(this->gPR);
      *(outbuffer + offset + 0) = (this->gPO >> (8 * 0)) & 0xFF;
      offset += sizeof(this->gPO);
      *(outbuffer + offset + 0) = (this->gCU >> (8 * 0)) & 0xFF;
      offset += sizeof(this->gCU);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->gACT =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->gACT);
      this->gGTO =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->gGTO);
      this->gSTA =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->gSTA);
      this->gOBJ =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->gOBJ);
      this->gFLT =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->gFLT);
      this->gPR =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->gPR);
      this->gPO =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->gPO);
      this->gCU =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->gCU);
     return offset;
    }

    const char * getType(){ return "robotiq_2f_gripper_control/Robotiq2FGripper_robot_input"; };
    const char * getMD5(){ return "17d49e32c00f4f2fb4fe664060553362"; };

  };

}
#endif
