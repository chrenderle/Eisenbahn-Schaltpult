# Schaltpult Readme

## Installation
Install Visual Studio Code or any other IDE that supports Platform IO.
[Here](https://platformio.org/install/ide?install=vscode) are the instructions for Visual Studio Code.

Open the project from the Platform IO Home which opens automatically when you start Visual Studio Code.

## Configuration
Edit the src/main.cpp file.
For every switch you connect to the arduino you need to add three lines.

### Declaration
At first the declaration of the object.
```C++
/*Declarations*/
Switch* switch1;
```
"switch1" is the name and must be used only for this switch. If you want to connect another switch name it for example "switch2".

### Initialization
Second you need to initialize the object.
```C++
/*Initializations*/
switch1 = new Switch(1, 2, 3, 4, 5, 6, RIGHT);
```
Here you give the object the information at which pins the two leds, two buttons and two relays are connected. Also you tell it in which direction to go when starting the Arduino.
```C++
Switch(rightLed, leftLed, rightRelay, leftRelay, rightButton, leftButton, defaultDirection);
```

### Check button press
At last you need to add this line in the loop function.
```C++
/*Check button press*/
switch1->CheckButtonPress();
```

## Connecting multiple switches
If you want to connect multiple switches so that if you press the right button of one switch other switches also switch in certain directions you have to configure this.
```C++
switch1->AddRight(switch2, RIGHT);
```
In this example switch2 is added to the list of connected switches for the right side of switch1.
This means if you press the right button of switch1 switch2 will be switched to the direction right.
You can also do this for the left button:
```C++
switch1->AddLeft(switch2, RIGHT)
```
or change the direction switch2 should switch when the button is pressed:
```C++
switch1->AddRight(switch2, LEFT);
```

## License
GPLv3