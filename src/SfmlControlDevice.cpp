
#include "SfmlControlDevice.h"
#include <cstdio>
#include <iostream> 

SfmlControlDevice::SfmlControlDevice()
{

}

SfmlControlDevice::~SfmlControlDevice()
{

}

bool SfmlControlDevice::handleInput()
{ 
    // HACKY HACK HACK 
    Eigen::VectorXd cmd(3);
    cmd << 0, 0, 0; 
    setCommand(cmd); 

    sf::Window window(sf::VideoMode(50, 50), "teleop"); 

    while(window.isOpen())
    {
        sf::Event event; 
        while(window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close(); 
                break;
            default:
                break;
            }
        }

        sf::Vector2i thrustDir = getThrustDirection(0); 
        Eigen::VectorXd cmd(3);
        cmd << thrustDir.x, thrustDir.y, 0; 
        appendCommand(cmd); 
    } 
}

void SfmlControlDevice::appendCommand(Eigen::VectorXd anUpdateCmd)
{
    auto current = getCommand(); 
    Eigen::VectorXd result(current.size());

    for (int i = 0; i < current.size(); ++i) 
    {
        result[i] = current[i] == anUpdateCmd[i] ? current[i] : anUpdateCmd[i];    
    }

    setCommand(result); 
}

int SfmlControlDevice::snapAxis(float value, float threshold) 
{
    if (value > threshold) return 1;
    if (value < -threshold) return -1;
    return 0;
}

sf::Vector2i SfmlControlDevice::getThrustDirection(int joystickId) 
{
    if (!sf::Joystick::isConnected(joystickId))
        return {0, 0};

    float xRaw = sf::Joystick::getAxisPosition(joystickId, sf::Joystick::X); // right = +
    float yRaw = sf::Joystick::getAxisPosition(joystickId, sf::Joystick::Y); // down = +

    // Flip Y axis to make up = positive (optional, depends on your world)
    yRaw = -yRaw;

    // Normalize to range [-1.0, 1.0]
    float xNorm = xRaw / 100.f;
    float yNorm = yRaw / 100.f;

    // Snap to discrete thrust values
    int xSnap = snapAxis(xNorm);
    int ySnap = snapAxis(yNorm);

    return {xSnap, ySnap};
}