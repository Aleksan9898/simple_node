# ROS2 Simple Node

Это ROS2 пакет, который содержит в себе простой узел. Класс `SimpleNode` является этим узлом, который публикует сообщения раз в секунду и одновременно подписывается на топик, выводя полученные данные в консоль.

## Описание

Этот проект демонстрирует базовую работу с ROS2, создавая узел, который выполняет два действия:
1. Публикует сообщения типа `std_msgs::msg::String` каждую секунду.
2. Подписывается на тот же топик, выводя полученные сообщения в консоль.

## Установка

Для установки ROS и запуска пакета, пожалуйста, ознакомьтесь с официальной инструкцией по установке ROS2, доступной по следующей ссылке: [Установка ROS2](https://docs.ros.org/en/foxy/Installation.html).
