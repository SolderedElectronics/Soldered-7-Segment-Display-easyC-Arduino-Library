/**
 **************************************************
 *
 * @file        7-Segment-Display-easyC-SOLDERED.h
 * @brief       Header file for 7-segment display.
 *
 *
 * @copyright   GNU General Public License v3.0
 * @authors     Karlo Lelsic for soldered.com
 ***************************************************/

#ifndef __DISPLAY7__
#define __DISPLAY7__

#include "Arduino.h"
#include "libs/Generic-easyC/easyC.hpp"

class Display7EasyC : public EasyC
{
  public:
    Display7EasyC();
    void setBrightenss(byte _pwmValue);
    void setDigit(byte _digitIndex);
    void setDP();
    void clearDP();
    void clear();
    void allOn();
    void customChar(byte _char);

  protected:
    void initializeNative();

  private:
    int pin;
    byte brightness = 128;
    byte digitIndex = 8;
    bool dp = 0;
    byte digits[16] = {252, 96, 218, 242, 102, 182, 190, 224, 254, 246, 238, 62, 156, 122, 158, 142};
};

#endif
