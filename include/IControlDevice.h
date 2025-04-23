#ifndef ICONTROLDEVICE_H
#define ICONTROLDEVICE_H
 
#include <eigen3/Eigen/Dense>
 
class IControlDevice 
{ 
public:
    virtual ~IControlDevice() = default; 
    virtual bool handleInput() = 0; 
    virtual Eigen::VectorXd getCommand() = 0; 

private:
   
};
#endif //ICONTROLDEVICE_H   