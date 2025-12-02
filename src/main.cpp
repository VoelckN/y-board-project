#include <Arduino.h>
#include "yboard.h"
#include <cmath>

  float x_value;  //Declare variables like these at the top of your file (before setup()) so you can use them to store values.
  float y_value;  //
  float z_value;  //
  float max_x;
  float max_y;
  bool button_1;  // Declare variables like these at the top of your file (before setup()) so you can use them to store values.
  int NUM_LEDS(35);
  int segment_length(3);


// Function to map angle to LED index
int angleToLED(const float &x, const float &y) {
    // Compute angle in radians (-π to π)
    float angle = atan2(y, x);

    // Convert to degrees (0 to 360)
    float degrees = angle * 180.0 / M_PI;
    if (degrees < 0) degrees += 360.0;

    // Map degrees to LED index
    int ledIndex = static_cast<int>(degrees / (360.0 / NUM_LEDS));
    return ledIndex;
}


int wrap(const int & value, const int & maxValue) {
    int range = maxValue;
    return ( ((value - 1) % range) + range ) % range + 1;
}


void setup() {
  Serial.begin(9600);
  Yboard.setup();
}


void loop() {


  if (Yboard.accelerometer_available()) {
    accelerometer_data accel_data = Yboard.get_accelerometer();
    x_value = accel_data.x;
    y_value = accel_data.y;
    z_value = accel_data.z;
  }
  // Update max values
  if (std::abs(x_value) > std::abs(max_x)) {
    max_x = x_value;
  }
  if (std::abs(y_value) > std::abs(max_y)) {
    max_y = y_value;
  }

  
  Yboard.set_led_brightness(128);
  Yboard.set_all_leds_color(0,0,0);
  int index = angleToLED(x_value, y_value);
  for (int i=index; i < segment_length+index; i++) {
    Yboard.set_led_color(wrap(i, NUM_LEDS), 0, 255, 0);
  }


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
  Yboard.display.setCursor(40, 0);
  Yboard.display.printf("y:%i", static_cast<int>(y_value));
  Yboard.display.setCursor(80,0);
  Yboard.display.printf("i:%i", wrap(index, NUM_LEDS));

  Yboard.display.setCursor(0,20);
  Yboard.display.printf("max X:%i", static_cast<int>(max_x));
  Yboard.display.setCursor(0,40);
  Yboard.display.printf("max Y:%i", static_cast<int>(max_y));

  //ANY time you make changes to the display, they won't be shown until you call this function:
  Yboard.display.display(); // Update the display to show the changes
  //(Including if you clear the display)
  // =======================
}