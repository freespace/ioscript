void setup() {
  Serial.begin(9600);
}

void _set_output(int pin, char hilo) {
  pinMode(pin, OUTPUT);
  digitalWrite(pin, hilo);
}

void loop() {
  if (Serial.available()) {
    int c = Serial.read();
    Serial.write(c);

    if (c == 'o') {
      _set_output(Serial.parseInt(), LOW);
    }

    if (c == 'O') {
      _set_output(Serial.parseInt(), HIGH);
    }

    if (c == 'd') {
      delay(Serial.parseInt());
    }

    if (c == 'r') {
      int pin = Serial.parseInt();
      pinMode(pin, INPUT);
      Serial.write('0'+digitalRead(pin));
    }

    Serial.write('.');
  }
}
