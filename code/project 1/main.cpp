#include <Arduino.h>
// Definirea pinilor
const int ledRGB_R = 6;
const int ledRGB_G = 5;
const int ledRGB_B = 4;
const int led1 = 10;
const int led2 = 9;
const int led3 = 8;
const int led4 = 7;
const int btnStart = 3;
const int btnStop = 2;

bool charging = false;
unsigned long previousMillis = 0;
int currentStep = 0;
bool stopPressed = false;

// Prototipurile functiilor
void startCharging();
void stopCharging();
void updateChargingProgress();
void finishCharging();
void resetProgress();
void blinkLed(int ledPin);
void blinkAllLeds(int times);

void setup() {
  pinMode(ledRGB_R, OUTPUT);
  pinMode(ledRGB_G, OUTPUT);
  pinMode(ledRGB_B, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(btnStart, INPUT_PULLUP);
  pinMode(btnStop, INPUT_PULLUP);

  // Initial, statia este libera (LED-ul verde aprins)
  digitalWrite(ledRGB_R, LOW);
  digitalWrite(ledRGB_G, HIGH);
  digitalWrite(ledRGB_B, LOW);

  // Toate LED-urile de progres sunt stinse
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
}

void loop() {
  if (!charging) {
    // Butonul de start initiaza incarcarea
    if (digitalRead(btnStart) == LOW) {
      startCharging();
    }
  } else {
    // Daca suntem in procesul de incarcare, verificam progresul
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= 3000) {
      previousMillis = currentMillis;
      updateChargingProgress();
    }

    // Verificam daca butonul de stop este apasat lung doar in timpul incarcarii
    if (digitalRead(btnStop) == LOW) {
      unsigned long stopPressTime = millis();
      while (digitalRead(btnStop) == LOW) {
        if (millis() - stopPressTime >= 1000) {
          stopCharging();
          break;
        }
      }
    }
  }
}

void startCharging() {
  // Schimbam starea statiei la ocupat (LED-ul rosu aprins)
  charging = true;
  currentStep = 0;
  digitalWrite(ledRGB_R, HIGH);
  digitalWrite(ledRGB_G, LOW);
}

void stopCharging() {
  charging = false;
  // Semnalizam oprirea prin clipirea LED-urilor de progres
  blinkAllLeds(3);
  // Resetam statia la libera (LED-ul verde aprins)
  digitalWrite(ledRGB_R, LOW);
  digitalWrite(ledRGB_G, HIGH);
  resetProgress();
}

void updateChargingProgress() {
  switch (currentStep) {
    case 0:
      // LED 1 clipeste
      blinkLed(led1);
      break;
    case 1:
      digitalWrite(led1, HIGH);
      blinkLed(led2);
      break;
    case 2:
      digitalWrite(led2, HIGH);
      blinkLed(led3);
      break;
    case 3:
      digitalWrite(led3, HIGH);
      blinkLed(led4);
      break;
    case 4:
      digitalWrite(led4, HIGH);
      finishCharging();
      break;
  }
  currentStep++;
}

void finishCharging() {
  // Clipim toate LED-urile de 3 ori pentru a semnala finalizarea
  blinkAllLeds(3);
  // Resetam statia la libera
  charging = false;
  digitalWrite(ledRGB_R, LOW);
  digitalWrite(ledRGB_G, HIGH);
  resetProgress();
}

void resetProgress() {
  // Oprirea LED-urilor de progres
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
}

void blinkLed(int ledPin) {
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(500);
}

void blinkAllLeds(int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    delay(500);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    delay(500);
  }
}
