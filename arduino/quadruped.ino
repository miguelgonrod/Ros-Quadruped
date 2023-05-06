#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include<WProgram.h>
#endif

#include <Servo.h>
#include <ros.h>
#include <std_msgs/UInt16.h>

ros::NodeHandle nh;

Servo servo1mano;
Servo servo1base;

Servo servo2mano;
Servo servo2base;

Servo servo3mano;
Servo servo3base;

Servo servo4mano;
Servo servo4base;

void servo_mano_1(const std_msgs::UInt16& cmd_msg){
  servo1mano.write(cmd_msg.data);
  digitalWrite(3, HIGH-digitalRead(3));
}

void servo_base_1(const std_msgs::UInt16& cmd_msg){
  servo1base.write(cmd_msg.data);
  digitalWrite(4, HIGH-digitalRead(4));
}

void servo_mano_2(const std_msgs::UInt16& cmd_msg){
  servo2mano.write(cmd_msg.data);
  digitalWrite(6, HIGH-digitalRead(6));
}

void servo_base_2(const std_msgs::UInt16& cmd_msg){
  servo2base.write(cmd_msg.data);
  digitalWrite(7, HIGH-digitalRead(7));
}

void servo_mano_3(const std_msgs::UInt16& cmd_msg){
  servo3mano.write(cmd_msg.data);
  digitalWrite(A1, HIGH-digitalRead(A1));
}

void servo_base_3(const std_msgs::UInt16& cmd_msg){
  servo3base.write(cmd_msg.data);
  digitalWrite(A2, HIGH-digitalRead(A2));
}

void servo_mano_4(const std_msgs::UInt16& cmd_msg){
  servo4mano.write(cmd_msg.data);
  digitalWrite(A4, HIGH-digitalRead(A4));
}

void servo_base_4(const std_msgs::UInt16& cmd_msg){
  servo4base.write(cmd_msg.data);
  digitalWrite(A5, HIGH-digitalRead(A5));
}

ros::Subscriber<std_msgs::UInt16> subm1("servom1", servo_mano_1);
ros::Subscriber<std_msgs::UInt16> subb1("servob1", servo_base_1);

ros::Subscriber<std_msgs::UInt16> subm2("servom2", servo_mano_2);
ros::Subscriber<std_msgs::UInt16> subb2("servob2", servo_base_2);

ros::Subscriber<std_msgs::UInt16> subm3("servom3", servo_mano_3);
ros::Subscriber<std_msgs::UInt16> subb3("servob3", servo_base_3);

ros::Subscriber<std_msgs::UInt16> subm4("servom4", servo_mano_4);
ros::Subscriber<std_msgs::UInt16> subb4("servob4", servo_base_4);

void setup(){
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  nh.initNode();
  nh.subscribe(subm1);
  nh.subscribe(subb1);

  nh.subscribe(subm2);
  nh.subscribe(subb2);

  nh.subscribe(subm3);
  nh.subscribe(subb3);

  nh.subscribe(subm4);
  nh.subscribe(subb4);
  
  servo1mano.attach(3);  
  servo1base.attach(4);

  servo2mano.attach(6);  
  servo2base.attach(7);

  servo3mano.attach(A1);  
  servo3base.attach(A2);

  servo4mano.attach(A4);  
  servo4base.attach(A5);
}

void loop(){
  nh.spinOnce();
  delay(1);
}
