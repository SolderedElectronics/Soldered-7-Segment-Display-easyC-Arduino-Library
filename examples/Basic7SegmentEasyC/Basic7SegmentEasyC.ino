/**
 **************************************************
 *
 * @file        Basic7SegmentEasyC.ino
 * @brief       Example how to use 7 segment display with easyC.
 *              For this example, you need Dasduino, a 7-segment display with easyC, and easyC cable.
 *              Connect the 7-segment display to Dasduino with easyC and upload this code.
 *              You will see numbers and letters displayed on the 7-segment display.
 *
 * @link        solde.red/333190, solde.red/333206, solde.red/333207
 * 
 * @authors     Karlo Leksic for soldered.com
 ***************************************************/

// Include Soldered library
#include "7-Segment-Display-easyC-SOLDERED.h"

// Create 7-segment display object
Display7EasyC display;

void setup()
{
    // Initialize 7-segment display
    display.begin();
    // Set brightness to display
    display.setBrightenss(128);
}

void loop()
{
    // Turn on the decimal point when printing numbers
    display.setDP();
    // Print all 16 predefined characters with a decimal point
    // Pre-defined characters are numbers from 0 to 9 and letters from A to F in this order
    // You just have to put the index of the wanted number or letter in setDigit function
    // For numbers, indexes are identical to the numbers we display
    for (int i = 0; i < 16; ++i)
    {
        // Set each digit on the display
        display.setDigit(i);
        // A little delay just to see changes
        delay(500);
    }

    // Clear the decimal point when printing the next numbers
    display.clearDP();
    for (int i = 0; i < 16; ++i)
    {
        // Set each digit on the display
        display.setDigit(i);
        // A little delay just to see changes
        delay(500);
    }

    // Create 1 custom character
    // To create a custom character you have to put 1 byte which represents your character
    // MSB represents segment A while LSB represents DP
    //     A
    //  F     B
    //     G
    //  E     C
    //     D    DP
    // If you want to turn on the segment, just put 1 in a certain place in the byte
    // For example, we want to display 3 parallel lines. Those are 3 segments: A, G, and D so we need to send 10010010
    // to turn wanted segments on. It is 146 in decimal, so we put this number in the function.
    display.customChar(146);
    delay(1000);

    // Blink with the display 2 times with all segments
    display.clear();
    delay(200);
    display.allOn();
    delay(200);
    display.clear();
    delay(200);
    display.allOn();
    delay(200);
    display.clear();
    delay(200);
}
