
#include "TeleopController.h"
#include "ControlDeviceFactory.h"

int main()
{
    auto controlDevice = ControlDeviceFactory::create("sfml"); 
    TeleopController tc(controlDevice); 
    tc.run();  
}
