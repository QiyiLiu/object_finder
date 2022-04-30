#!/usr/bin/env python3
from track_objects import MultiObjectTracker, annotate_frame
import rospy
from sensor_msgs.msg import Image
from geometry_msgs.msg import PoseStamped 
from depthai_ros_msgs.msg import SpatialDetectionArray
from cv_bridge import CvBridge, CvBridgeError
import cv2
import numpy as np


class UI():
    def __init__(self):
        self.bridge = CvBridge()
        self.tracked_ids = [41,39, 76, 56, 63]
        self.colors = [[255,0,0], [0,255,0], [0,0,255], [255,255,0], [255,0,255]]
        self.annotation_tracked = [None, None]
        self.annotation_detection = [None, None]
        self.intrinsic = np.array([[600.48120117, 0., 200.15670776], [0., 599.72149658, 214.27590942], [0., 0., 1.]])
        self.camera_poses_pos_np = []
        self.camera_poses_rot_np = []
        self.object_ids = []
        self.detection_object_pos_np = []
        self.tracker = MultiObjectTracker(tracked_objects_id= self.tracked_ids)
        self.out = cv2.VideoWriter('outpy.avi',cv2.VideoWriter_fourcc('M','J','P','G'), 10, (416,416))
        # Initalize a subscriber to the "/camera/rgb/image_raw" topic with the function "image_callback" as a callback
        self.pose = rospy.Subscriber("/orb_pose", PoseStamped, self.pose_callback)
        self.object_pos = rospy.Subscriber("/yolov4_publisher/color/yolov4_Spatial_detections", SpatialDetectionArray, self.update)
        self.sub_image = rospy.Subscriber("/yolov4_publisher/color/image", Image, self.image_callback)
        
    # Define a callback for the Image message
    def image_callback(self, img_msg):
        # log some info about the image topic
        # rospy.loginfo(img_msg.header)
        try:
            self.cv_image = self.bridge.imgmsg_to_cv2(img_msg, "bgr8")
        except CvBridgeError as e:
            print(e)
        self.annotation_detection =[]
        for tracked_id in self.tracked_ids:
            blah = None
            for i in range(0, len(self.object_ids)):
                if tracked_id == self.object_ids[i]:
                    # print(self.detection_object_pos_np)
                    blah = self.detection_object_pos_np[i]
            self.annotation_detection.append(blah)
        annotate_frame(self.cv_image, self.annotation_detection, self.annotation_tracked, self.colors, self.intrinsic)
        self.out.write(self.cv_image)
        cv2.imshow("UI", self.cv_image)
        cv2.waitKey(1)
        
    def pose_callback(self, pose):
        # print(pose.pose.position.x)
        self.camera_poses_pos_np = np.array([pose.pose.position.x,
                            pose.pose.position.y,
                            pose.pose.position.z ])
        self.camera_poses_rot_np = np.array([pose.pose.orientation.x,
                                           pose.pose.orientation.y, 
                                           pose.pose.orientation.z,
                                           pose.pose.orientation.w])
        self.annotation_tracked = self.tracker.get_tracked_objects_cameraframe_pos(camera_pose_pos_np=self.camera_poses_pos_np, 
                                                        camera_pose_rot_np=self.camera_poses_rot_np)

    def update(self, detections):

        # print(detections.detections[0].results)
        self.object_ids = []
        self.detection_object_pos_np = []
        if detections.detections != []:
            detection_time = detections.header.stamp.secs
            for detection in detections.detections:
                # print(detection.results[0].id)
                for i in range (0,len(detection.results)):
                    if detection.results[i].id in self.tracked_ids:
                        if detection.results[i].id not in self.object_ids:
                            self.object_ids.append(detection.results[i].id)
                            print(self.object_ids)
                            self.detection_object_pos_np.append(np.array([detection.position.x, -detection.position.y, detection.position.z]))
                            
                        else:
                            for ii in range (0, len(self.object_ids)):
                                if self.object_ids[ii] == detection.results[i].id:
                                    self.detection_object_pos_np[ii]= np.array([detection.position.x, -detection.position.y, detection.position.z])
            print(self.object_ids)
            print(self.detection_object_pos_np)
            self.tracker.update(self.camera_poses_pos_np, self.camera_poses_rot_np, 
                                detection_time,self.object_ids, self.detection_object_pos_np)


def main():
    rospy.init_node('object_tracker', anonymous=True)
    ui = UI()

    # Loop to keep the program from shutting down unless ROS is shut down, or CTRL+C is pressed
    while not rospy.is_shutdown():
        rospy.spin()
    ui.out.release()
if __name__=='__main__':
    main()