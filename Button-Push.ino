int button = 2;
int led = 4;
int state = LOW;
int last = HIGH;

void setup() {
  pinMode(button, INPUT_PULLUP); 
  pinMode(led, OUTPUT);
}

void loop() {
  int reading = digitalRead(button);

  if (reading == LOW && last == HIGH) {
    delay(50); // simple debounce
    state = !state;
    digitalWrite(led, state);
  }

  last = reading;
}