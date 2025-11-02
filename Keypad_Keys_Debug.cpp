const int pins[] = {2, 3, 4, 5, 6, 7, 8, 9};  // All keypad pins connected to D2–D9
const int numPins = sizeof(pins) / sizeof(pins[0]);

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < numPins; i++) {
    pinMode(pins[i], INPUT_PULLUP);
  }
}

void loop() {
  for (int i = 0; i < numPins; i++) {
    pinMode(pins[i], OUTPUT);
    digitalWrite(pins[i], LOW);
    for (int j = 0; j < numPins; j++) {
      if (i != j && digitalRead(pins[j]) == LOW) {
        Serial.print("Pressed between ");
        Serial.print(pins[i]);
        Serial.print(" & ");
        Serial.println(pins[j]);
        delay(400);
      }
    }
    pinMode(pins[i], INPUT_PULLUP);
  }
}
