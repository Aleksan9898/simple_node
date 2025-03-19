from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='simple_node',
            executable='simple_node',
            name='simplenode'
        )
    ])