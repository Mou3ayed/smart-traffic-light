// Pin setup
const int redPin = 12;
const int yellowPin = LED_BUILTIN;
const int greenPin = 11;
const int buttonPin = 7;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); // Button active LOW
}

void loop() {
  // --- RED ---
  digitalWrite(redPin, HIGH);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, LOW);
  delay(4000); // Red on for 4 sec

  // --- GREEN ---
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, HIGH);
  
  int greenTime = 0;
  while (greenTime < 4000) {
    delay(100); // check every 100 ms
    greenTime += 100;

    // If pedestrian button is pressed
    if (digitalRead(buttonPin) == LOW) {
      break; // exit early to switch lights
    }
  }
  digitalWrite(greenPin, LOW);

  // --- YELLOW ---
  digitalWrite(yellowPin, HIGH);
  delay(2000);
  digitalWrite(yellowPin, LOW);
}
