#include "simple_node/simple_node.hpp"

SimpleNode::SimpleNode(): Node("simple_node"){
    publisher_ = this->create_publisher<std_msgs::msg::String>("node_topic", 10);
    timer_ = this->create_wall_timer(std::chrono::seconds(1), std::bind(&SimpleNode::timer_callback,this));
    subscription_ = this->create_subscription<std_msgs::msg::String>("node_topic", 10,
        std::bind(&SimpleNode::topic_callback,this, std::placeholders::_1));
}

void SimpleNode::timer_callback(){
    auto message = std_msgs::msg::String();
    message.data = "Message from timer_callback";
    publisher_->publish(message);
    RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
}

void SimpleNode::topic_callback(const std_msgs::msg::String::SharedPtr message) const{
    RCLCPP_INFO(this->get_logger(), "Received: '%s'", message->data.c_str());
}

