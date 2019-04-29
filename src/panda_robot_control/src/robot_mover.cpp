#include "ros/ros.h"
#include "sensor_msgs/Image.h"
#include "std_msgs/String.h"
#include "geometry_msgs"


int main(int argc, char** argv)
{
    ros::init(argc, argv, "joint_mover");
    ros::NodeHandle nodeHandler;

    // Not sure what to listen to in order to know where to go but leaving this here
    //ros::Subscriber imagesSubscriber = nodeHandler.subscribe("/panda_camera/images", 1000, callback);

    // Publish to each joint individually
    ros::Publisher joint1Pub = nodeHandler.advertise<int::int>("/joint1_position_controller/command", 1000);
    ros::Publisher joint2Pub = nodeHandler.advertise<int::int>("/joint2_position_controller/command", 1000);
    ros::Publisher joint3Pub = nodeHandler.advertise<int::int>("/joint3_position_controller/command", 1000);
    ros::Publisher joint4Pub = nodeHandler.advertise<int::int>("/joint4_position_controller/command", 1000);
    ros::Publisher joint5Pub = nodeHandler.advertise<int::int>("/joint5_position_controller/command", 1000);
    ros::Publisher joint6Pub = nodeHandler.advertise<int::int>("/joint6_position_controller/command", 1000);
    ros::Publisher joint7Pub = nodeHandler.advertise<int::int>("/joint7_position_controller/command", 1000);


    ros::Rate loop_rate(10);
    int count = 0;

    while(ros::ok())
    {
        int::examplePose = 90;
        joint1Pub.publish(examplePose);
        joint2Pub.publish(examplePose);
        joint3Pub.publish(examplePose);
        joint4Pub.publish(examplePose);
        joint5Pub.publish(examplePose);
        joint6Pub.publish(examplePose);
        joint7Pub.publish(examplePose);

        ros::spinOnce();
        loop_rate.sleep();
        ++count;
    }

    /**
     * Keep node alive until ros shutdown is called
     */
    ros::spin();
}
