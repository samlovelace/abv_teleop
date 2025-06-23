#ifndef SFMLCONTROLDEVICE_H
#define SFMLCONTROLDEVICE_H

#include "IControlDevice.h"
#include <SFML/Window.hpp>

 
class SfmlControlDevice : public IControlDevice
{ 
public:
    SfmlControlDevice();
    ~SfmlControlDevice();

    bool handleInput() override; 

private:

    void appendCommand(Eigen::VectorXd anUpdateCmd); 
    sf::Vector2i getThrustDirection(int joystickId); 
    int snapAxis(float value, float threshold = 0.5f);
    bool mFirstConnected; 

};
#endif //SFMLCONTROLDEVICE_H