#include <Arduino.h>


class Semaforo {
public:
  int redLed;
  int yellowLed;
  int greenLed;

  Semaforo(const int redLed, const int yellowLed, const int greenLed)
    : redLed(redLed), yellowLed(yellowLed), greenLed(greenLed) {}

  void setup() const {
    pinMode(this->redLed, OUTPUT);
    pinMode(this->yellowLed, OUTPUT);
    pinMode(this->greenLed, OUTPUT);
  }

  void turnOnGreen() {
    digitalWrite(this->greenLed, HIGH);
    digitalWrite(this->yellowLed, LOW);
    digitalWrite(this->redLed, LOW);
  }

  void turnOnYellow() {
    digitalWrite(this->greenLed, LOW);
    digitalWrite(this->yellowLed, HIGH);
    digitalWrite(this->redLed, LOW);
  }

  void turnOnRed() {
    digitalWrite(this->greenLed, LOW);
    digitalWrite(this->yellowLed, LOW);
    digitalWrite(this->redLed, HIGH);
  }

  void twinkleGreenLed () {
    for (int i = 0; i < 3; i++) {
      digitalWrite(this->greenLed, LOW);
      delay(500);
      digitalWrite(this->greenLed, HIGH);
      delay(500);
    }
  }
};

Semaforo semaforo1(13, 12, 11);
Semaforo semaforo2(10, 9, 8);
Semaforo semaforo3(7, 6, 5);
Semaforo semaforo4(4, 3, 2);

void setup() {
  semaforo1.setup();
  semaforo2.setup();
  semaforo3.setup();
  semaforo4.setup();
}

void loop() {
  semaforo1.turnOnGreen();
  semaforo2.turnOnRed();
  semaforo3.turnOnRed();
  semaforo4.turnOnRed();
  delay(4000);
  semaforo1.twinkleGreenLed();
  semaforo1.turnOnYellow();
  delay(2000);
  semaforo1.turnOnRed();

  semaforo2.turnOnGreen();
  delay(4000);
  semaforo2.twinkleGreenLed();
  semaforo2.turnOnYellow();
  delay(2000);
  semaforo2.turnOnRed();

  semaforo3.turnOnGreen();
  delay(4000);
  semaforo3.twinkleGreenLed();
  semaforo3.turnOnYellow();
  delay(2000);
  semaforo3.turnOnRed();

  semaforo4.turnOnGreen();
  delay(4000);
  semaforo4.twinkleGreenLed();
  semaforo4.turnOnYellow();
  delay(2000);
  semaforo4.turnOnRed();
}