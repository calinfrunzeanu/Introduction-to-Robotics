<h1 align="center" style="font-size:20">
Introduction to Robotics Course
</h1>

<p align="center">
Everything related to the course.
</p>

<p align="center">
  :microscope: <a href="#about">About</a>&#160;
  :pencil: <a href="#content">Content</a>&#160;
  :paperclip:<a href="#resources">Others</a>
</p>

## About

#### Course Objectives:
1. Development of POC (Proof of Concept) and Final Product Development Skills
2. Encouragement of Critical Thinking and Problem Solving
3. Programming Skills Development
4. Understanding Basic Robotics Concepts
5. Understanding and Using Microcontrollers

Professor: [Dan Tudose](https://github.com/dantudose)

Laboratory tutor: [Radu Ioan Nedelcu](https://github.com/Pepi100)

</br>

## Content

### PROJECT 1: Electric vehicle charging system
<details>
<summary>TASK</summary> 
 
  
<img src="media/project 1/img/Screenshot 2024-10-23 210012.png" align="right" alt="Diagram" width="400">



#### Components Used

- 4x LEDs (to simulate the percentage of charge)
- 1x RGB LED (for free or busy status)
- 2x Buttons (for charging start and stop charging)
- 8x Resistors (6x 220/330ohm, 2x 1K)
- Breadboard
- Connecting Lines

</br>
</br>
</br>

#### Technical Task

The RGB LED represents the availability of the station. If the station is free, the LED will be green, and if the station is occupied, it will turn red.
The simple LEDs represent the degree of battery charge, which we will simulate through a progressive loader (L1 = 25%, L2 = 50%, L3 = 75%, L4 = 100%). The loader is charged by successively lighting up the LEDs, at a fixed interval of 3s. The LED that signifies the current percentage of charge will have a flashing state, the LEDs behind it being lit continuously, and the others turned off.
Short pressing the start button will start charging. Pressing this button while charging will not do anything.
Long pressing the stop button will forcibly stop charging and reset the station to the free state. Pressing this button while the station is free will not do anything.

</br>
</br>
</br>

</details>

<details>
<summary>IMPLEMENTATION</summary> 

</br>

[Virtual Simulation](https://wokwi.com/projects/412558654532609025)
</br>

[Code](https://github.com/calinfrunzeanu/Introduction-to-Robotics/blob/main/code/project%201/main.cpp)
</br>

[Video of the physical setup](https://github.com/calinfrunzeanu/Introduction-to-Robotics/blob/main/media/project%201/WhatsApp%20Video%202024-10-23%20at%2023.00.44_58cbeca5.mp4)
</br>

#### Photo Gallery

<div align="center">
  <img src="https://github.com/calinfrunzeanu/Introduction-to-Robotics/blob/main/media/project%201/img/tema%201%20img%20(1).jpg" alt="Image 1" width="300">
  <img src="https://github.com/calinfrunzeanu/Introduction-to-Robotics/blob/main/media/project%201/img/tema%201%20img%20(2).jpg" alt="Image 2" width="300">
  <img src="https://github.com/calinfrunzeanu/Introduction-to-Robotics/blob/main/media/project%201/img/tema%201%20img%20(3).jpg" alt="Image 3" width="300">
  <img src="https://github.com/calinfrunzeanu/Introduction-to-Robotics/blob/main/media/project%201/img/tema%201%20img%20(4).jpg" alt="Image 4" width="300">
  <img src="https://github.com/calinfrunzeanu/Introduction-to-Robotics/blob/main/media/project%201/img/tema%201%20img%20(5).jpg" alt="Image 5" width="300">
  <img src="https://github.com/calinfrunzeanu/Introduction-to-Robotics/blob/main/media/project%201/img/tema%201%20img%20(6).jpg" alt="Image 6" width="300">  
</div>

</br>
</br>
</details>
