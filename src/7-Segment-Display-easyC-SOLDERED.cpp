/**
 **************************************************
 *
 * @file        7-Segment-Display-easyC-SOLDERED.cpp
 * @brief       Functions for 7-segment display.
 *
 *
 * @copyright   GNU General Public License v3.0
 * @authors     Karlo Leksic for soldered.com
 ***************************************************/


#include "7-Segment-Display-easyC-SOLDERED.h"

/**
 * @brief                   Sensor specific native constructor.
 *
 * @param int _pin          Example parameter.
 */
Display7EasyC::Display7EasyC()
{
    native = 0;
}

/**
 * @brief                   Overloaded function for virtual in base class to initialize Display7EasyC specific.
 */
void Display7EasyC::initializeNative()
{
    pinMode(pin, INPUT);
}

/**
 * @brief                   Function to set display brightness.
 *
 * @param byte _pwmValue    Value from 0 to 255 for brightness.
 */
void Display7EasyC::setBrightenss(byte _pwmValue)
{
    brightness = _pwmValue;
    byte data[2];
    data[0] = digits[digitIndex];
    data[1] = brightness;
    sendData(data, 2);
}

/**
 * @brief                   Function to set digit on display.
 *
 * @param byte _digitIndex  Index of digit we want to display.
 *                          There are 16 indexes, from 0 to 15.
 *                          First 9 index represents numbers from 0 to 9,
 *                          and next 9 represents characters from a to f.
 */
void Display7EasyC::setDigit(byte _digitIndex)
{
    digitIndex = _digitIndex;
    byte data[2];
    if (dp == 1)
    {
        data[0] = digits[digitIndex] | (1 << 0);
    }
    else
    {
        data[0] = digits[digitIndex] & ~(1 << 0);
    }

    data[1] = brightness;
    sendData(data, 2);
}

/**
 * @brief                   Function to set decimal point.
 *                          You need to call this function before you draw on the display to see the decimal point.
 */
void Display7EasyC::setDP()
{
    dp = 1;
}

/**
 * @brief                   Function to remove decimal point.
 *                          The decimal point will be removed after calling this function and setting another digit or
 * letter on the display.
 */
void Display7EasyC::clearDP()
{
    dp = 0;
}

/**
 * @brief                   This function clears display.
 */
void Display7EasyC::clear()
{
    byte data[2];
    data[0] = 0;
    data[1] = brightness;
    sendData(data, 2);
}

/**
 * @brief                   This function turn all segments on.
 */
void Display7EasyC::allOn()
{
    byte data[2];
    data[0] = 255;
    data[1] = brightness;
    sendData(data, 2);
}

/**
 * @brief                   Function for drawing custom character.
 *
 * @param byte _char        Char in byte you want to display.
 *                          Each bit represents 1 segment.
 *                          MSB represents A segment while LSB represents DP.
 */
void Display7EasyC::customChar(byte _char)
{
    byte data[2];
    data[0] = _char;
    data[1] = brightness;
    sendData(data, 2);
}
