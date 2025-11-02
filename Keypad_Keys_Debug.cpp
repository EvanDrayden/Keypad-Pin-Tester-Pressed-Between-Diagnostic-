const int pins[] = {2, 3, 4, 5, 6, 7, 8, 9};  // All keypad pins connected to D2–D9
const int numPins = sizeof(pins) / sizeof(pins[0]);
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < numPins; i++) {
    pinMode(pins[i], INPUT_PULLUP);
  }
}

void loop() {
  if ((millis() - lastDebounceTime) > debounceDelay) {
    for (int i = 0; i < numPins; i++) {
      pinMode(pins[i], OUTPUT);
      digitalWrite(pins[i], LOW);
      
      delayMicroseconds(10); // Allow pins to settle
      
      for (int j = 0; j < numPins; j++) {
        if (i != j && digitalRead(pins[j]) == LOW) {
          Serial.print("Pressed between ");
          Serial.print(pins[i]);
          Serial.print(" & ");
          Serial.println(pins[j]);
          lastDebounceTime = millis();
        }
      }
      
      pinMode(pins[i], INPUT_PULLUP);
      delayMicroseconds(10); // Allow pins to settle
    }
  }
}