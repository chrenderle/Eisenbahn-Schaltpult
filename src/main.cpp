#include <Arduino.h>
#include "Switch.h"
#include "Direction.h"

/*Declarations*/
Switch* switch1;
Switch* switch2;
Switch* switch3;
Switch* switch4;
Switch* switch5;
Switch* switch6;
Switch* switch7;
Switch* switch8;
Switch* switch9;
Switch* switch10;

void setup()
{
    /*Initializations*/
    switch1 = new Switch(A0, A1, 22, 27, 13, 12, RIGHT);
    switch2 = new Switch(A2, A3, 24, 25, 11, 10, RIGHT);
    //switch1 = new Switch(A0, A1, 13, 12, 22, 23, RIGHT);
    //switch2 = new Switch(A2, A3, 11, 10, 24, 25, RIGHT);
    /*switch3 = new Switch(A4, A5, 9, 8, 26, 27, RIGHT);
    switch4 = new Switch(A6, A7, 7, 6, 28, 29, RIGHT);
    switch5 = new Switch(A8, A9, 5, 4, 30, 31, RIGHT);
    switch6 = new Switch(A10, A11, 3, 2, 32, 33, RIGHT);
    switch7 = new Switch(A12, A13, 14, 15, 34, 35, RIGHT);
    switch8 = new Switch(A14, A15, 16, 17, 36, 37, RIGHT);
    switch9 = new Switch(52, 50, 18, 19, 38, 39, RIGHT);
    switch10 = new Switch(53, 51, 20, 21, 40, 41, RIGHT);*/

    switch1->AddRight(switch2, LEFT);
    switch1->AddLeft(switch2, RIGHT);

    /*switch2->AddRight(switch6, LEFT);
    switch2->AddLeft(switch6, RIGHT);

    switch3->AddRight(switch5, LEFT);
    switch3->AddLeft(switch5, RIGHT);
    switch3->AddLeft(switch4, LEFT);

    switch7->AddRight(switch10, LEFT);
    switch7->AddLeft(switch10, RIGHT);

    switch8->AddRight(switch9, LEFT);
    switch8->AddLeft(switch9, RIGHT);*/

    
}

void loop()
{
    /*Check button press*/
    switch1->CheckButtonPress();
    switch2->CheckButtonPress();
    /*switch3->CheckButtonPress();
    switch4->CheckButtonPress();
    switch5->CheckButtonPress();
    switch6->CheckButtonPress();
    switch7->CheckButtonPress();
    switch8->CheckButtonPress();
    switch9->CheckButtonPress();
    switch10->CheckButtonPress();*/
}