<h1 align="center" style="font-size:20">
Introduction to Robotics
</h1>

<p align="center">
Everything related to the course.
</p>

<p align="center">
  :microscope: <a href="#about">About</a>&#160;
  :pencil: <a href="#content">Content</a>&#160;
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
 
  
<img src="https://github.com/calinfrunzeanu/Introduction-to-Robotics/blob/main/folder/project%201/images/project%201%20(1).jpg" align="right" alt="Diagram" width="400">

#### Descriere

În această temă trebuie să simulați o stație de încărcare pentru un vehicul electric, folosind mai multe LED-uri și butoane. În cadrul acestui task trebuie să țineți cont de stările butonului și să folosiți debouncing, dar și să coordonați toate componentele ca într-un scenariu din viața reală.

</br>
</br>
</br>

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

[Virtual Simulation](https://wokwi.com/projects/413755024948932609)
</br>

[Code](https://github.com/calinfrunzeanu/Introduction-to-Robotics/blob/main/folder/project%201/code/PROJECT%201/src/main.cpp)
</br>

[Video of the physical setup](https://imgur.com/VyJZZNH)
</br>

#### Photo Gallery

<div align="center" style="display: grid; grid-template-columns: repeat(auto-fit, minmax(150px, 1fr)); gap: 10px; max-width: 450px;">
  <img src="https://github.com/calinfrunzeanu/Introduction-to-Robotics/blob/main/folder/project%201/images/project%201%20(2).jpg" alt="Image 1" width="250" height="250" style="object-fit: cover;">
  <img src="https://github.com/calinfrunzeanu/Introduction-to-Robotics/blob/main/folder/project%201/images/project%201%20(3).jpg" alt="Image 2" width="250" height="250" style="object-fit: cover;">
  <img src="https://github.com/calinfrunzeanu/Introduction-to-Robotics/blob/main/folder/project%201/images/project%201%20(4).jpg" alt="Image 3" width="250" height="250" style="object-fit: cover;">
  <img src="https://github.com/calinfrunzeanu/Introduction-to-Robotics/blob/main/folder/project%201/images/project%201%20(5).jpg" alt="Image 4" width="250" height="250" style="object-fit: cover;">
  <img src="https://github.com/calinfrunzeanu/Introduction-to-Robotics/blob/main/folder/project%201/images/project%201%20(6).jpg" alt="Image 5" width="250" height="250" style="object-fit: cover;">
  <img src="https://github.com/calinfrunzeanu/Introduction-to-Robotics/blob/main/folder/project%201/images/project%201%20(7).jpg" alt="Image 6" width="250" height="250" style="object-fit: cover;">
</div>

</br>
</br>
</details>



### PROJECT 2: ⁠TypeRacer Game
<details>
<summary>TASK</summary> 
 
  
<img src="https://github.com/calinfrunzeanu/Introduction-to-Robotics/blob/main/folder/project%202/images/project%202%20(1).jpg" align="right" alt="Diagram" width="400">

#### Description

In this theme you will create a game similar to TypeRacer.

</br>

#### Components Used

- Arduino UNO (ATmega328P microcontroller)
- 1x RGB LED (to signal if the correct word is misspelled or not)
- 2x Buttons (for round start/stop and difficulty selection)
- 5x Resistors (3x 220/330 ohm, 2x 1000 ohm)
- Breadboard
- Connecting threads

</br>

#### Technical Task

RGB LED - Status indicator:

In the sleep state, the LED will be white.
When the start button is pressed, the LED will flash for 3 seconds, indicating a countdown until the start of the round.
During a round: The LED will be green if the text entered is correct and will turn red if there is an error.
(1p) Start/Stop button:

Sleep Mode: If the game is paused, pressing the button initiates a new round after a 3-second countdown.
During a round: If the round is active, pressing the button will stop it immediately.
(1p) Difficulty button:

The difficulty button controls the speed at which words appear and can only be used in idle mode.
With each press, the difficulty changes by cycling between: (Easy, Medium, Hard).
When changing the difficulty, a message is sent via serial: "Easy/Medium/Hard mode on!".
For handling button presses, use debouncing and interrupts. Timers will be used to set the frequency of occurrence of words. A useful site, which also includes a video on using interrupts and timers in Arduino, is available here.
(3p) Word generation:

A word dictionary will be created.
During a round, the words will be displayed in the terminal in a random order.
If the current word was spelled correctly, a new word will be displayed immediately. If not, a new word will appear after the time interval set by the difficulty.
To generate random numbers, you must use the random() function.
(1p) Other observations:

The allotted time for a round is 30 seconds.
At the end of each round, the terminal will display how many words were spelled correctly.
</br>
</br>
</br>

</details>

<details>
<summary>IMPLEMENTATION</summary> 

</br>

[Virtual Simulation](https://wokwi.com/projects/413755217734885377)
</br>

[Code](https://github.com/calinfrunzeanu/Introduction-to-Robotics/blob/main/folder/project%202/code/PROJECT%202/src/main.cpp)
</br>

[Video of the physical setup](https://imgur.com/gallery/introduction-to-robotics-project-2-video-aTbcrqy)
</br>

#### Photo Gallery

<div align="center" style="display: grid; grid-template-columns: repeat(auto-fit, minmax(150px, 1fr)); gap: 10px; max-width: 450px;">
  <img src="https://github.com/calinfrunzeanu/Introduction-to-Robotics/blob/main/folder/project%202/images/project%202%20(2).jpg" alt="Image 1" width="250" height="250" style="object-fit: cover;">
  <img src="https://github.com/calinfrunzeanu/Introduction-to-Robotics/blob/main/folder/project%202/images/project%202%20(3).jpg" alt="Image 2" width="250" height="250" style="object-fit: cover;">
  <img src="https://github.com/calinfrunzeanu/Introduction-to-Robotics/blob/main/folder/project%202/images/project%202%20(4).jpg" alt="Image 3" width="250" height="250" style="object-fit: cover;">
  <img src="https://github.com/calinfrunzeanu/Introduction-to-Robotics/blob/main/folder/project%202/images/project%202%20(5).jpg" alt="Image 4" width="250" height="250" style="object-fit: cover;">
  <img src="https://github.com/calinfrunzeanu/Introduction-to-Robotics/blob/main/folder/project%202/images/project%202%20(6).jpg" alt="Image 5" width="250" height="250" style="object-fit: cover;">
  <img src="https://github.com/calinfrunzeanu/Introduction-to-Robotics/blob/main/folder/project%202/images/project%202%20(7).jpg" alt="Image 6" width="250" height="250" style="object-fit: cover;">
</div>

</br>
</br>
</details>

### PROJECT 3: ⁠TypeRacer Game
<details>
<summary>TASK</summary> 
 
  
<img src="https://github.com/calinfrunzeanu/Introduction-to-Robotics/blob/main/folder/project%203/images/project%203%20(1).png" align="right" alt="Diagram" width="400">

#### Description

In this assignment, each team will create a two-player competitive reflex game where both participants will compete for the highest score, testing their reaction speed. The project will be carried out in teams of two people.

Each player will have their own buttons and LEDs, and the game will take place in several rounds. The goal of each player is to press the button that corresponds to the color displayed on their team's RGB LED as quickly as possible. Each player's score will be displayed on an LCD screen and will update throughout the game. At the end of the game, the player with the highest score is declared the winner.

</br>

#### Components Used

6x LEDs (2 groups of 3 LEDs each, within a group we must have different colors)
2x RGB LEDs (1 for each player)
6x buttons (3 for each player)
1x LCD
1x servo motor
2x Breadboard
Connecting threads
2x Arduino Uno

</br>

#### Technical Task

Initialization
The game starts with a welcome message displayed on the LCD. Pressing a button triggers the start of the game.

To start the game, the start button can be implemented in a flexible way, leaving it up to the students to choose one of the following options:

- in this variant, the game starts when you press any button.
A specific button starts the game* - a specific button, clearly marked on the breadboard, can be designated to start the game.
A 7th dedicated button* – an additional button dedicated solely to starting the game can be added.
Conduct of Rounds
Each player has three buttons, each associated with a different color LED and a 4th RGB LED.
In each round, each player is the active one.
The active player's RGB LED lights up in a color corresponding to one of their buttons. The player must press the button that corresponds to the color of the RGB LED as quickly as possible to get points. The faster he reacts, the more points he gets.
At the end of a round the LCD displays the updated score of both players.
Throughout the game, the LCD display will show the score of each player
Timing and Completion of the Game
The servo rotates throughout the game, indicating progress. One full rotation of the servo marks the end of the game (you decide how fast it moves).
At the end, the LCD displays the winner's name and final score for a few seconds, then returns to the home screen with the welcome message.
3.4 Technical details
(2.5p) SPI: This theme involves a lot of connections. So many that a single arduino uno does not give us enough GPIO pins. That's why for this theme you need 2 arduino unos that will communicate using SPI. The master arduino will be the one responsible for controlling the LCD, the servo motor, and it will be the one that keeps the state of the game in memory (eg the score of each player, the led that needs to be lit now, etc.). The slave arduino will control the buttons and leds by receiving messages from the master arduino to know which led to light and sending back messages about the button being pressed.

(2p) Buttons:

To start the game the start button can be implemented in various ways:
Any button starts the game
A specific button starts the game (it should be clear on the breadboard which button is the one that starts the game)• A 7th dedicated button can be put to start the game
While the game is in progress the buttons should only be able to be used to control the game and not reset progress
Only the player's buttons in that round must be able to control the game
Even with 2 arduino boards we don't have enough pins for all components. That's why we can
multiplex buttons using resistors (www.youtube.com/watch?v=Y23vMfynUJ0)

(1p) LEDs:

Each button has an associated LED of a different color. During the game they must be lit to see which color each button corresponds to
The rgb LED should light up in one of the 3 button colors
The rgb LED must be off if it is not the round of the player corresponding to that LED
(1p) LCD:

To control it, we can use the LiquidCrystal library
It must have a brightness and contrast set good enough for the text to be visible on the screen.
Only pins D4-7 will be used for the display data lines
During the game it must display the scores of the 2 players
(1p) Actuator:

The actuator will start from the 0 degree position and move counter-clockwise to indicate the elapsed time.
Heading to the value sent to the servo motor. Through the Servo.h library we send absolute rotation to the servomotor, not relative to the current one.
You have the freedom to decide the following elements:

The score received for a correct answer according to reaction speed
Time between rounds (you can have a little preparation time between rounds or they can be right after each other for increased difficulty)
The time of the entire game
3.5 Bonus (up to 1p)
The initial state of the game can have various elements to make it more interesting. Some examples:

Animation on LCD
LED animation
Adding a buzzer
Adding the ability for ace players to enter their names
The buzzer can be included to signal correct/wrong answers, the start and end of the game or even a theme song.

Various methods can be used to add players' names:

Buttons and joysticks
LCD to display the name being entered
Serial interface (USART)
3.6 Publishing Theme
(1p) Code must be uploaded (by both team members) to your personal github in the course repo by your lab day the week of November 18-22. Add the following to the README file:

task description/requirements
the components used
pictures of the physical setup
a link/video with the physical montage functionality
wiring diagram (Wokwi, TinkerCAD


</br>
</br>
</br>

</details>

<details>
<summary>IMPLEMENTATION</summary> 



[Code](https://github.com/calinfrunzeanu/Introduction-to-Robotics/blob/main/folder/project%202/code/PROJECT%202/src/main.cpp)
</br>

[Video of the physical setup](https://imgur.com/gallery/introduction-to-robotics-project-2-video-aTbcrqy)
</br>

#### Photo Gallery

<div align="center" style="display: grid; grid-template-columns: repeat(auto-fit, minmax(150px, 1fr)); gap: 10px; max-width: 450px;">
  <img src="https://github.com/calinfrunzeanu/Introduction-to-Robotics/blob/main/folder/project%203/images/project%203%20(2).jpg" alt="Image 1" width="250" height="250" style="object-fit: cover;">
  <img src="https://github.com/calinfrunzeanu/Introduction-to-Robotics/blob/main/folder/project%203/images/project%203%20(3).jpg" alt="Image 2" width="250" height="250" style="object-fit: cover;">
  <img src="https://github.com/calinfrunzeanu/Introduction-to-Robotics/blob/main/folder/project%203/images/project%203%20(4).jpg" alt="Image 3" width="250" height="250" style="object-fit: cover;">
  <img src="https://github.com/calinfrunzeanu/Introduction-to-Robotics/blob/main/folder/project%203/images/project%203%20(5).jpg" alt="Image 4" width="250" height="250" style="object-fit: cover;">
  <img src="https://github.com/calinfrunzeanu/Introduction-to-Robotics/blob/main/folder/project%203/images/project%203%20(6).jpg" alt="Image 5" width="250" height="250" style="object-fit: cover;">
  <img src="https://github.com/calinfrunzeanu/Introduction-to-Robotics/blob/main/folder/project%203/images/project%203%20(1).jpg" alt="Image 6" width="250" height="250" style="object-fit: cover;">
</div>

</br>
</br>
</details>
