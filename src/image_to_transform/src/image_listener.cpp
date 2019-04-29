
#include "ros/ros.h"
#include "sensor_msgs/Image.h"
#include "std_msgs/String.h"
//s #include "tf/Transform.h"


// * Callback pastes message data to ROS_INFO logger
 
void callback(const sensor_msgs::Image::ConstPtr& image)
{
    // TODO: this is likely incorrect string formatting for the image message
    //ROS_INFO("I heard: [%s]", image->data);
}

int main(int argc, char** argv)
{
    
     //* Generic init for the image_listener node
     
    ros::init(argc, argv, "image_listener");
    ros::NodeHandle nodeHandler;

    
     //* Creates a subscriber on the images topic. 
     //* Queue size of 1000 messages, beyond that oldest message gets discarded
     //* Callback occur when new messages are seen
     
    ros::Subscriber imagesSubscriber = nodeHandler.subscribe("/panda_camera/images", 1000, callback);

    // ros::Publisher posePublisher = nodeHandler.advertise<tf::Transform>("/CameraToObjectTransform", 1000);

    ros::Rate loop_rate(10);
    int count = 0;

    while(ros::ok())
    {
        // tf::Transform cameraToObjectTransform;
        // cameraToObjectTransform = new tf::Transform();
        // posePublisher.publish(cameraToObjectTransform);

     
     
     
     
     
     
        ros::spinOnce();
        loop_rate.sleep();
        ++count;
    }

    
     //* Keep node alive until ros shutdown is called
     
    ros::spin();
}