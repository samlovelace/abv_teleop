
#include "SfmlControlDevice.h"
#include <cstdio>

SfmlControlDevice::SfmlControlDevice()
{

}

SfmlControlDevice::~SfmlControlDevice()
{

}

bool SfmlControlDevice::handleInput()
{ 
    printf("handlin dat shit\n"); 
}

Eigen::VectorXd SfmlControlDevice::getCommand()
{
    printf("getting cmd\n");
    return Eigen::VectorXd(Eigen::Vector3d::Zero()); 
}