#! /usr/bin/env python

import rospy
from topic_conn_test_msg_custom.msg import person

def get_msg_cb(p):
    rospy.loginfo("Get message, Name:%s Age:%d Height:%.2f",
                  p.name,p.age,p.height)

if __name__ == "__main__":
    rospy.init_node("listener_person_p")
    subscribe = rospy.Subscriber("chat_test",person,get_msg_cb,queue_size=10)
    rospy.spin()