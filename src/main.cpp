#include <Arduino.h>
#include "yboard.h"
#include <cmath>

  float x_value;  //Declare variables like these at the top of your file (before setup()) so you can use them to store values.
  float y_value;  //
  float z_value;  //
  bool button_1;  // Declare variables like these at the top of your file (before setup()) so you can use them to store values.
  bool switch_1;  //
  int NUM_LEDS(35);
  int segment_length(3);

// Function to map angle to LED index
int angleToLED(float x, float y) {
    // Compute angle in radians (-π to π)
    float angle = atan2(y, x);

    // Convert to degrees (0 to 360)
    float degrees = angle * 180.0 / M_PI;
    if (degrees < 0) degrees += 360.0;

    // Map degrees to LED index
    int ledIndex = static_cast<int>(degrees / (360.0 / NUM_LEDS));
    return ledIndex;
}


void setup() {
  Serial.begin(9600);
  Yboard.setup();
}

void loop() {
  // For a full list of functions available on the Y-board, 
  // see the header file at .pio/libdeps/esp32/Y-Board v4/include/yboard.h from lines 39-330.
  
  /*
  ***** INITIAL WORK *****
  Get the device to change color with accelerometer data (in the x-direction)

  */
  if (Yboard.accelerometer_available()) {
    accelerometer_data accel_data = Yboard.get_accelerometer();
    x_value = accel_data.x;
    y_value = accel_data.y;
    z_value = accel_data.z;
  }
  Yboard.set_led_brightness(64);
  Yboard.set_all_leds_color(0,0,0);
  int index = angleToLED(x_value, y_value);
  for (int i=index; i < segment_length+index; i++) {
    Yboard.set_led_color(i, 255, 255, 0);
  }


  // ========LEDS========

  // Yboard.set_led_brightness(128);       // Set the brightness of all LEDs to 50% (128 out of 255)
  // Yboard.set_all_leds_color(0, 255, 0); // Set all LEDs to green
  // Yboard.set_led_color(1, 255, 0, 0);   // Set the first LED to red

  // ====================


  // ========BUTTONS AND SWITCHES========

  // Use these commands to get values from the buttons and switches.
  // button_1 = Yboard.get_button(1);  
  // switch_1 = Yboard.get_switch(1);
  // Then use those values however you need them
  // ====================================
  

  // ========DISPLAY========
  Yboard.display.clearDisplay(); // Clear the display
  Yboard.display.setTextSize(1); // Set text size to 1 (smallest)
  Yboard.display.setTextColor(SSD1306_WHITE); // Set text color to white
  Yboard.display.setCursor(0, 0); // Set cursor to top-left corner
  Yboard.display.printf("x:%i", static_cast<int>(x_value)); // Print text to the display
  Yboard.display.setCursor(50, 0);
  Yboard.display.printf("y:%i", static_cast<int>(y_value));

  // You can also draw shapes on the display. Here are some examples:
  Yboard.display.drawLine(0, 10, 127, 10, SSD1306_WHITE); // Draw a horizontal line across the display
  Yboard.display.drawRect(10, 15, 50, 30, SSD1306_WHITE); // Draw a rectangle
  Yboard.display.fillRect(70, 15, 50, 30, SSD1306_WHITE); // Draw a filled rectangle
  Yboard.display.drawCircle(30, 50, 10, SSD1306_WHITE); // Draw a circle
  Yboard.display.fillCircle(90, 50, 10, SSD1306_WHITE); // Draw a filled circle
  Yboard.display.drawTriangle(110, 40, 120, 60, 100, 60, SSD1306_WHITE); // Draw a triangle
  Yboard.display.fillTriangle(50, 40, 60, 60, 40, 60, SSD1306_WHITE); // Draw a filled triangle

  //ANY time you make changes to the display, they won't be shown until you call this function:
  Yboard.display.display(); // Update the display to show the changes
  //(Including if you clear the display)
  // =======================

  // ========ACCELEROMETER========
  // Here's an example of how to get angle data from the accelerometer. The Values the accelerometer gives are between 0 and 999.

  // Use a block like this to get data from the accelerometer using the variables you declared. The if() makes sure you're only getting data when it's available.
  
  // if (Yboard.accelerometer_available()) {
  //   accelerometer_data accel_data = Yboard.get_accelerometer();
  //   x_value = accel_data.x;
  //   y_value = accel_data.y;
  //   z_value = accel_data.z;
  // }
  
  // Then you can use the x_value, y_value, and z_value variables to do whatever you want with the accelerometer data.
  // ============================
}