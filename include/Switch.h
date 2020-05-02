#ifndef SWITCH_CLASS_H
#define SWITCH_CLASS_H

#include "Direction.h"
#include <Arduino.h>

#define MAX_EVENT_SWITCHES 2

class Switch
{
public:
    Switch(uint8_t rightLed, uint8_t leftLed, uint8_t rightRelay, uint8_t leftRelay, uint8_t rightButton, uint8_t leftButton, DIRECTION defaultDirection);
    void AddRight(Switch* _switch, DIRECTION Direction);
    void AddLeft(Switch* _switch, DIRECTION Direction);
    void Set(DIRECTION direction);
    void CheckButtonPress();
private:
    uint8_t rightLed;
    uint8_t leftLed;
    uint8_t rightRelay;
    uint8_t leftRelay;
    uint8_t rightButton;
    uint8_t leftButton;
    DIRECTION defaultDirection;
    Switch* rightSwitches[MAX_EVENT_SWITCHES];
    DIRECTION rightSwitchesDirection[MAX_EVENT_SWITCHES];
    uint8_t rightSwitchesSize = 0;
    Switch* leftSwitches[MAX_EVENT_SWITCHES];
    DIRECTION leftSwitchesDirection[MAX_EVENT_SWITCHES];
    uint8_t leftSwitchesSize = 0;

    unsigned long lastButtonPress = 0;
};

#endif