#ifndef COMMSUTILS_H
#define COMMSUTILS_H

#include "robot_idl/msg/abv_command.hpp"

namespace CommsUtils
{
    static robot_idl::msg::AbvCommand commandMsgToIdl(const Eigen::VectorXd& aData)
    {
        robot_idl::msg::AbvCommand cmd;
        robot_idl::msg::AbvVec3 vec; 
        vec.set__x(aData[0]); 
        vec.set__y(aData[1]); 
        vec.set__yaw(aData[2]);  
        cmd.set__type("thruster"); 
        cmd.set__data(vec); 

        return cmd; 
    }
};

#endif