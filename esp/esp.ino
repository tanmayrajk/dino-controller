const int fBtn = 25;
const int sBtn = 33;
bool lastfBtnState = LOW;
bool lastsBtnState = LOW;

void setup() {
  Serial.begin(115200);
  pinMode(fBtn, INPUT_PULLDOWN);
  pinMode(sBtn, INPUT_PULLDOWN);
}

void loop() {
  const bool currentfBtnState = debouncedState(fBtn, lastfBtnState, 10);
  const bool currentsBtnState = debouncedState(sBtn, lastsBtnState, 10);

  if (currentfBtnState == HIGH && lastfBtnState == LOW) {
    Serial.println("A1");
  } else if (currentfBtnState == LOW && lastfBtnState == HIGH) {
    Serial.println("A0");
  }

  if (currentsBtnState == HIGH && lastsBtnState == LOW) {
    Serial.println("B1");
  } else if (currentsBtnState == LOW && lastsBtnState == HIGH) {
    Serial.println("B0");
  }

  lastfBtnState = currentfBtnState;
  lastsBtnState = currentsBtnState;
}

bool debouncedState(int pin, bool previousState, int time) {
  bool currentState = digitalRead(pin);
  if (currentState != previousState) {
    delay(time);
    currentState = digitalRead(pin);
  }
  return currentState;
}