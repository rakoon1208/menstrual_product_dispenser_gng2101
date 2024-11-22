#include <Servo.h>

Servo myservo; // create servo object to control a servo
int buttonPin = 2; // the number of the pushbutton pin
int buttonState = 0; // variable for reading the pushbutton status
int buttonPressed = 0; // flag for checking if the button was pressed
int count = 0;

void setup() {
  myservo.attach(9); // attaches the servo on pin 9 to the servo object
  pinMode(buttonPin, INPUT_PULLUP); // initialize the pushbutton pin as an input
  Serial.begin(9600);
  Serial.print(count);
}

void loop() {
  buttonState = digitalRead(buttonPin); // read the state of the pushbutton
  if (buttonState == HIGH) { // check if button was pressed and released
    myservo.write(180); // set servo position to 180 degrees
    delay(3000); // wait
    myservo.write(0); // set servo position back to 0 degrees
    count = count + 1;
    Serial.print(count);
  }
  if (buttonState == LOW) {
    myservo.write(0);
  }
}
