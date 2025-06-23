#ifndef COMMSUTILS_H
#define COMMSUTILS_H

#include "abv_idl/msg/abv_command.hpp"

namespace CommsUtils
{
    static abv_idl::msg::AbvCommand commandMsgToIdl(const Eigen::VectorXd& aData)
    {
        abv_idl::msg::AbvCommand cmd;
        abv_idl::msg::AbvVec3 vec; 
        vec.set__x(aData[0]); 
        vec.set__y(aData[1]); 
        vec.set__yaw(aData[2]);  
        cmd.set__type("thruster"); 
        cmd.set__data(vec); 

        return cmd; 
    }
};

#endif