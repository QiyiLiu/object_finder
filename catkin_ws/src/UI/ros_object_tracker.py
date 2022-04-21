from track_objects import MultiObjectTracker
import rospy
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError
import cv2

class UI():
    def __init__(self):
        self.bridge = CvBridge()
        rospy.init_node('object_tracker', anonymous=True)
        # Initalize a subscriber to the "/camera/rgb/image_raw" topic with the function "image_callback" as a callback
        self.sub_image = rospy.Subscriber("/yolov4_publisher/color/image", Image, image_callback)

    # Define a callback for the Image message
    def image_callback(self, img_msg):
        # log some info about the image topic
        rospy.loginfo(img_msg.header)
        try:
            cv_image = self.bridge.imgmsg_to_cv2(img_msg, "bgr8")
        except CvBridgeError as e:
            print(e)


        cv2.imshow("image", cv_image)
        cv2.waitKey(1)

def main():
    UI()

    # Loop to keep the program from shutting down unless ROS is shut down, or CTRL+C is pressed
    while not rospy.is_shutdown():
        rospy.spin()