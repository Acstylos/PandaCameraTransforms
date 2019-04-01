#include "ros/ros.h"
#include "sensor_msgs/Image.h"
#include "std_msgs/String.h"

/**
 * Callback pastes message data to ROS_INFO logger
 */
void callback(const sensor_msgs::Image::ConstPtr& image)
{
    // TODO: this is likely incorrect string formatting for the image message
    //ROS_INFO("I heard: [%s]", image->data);
}

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
    ros::Subscriber imagesSubscriber = nodeHandler.subscribe("panda_camera/images", 1000, callback);

    ros::Publisher posePublisher = nodeHandler.advertise<std_msgs::String>("cameraPose", 1000);

    ros::Rate loop_rate(10);
    int count = 0;

    while(ros::ok())
    {
        /**
         * This is a message object. You stuff it with data, and then publish it.
         */
        std_msgs::String msg;

        std::stringstream ss;
        ss << "hello world " << count;
        msg.data = ss.str();

        //ROS_INFO("%s", msg.data.c_str());

        /**
         * The publish() function is how you send messages. The parameter
         * is the message object. The type of this object must agree with the type
         * given as a template parameter to the advertise<>() call, as was done
         * in the constructor above.
         */
        posePublisher.publish(msg);

        ros::spinOnce();

        loop_rate.sleep();
        ++count;
    }

    /**
     * Keep node alive until ros shutdown is called
     */
    ros::spin();
}

