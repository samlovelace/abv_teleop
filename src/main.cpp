
#include "TeleopController.h"
#include "ControlDeviceFactory.h"
#include "RosTopicManager.h"
#include <robot_idl/msg/abv_command.hpp>

// Signal handler function
void signalHandler(int signal) {

    // LOGD  << "\n" << R"(
    // _________________________
    // |                       |
    // |   SHUTTING DOWN...    |
    // |_______________________|
    //         \   ^__^
    //          \  (oo)\_______
    //             (__)\       )\/\
    //                 ||----w |
    //                 ||     ||)";
    exit(0); // Exit the program
}

int main()
{
    std::signal(SIGINT, signalHandler);

    rclcpp::init(0, nullptr); 
    auto topicManager = RosTopicManager::getInstance(); 
    topicManager->createPublisher<robot_idl::msg::AbvCommand>("abv_command"); 
    topicManager->spinNode(); 
    
    auto controlDevice = ControlDeviceFactory::create("sfml"); 
    TeleopController tc(controlDevice); 
    tc.run(); 
    
    rclcpp::shutdown(); 
}
