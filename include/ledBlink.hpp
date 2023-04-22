#include <Arduino.h>

bool ioBlink = false;
unsigned long milOld;
int rndTemp = 0;

// ------------------------------------------------------------------
// Simple blinking function - Para alarmes tempo variado
// ------------------------------------------------------------------
void blinkSingle(int speed, int _pin){
    if ((milOld + speed) < millis()){
        milOld = millis();
        if(ioBlink == false){
            digitalWrite(_pin, HIGH);
            ioBlink = true;
        }
        else{
            digitalWrite(_pin, LOW);
            ioBlink = false;
        }
    }
}

// ------------------------------------------------------------------
// Simple blinking function - Para alarmes tempo variado
// ------------------------------------------------------------------
void blinkSingleAsy(int timeHigh, int timeLow, int _pin){
    if (ioBlink == false){
        if((milOld + timeHigh) < millis()){
            milOld = millis();
            digitalWrite(_pin, LOW);
            ioBlink = true;
        }
    }
    else{
        if ((milOld + timeLow) < millis()){
            milOld = millis();
            digitalWrite(_pin, HIGH);
            ioBlink = false;
        }
    }
}
// ------------------------------------------------------------------
// Simple blinking function - Para alarmes tempo variado
// ------------------------------------------------------------------
void blinkRandomSingle(int minTime, int maxTime, int _pin){
    if((milOld + rndTemp) < millis()){
        milOld = millis();
        rndTemp = random(minTime, maxTime);
        if(ioBlink == false){
            digitalWrite(_pin, HIGH);
            ioBlink = true;
        }
        else{
            digitalWrite(_pin, LOW);
            ioBlink = false;
        }
    }
}
// ------------------------------------------------------------------
// On um Led
// ------------------------------------------------------------------
void setOnSingle(int _pin){
    digitalWrite(_pin, HIGH);
}
// ------------------------------------------------------------------
// Off um Led
// ------------------------------------------------------------------
void setOffSingle(int _pin){
    digitalWrite(_pin, LOW);
}