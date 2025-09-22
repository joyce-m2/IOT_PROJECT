# Human-Following Autonomous Robot using Arduino

This project is a human-following autonomous robot created by **Joyce M (1RVU22CSE072)** and **Prachi G (1RVU22CSE115)** as part of a summer internship at **RV University, Bengaluru**. The robot demonstrates the application of IoT and robotics in human interaction.

## About The Project

The Human-Tracking Autonomous Robot uses an **Arduino Uno** to detect and follow objects autonomously. It integrates **infrared (IR) sensors** and **ultrasonic modules** to perceive its environment and respond accordingly. A key feature is the **OLED display** that shows a dynamic "robot eye," which changes based on object detection, adding a visually appealing and interactive element.

## Objectives

- Detect and follow objects in real-time using sensors.
- Utilize an Arduino-based control system to process inputs and control movement.
- Incorporate an OLED display to enhance the robot's interactive features.
- Ensure smooth movement and real-time processing through optimized code.

## Built With

- **Arduino Uno R3**
- **L293D Motor Driver Shield**
- **Infrared (IR) Sensors**
- **Ultrasonic Module HC-SR04**
- **Micro Servo Motor**
- **DC Gear Motors**
- **NodeMCU ESP32** (for OLED display)
- **OLED Display**

## Implementation

The robot's core functionality is managed by the **Arduino Uno**, which processes data from the **IR** and **ultrasonic sensors** to control movement via the **motor driver**. The **OLED display** is controlled separately by a **NodeMCU ESP32** programmed with **MicroPython**. This setup allows the Arduino to focus on movement and object tracking while the NodeMCU handles the visual feedback, displaying a "robot eye" that changes based on sensor input.

## Results

The robot successfully detects and follows objects with precision. The sensors work together to allow for smooth tracking, and the **OLED display** provides interactive visual feedback by displaying robot eyes that change based on movement detection, fulfilling the project's main objectives.

## Video

You can watch a demonstration of the project here:  
[Project Demonstration Video](https://drive.google.com/file/d/1XpD5aDzkUWGJn0SQ0QOIm4ouiknnYT8v/view?usp=share_link)