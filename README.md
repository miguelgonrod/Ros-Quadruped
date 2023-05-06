# Ros-Quadruped

## Table of contents
* [Description](#description)
* [Technologies](#technologies)
* [Setup](#setup)
* [Licence](#licence)

## Description
In this repository you will find my files to control my own quadruped robot using ROS, this is the rosserial branch. This project was made by me using ROS Noetic as my final project to Junior I in the branch RAS Javeriana.

## Technologies
* ROS: noetic
* Python: 3.8.10
* Arduino: 1.8.19
* Rosserial

## Setup
To run this project, you need to install these dependencies:
```
$ sudo apt install ros-noetic-desktop-full
$ sudo apt install ros-noetic-rosserial-arduino ros-noetic-rosserial
```

Then you need to upload the ino file located in arduino folder.

Now you need to clone this repo in your workspace and launch the node:
```
$ git clone https://github.com/miguelgonrod/Ros-Quadruped
$ catkin_make
$ chmod u+x /scripts/mov.py
$ rosrun rosserial_python serial_node.py /dev/ttyUSB0
$ rosrun ardu_arania mov.py
```

## Licence
Ros-Quadruped is available under the BSD-3-Clause license. See the LICENSE file for more details.
