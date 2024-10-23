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

 This repo will contain all materials related to the laboratory.
 The code for each project is available in it's specific folder.

</br>

## Content

### Homework #1 : Electric vehicle charging system
 
<img src="https://github.com/Pepi100/IntroductionToRobotics/images/Screenshot 2024-10-23 205118.png" align="right"
     alt="Diagram" width="600">

#### Components Used

- 4x LEDs (to simulate the percentage of charge)
- 1x RGB LED (for free or busy status)
- 2x Buttons (for charging start and stop charging)
- 8x Resistors (6x 220/330ohm, 2x 1K)
- Breadboard
- Connecting Lines

[Wokwi Implementation](https://wokwi.com/projects/379141484912992257)

[Demo link](https://youtu.be/U9Ul7x-ILts)



</br>
</br>
</br>

#### Technical Task

The RGB LED represents the availability of the station. If the station is free, the LED will be green, and if the station is occupied, it will turn red.
The simple LEDs represent the degree of battery charge, which we will simulate through a progressive loader (L1 = 25%, L2 = 50%, L3 = 75%, L4 = 100%). The loader is charged by successively lighting up the LEDs, at a fixed interval of 3s. The LED that signifies the current percentage of charge will have a flashing state, the LEDs behind it being lit continuously, and the others turned off.
Short pressing the start button will start charging. Pressing this button while charging will not do anything.
Long pressing the stop button will forcibly stop charging and reset the station to the free state. Pressing this button while the station is free will not do anything.

<details>
  <summary> Development process</summary>

  <h4>Version 1</h4>
  <img src="https://github.com/Pepi100/IntroductionToRobotics/blob/master/%232%20-%20RGB%20Led/V1Diagram.png" align="right"
     alt="Diagram" width="500">
  <p style='color: crimson;'>1x 220&#8486; rezistor</p>
  
  
  <p>This initial version used only ore resistor for the entire circuit. It did work, however, the red LED was significantly brighter than the others. According to <a href="https://os.mbed.com/users/4180_1/notebook/rgb-leds/#:~:text=Resistor%20values%20are%20typically%20around,of%20the%20light%20wave%20increases.">this</a> article, the voltage drop of the LED tends to rise as the frequency of the light wave increases. Therefore, it is suitable to use different resistors for each color of the RGB LED.
  </p>
<!--   </br> -->
  <p>With the available choices, I've selected 2x 100&#8486; resistors for the blue and green LEDs.</p>

</br>
</br>
   <h4>Version 2</h4>
   
  <p style='color: crimson;'>Filtering signal</p>
  
  
  <p>
    This second version brings modifications to the code. The main flaw of version 1 was the flickering of the green LED when adjusting the other knobs. I`ve manually implemented a high pass filter such that values below a certain threshold would not register.
  </p>
    <p>
    LED values are now updated every 10 mills, attempting to reduce flickering and provide a smoother output.
  </p>
<!--   </br> -->
</details>



</br>
</br>

