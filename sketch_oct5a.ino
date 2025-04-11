// Pin definitions
const int eyeRedPin = 3;    // Red LED pin
const int eyeGreenPin = 5;  // Green LED pin
const int eyeBluePin = 6;   // Blue LED pin
const int bellyButtonPin = 4; // Button on belly
const int tailButtonPin = 2;  // Button on tail


// Variables
int bellyButtonState = 0;
int tailButtonState = 0;

void setup() {
  pinMode(eyeRedPin, OUTPUT);
  pinMode(eyeGreenPin, OUTPUT);
  pinMode(eyeBluePin, OUTPUT);
  pinMode(bellyButtonPin, INPUT_PULLUP);
  pinMode(tailButtonPin, INPUT_PULLUP);
}

void loop() {
  // Read the button states
  bellyButtonState = digitalRead(bellyButtonPin);
  tailButtonState = digitalRead(tailButtonPin);

  // Set the eye color based on button presses
  if (bellyButtonState == LOW) {
    // Belly button pressed (happy)
    setEyeColor(0, 255, 0); // Pink
  } else if (tailButtonState == LOW) {
    // Tail button pressed (angry)
    setEyeColor(255, 20, 147); // Red
  } else {
    // No buttons pressed (white)
    setEyeColor(255, 255, 255); // White
  }
}

// Function to set the RGB LED eye color
void setEyeColor(int red, int green, int blue) {
  analogWrite(eyeRedPin, red);
  analogWrite(eyeGreenPin, green);
  analogWrite(eyeBluePin, blue);
}


