#ifndef SIMPLE_NODE_HPP_
#define SIMPLE_NODE_HPP_
#include <chrono>
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"


/**
 * Этот класс является узлом ROS (наследует rclcpp::Node).
 * Узел публикует сообщения раз в секунду и одновременно подписывается на топик, 
 * выводя полученные данные в консоль.
 */
class SimpleNode: public rclcpp::Node {
public:
    /**
     * Конструктор узла SimpleNode.
     * Этот конструктор инициализирует узел с именем "simple_node", создаёт:
     * - Публикующий объект, который будет отправлять сообщения типа std_msgs::msg::String на топик "node_topic" с размером очереди 10.
     * - Таймер, который вызывает функцию `timer_callback()` каждую секунду.
     * - Подписку на топик "node_topic", которая вызывает функцию `topic_callback()` при получении сообщения.
     */
    SimpleNode();
private:
    void timer_callback(); 
    void topic_callback(const std_msgs::msg::String::SharedPtr msg) const;

    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;  
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
    rclcpp::TimerBase::SharedPtr timer_; 
};

#endif
