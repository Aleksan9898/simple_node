#include "rclcpp/rclcpp.hpp"
#include "simple_node/simple_node.hpp"


int main(int argc, char* argv[]){
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SimpleNode>());
    rclcpp::shutdown();
    return 0;
}