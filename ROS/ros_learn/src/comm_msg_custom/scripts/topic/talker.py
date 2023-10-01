#! /usr/bin/env python

import rospy
from comm_msg_custom.msg import person

if __name__ == "__main__":
    rospy.init_node("talker_person_p")
    pub = rospy.Publisher("chat_test",person,queue_size=10)
    p = person()
    p.name = "catcolia"
    p.age = 500
    p.height = 1.80

    r = rospy.Rate(1)
    while not rospy.is_shutdown():
        pub.publish(p)
        p.age += 1
        r.sleep()
        rospy.loginfo("Send message, Name:%s Age:%d Height:%.2f",p.name,p.age,p.height)
