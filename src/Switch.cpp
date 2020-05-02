#ifndef SWITCH_CLASS_CPP
#define SWITCH_CLASS_CPP

#include "Switch.h"
void setRelay(uint8_t);

Switch::Switch(uint8_t rightLed, uint8_t leftLed, uint8_t rightRelay, uint8_t leftRelay, uint8_t rightButton, uint8_t leftButton, DIRECTION defaultDirection) : rightLed(rightLed), leftLed(leftLed), rightRelay(rightRelay), leftRelay(leftRelay), rightButton(rightButton), leftButton(leftButton), defaultDirection(defaultDirection)
{
    pinMode(rightLed, OUTPUT);
    pinMode(leftLed, OUTPUT);
    pinMode(rightRelay, OUTPUT);
    pinMode(leftRelay, OUTPUT);
    pinMode(rightButton, INPUT_PULLUP);
    pinMode(leftButton, INPUT_PULLUP);
    digitalWrite(rightRelay, LOW);
    digitalWrite(leftRelay, LOW);
    Set(defaultDirection);
}

void Switch::AddRight(Switch* _switch, DIRECTION direction)
{
    if (rightSwitchesSize < MAX_EVENT_SWITCHES)
    {
        rightSwitches[rightSwitchesSize] = _switch;
        rightSwitchesDirection[rightSwitchesSize] = direction;
        ++rightSwitchesSize;
    }
}

void Switch::AddLeft(Switch* _switch, DIRECTION direction)
{
    if (leftSwitchesSize < MAX_EVENT_SWITCHES)
    {
        leftSwitches[leftSwitchesSize] = _switch;
        leftSwitchesDirection[rightSwitchesSize] = direction;
        ++leftSwitchesSize;
    }
}

void Switch::Set(DIRECTION direction)
{
    if (direction == RIGHT)
    {
        digitalWrite(rightLed, HIGH);
        digitalWrite(leftLed, LOW);
        setRelay(rightRelay);
    }
    else
    {
        digitalWrite(rightLed, LOW);
        digitalWrite(leftLed, HIGH);
        setRelay(leftRelay);
    }
    
}

void Switch::CheckButtonPress()
{
    Serial.println("lastbuttonpress: " + String(lastButtonPress));
    Serial.println("millis + 500: " + String(millis() + 500));
    //check if in the last half second was a button press on this switch
    if (lastButtonPress < millis() + 500)
    {
        if (digitalRead(rightButton) == LOW)
        {
            Serial.println("right button press");
            //right button got pressed
            //set this switch to right
            Set(RIGHT);
            //set all switches in the array to the desired direction
            for (int i = 0; i < rightSwitchesSize; ++i)
            {
                rightSwitches[i]->Set(rightSwitchesDirection[i]);
            }
        }
        else if (digitalRead(leftButton) == LOW)
        {
            //left button got pressed
            //set this switch to left
            Set(LEFT);
            //set all switches in the array to the desired direction
            for (int i = 0; i < leftSwitchesSize; ++i)
            {
                leftSwitches[i]->Set(leftSwitchesDirection[i]);
            }
        }
        lastButtonPress = millis();
    }
}

void setRelay(uint8_t pin)
{
    digitalWrite(pin, HIGH);
    delay(1000);
    digitalWrite(pin, LOW);
}

#endif