#ifndef TELEOPCONTROLLER_H
#define TELEOPCONTROLLER_H
 
#include <memory> 
#include "IControlDevice.h"
#include <thread> 
#include <mutex> 
 
class TeleopController 
{ 
public:
    TeleopController(std::shared_ptr<IControlDevice> aControlDevice);
    ~TeleopController();

    void run(); 


private:

    void commandPublishLoop(); 

    std::shared_ptr<IControlDevice> mControlDevice; 

    std::thread mCommandPublishThread; 
    std::mutex mCommand; 
};
#endif //TELEOPCONTROLLER_H 