
// Sparkfun Pro Micro Volume Knob project
// 2020-11-13
// assembled by Hardy J Pottinger IV

// This code is inspired by: https://learn.adafruit.com/trinket-usb-volume-knob/code
// and modified using the info in this tutorial: https://www.sparkfun.com/tutorials/337
// but the biggest thanks is owed to the wonderful example code for the NicoHood HID-Project:
//   https://github.com/NicoHood/HID/blob/master/examples/Consumer/Consumer.ino

#include "HID-Project.h"

#define PIN_ENCODER_CLK 2
#define PIN_ENCODER_DT 3

void setup() {

  // set pins as input with internal pull-up resistors enabled
  pinMode(PIN_ENCODER_CLK, INPUT);
  pinMode(PIN_ENCODER_DT, INPUT);
  digitalWrite(PIN_ENCODER_CLK, HIGH);
  digitalWrite(PIN_ENCODER_DT, HIGH);

// Init the Consumer class, so we can send media key presses
  Consumer.begin();

}

void loop() {

// very simplistic volume knob code, just look for low signals on the correct pin and send the right keycode

  if (digitalRead(PIN_ENCODER_CLK) == 0) // if the CLK pin goes low
  {
    Consumer.write(MEDIA_VOLUME_DOWN);
    // simple debounce
    delay(300); 
    digitalWrite(PIN_ENCODER_CLK, HIGH);
  }

  if (digitalRead(PIN_ENCODER_DT) == 0) // if the DT pin goes low
  {

    Consumer.write(MEDIA_VOLUME_UP);
    // simple debounce
    delay(300); 
    digitalWrite(PIN_ENCODER_DT, HIGH);
  }

  // TODO: for fun, the encoder has a switch, try turning it into a mute toggle

}
