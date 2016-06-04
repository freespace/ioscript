#define IGNORE_CHAR   ';'

// bitmap storing 0 when a pin is an input (default), 1 when it is an output.
// Implicitly assumes at most 64 pins
uint64_t _pinModeMask = 0;
typedef enum {
  PinModeInput,
  PinModeOutput,
} PinMode;

void setup() {
  Serial.begin(9600);
}

void _set_pin_mode(uint8_t pin, PinMode mode) {
  if (mode == PinModeInput) {
    if ((_pinModeMask & _BV(pin)) > 0) {
      pinMode(pin, INPUT);
      _pinModeMask &= ~_BV(pin);
    }
  }

  if (mode == PinModeOutput) {
    if ((_pinModeMask & _BV(pin)) == 0) {
      pinMode(pin, OUTPUT);
      _pinModeMask |= _BV(pin);
    }
  }
}

void _set_output(uint8_t pin, uint8_t hilo) {
  _set_pin_mode(pin, PinModeOutput);
  digitalWrite(pin, hilo);
}

uint8_t _dread_input(uint8_t pin) {
  _set_pin_mode(pin, PinModeInput);
  return digitalRead(pin);
}

void loop() {
  if (Serial.available()) {
    int c = Serial.read();
    Serial.write(c);
    bool matched = false;

    if (c == 'o') {
      _set_output(Serial.parseInt(), LOW);
      matched = true;
    }

    if (c == 'O') {
      _set_output(Serial.parseInt(), HIGH);
      matched = true;
    }

    if (c == 'd') {
      delay(Serial.parseInt());
      matched = true;
    }

    if (c == 'I') {
      uint8_t pin = Serial.parseInt(); 
      _set_pin_mode(pin, PinModeInput);
      digitalWrite(pin, HIGH);
      matched = true;
    }

    if (c == 'i') {
      uint8_t pin = Serial.parseInt(); 
      _set_pin_mode(pin, PinModeInput);
      digitalWrite(pin, LOW);
      matched = true;
    }

    if (c == 'r') {
      Serial.write('0' + _dread_input(Serial.parseInt()));
      matched = true;
    }

    if (matched) Serial.write('.');
    else if (c != IGNORE_CHAR) Serial.write('?');
  }
}
