#!/usr/bin/python3

import queue
import rospy
from std_msgs.msg import UInt16

def publisher () :
    publicadorb1 = rospy.Publisher("/servob1",UInt16, queue_size=10)
    publicadorb2 = rospy.Publisher("/servob2",UInt16, queue_size=10)
    publicadorb3 = rospy.Publisher("/servob3",UInt16, queue_size=10)
    publicadorb4 = rospy.Publisher("/servob4",UInt16, queue_size=10)
    publicadorm1 = rospy.Publisher("/servom1",UInt16, queue_size=10)
    publicadorm2 = rospy.Publisher("/servom2",UInt16, queue_size=10)
    publicadorm3 = rospy.Publisher("/servom3",UInt16, queue_size=10)
    publicadorm4 = rospy.Publisher("/servom4",UInt16, queue_size=10)
    while not rospy.is_shutdown():
        try:
            msg = UInt16()
            msg.data = 125
            publicadorm1.publish(180)
            publicadorm2.publish(180)
            publicadorm3.publish(180)
            publicadorm4.publish(180)
            delay(0.5)

            publicadorm1.publish(0)
            publicadorm3.publish(0)
            publicadorb1.publish(90)
            publicadorb3.publish(90)
            publicadorm1.publish(180)


            
            
            publicadorm3.publish(180)
            delay(0.5)


            publicadorm2.publish(0)
            publicadorm4.publish(0)
            publicadorb2.publish(90)
            publicadorb4.publish(90)
            publicadorm2.publish(180)


            
            
            publicadorm4.publish(180)
            delay(0.5)

            publicadorb4.publish(180)
            publicadorb3.publish(0)
            publicadorb1.publish(160)
            publicadorb2.publish(20)
            delay(0.5)
        except rospy.ROSInterruptException:
            return

def delay (seg) :
    rospy.Rate(1/seg).sleep()
    
if __name__ == "__main__":
    rospy.init_node("movimiento")
    publisher()
        
