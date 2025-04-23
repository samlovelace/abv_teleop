#ifndef SFMLCONTROLDEVICE_H
#define SFMLCONTROLDEVICE_H

#include "IControlDevice.h"

 
class SfmlControlDevice : public IControlDevice
{ 
public:
    SfmlControlDevice();
    ~SfmlControlDevice();

    bool handleInput() override; 
    Eigen::VectorXd getCommand() override; 

private:
   
};
#endif //SFMLCONTROLDEVICE_H