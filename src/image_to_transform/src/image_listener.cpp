#include "ros/ros.h"
#include "sensor_msgs/Image.h"

int main(int argc, char** argv)
{
    /** 
     * Generic init for the image_listener node
     */
    ros::init(argc, argv, "image_listener");
    ros::NodeHandle nodeHandler;

    /** 
     * Creates a subscriber on the images topic. 
     * Queue size of 1000 messages, beyond that oldest message gets discarded
     * Callback occur when new messages are seen
     */
    ros::Subscriber imagesSubscriber = nodeHandler.subscribe("images", 1000, callback);

    /**
     * Keep node alive until ros shutdown is called
     */
    ros::spin();
}

/**
 * Callback pastes message data to ROS_INFO logger
 */
void callback(const sensor_msgs::Image::ConstPtr& image)
{
    // TODO: this is likely incorrect string formatting for the image message
    ROS_INFO("I heard: [%s]", image->data);
}

