#include <Arduino.h>

// configuratia pinilor pentru led rgb si butoane
const int ledRGB_R = 6;
const int ledRGB_G = 5;
const int ledRGB_B = 4;
const int btnStartStop = 3;
const int btnLevel = 2;

// variabile globale
bool inGame = false;
bool awaitingInput = false;
int nrCuvinte = 0;
unsigned long startMillis = 0;
const long gameDuration = 30000; // durata totala a jocului in milisecunde
long currentInterval = 5000;     // interval implicit pentru dificultate
int difficultyLevel = 0;         // 0: easy, 1: medium, 2: hard
unsigned long lastDebounceTimeStartStop = 0; // debounce pentru butonul start/stop
unsigned long lastDebounceTimeLevel = 0;     // debounce pentru butonul de dificultate
const unsigned long debounceDelay = 200;

// dictionar de cuvinte in romana
const char* dictionar[] = {
    "mar", "banana", "cirese", "pruna", "zmeura", "strugure", "morcov",
    "cartof", "patrunjel", "ardei", "castravete", "rosie", "dovleac",
    "portocala", "pepene", "ciuperca", "lamaie", "piersica", "caisa",
    "gutui", "usturoi", "ceapa", "praz", "telina", "pastarnac", "cires"
};
const int dictSize = sizeof(dictionar) / sizeof(dictionar[0]);
String currentWord;

// temporizari pentru blink si feedback
unsigned long blinkStartMillis = 0;
unsigned long feedbackStartMillis = 0;
int blinkCount = 0;
bool ledOn = true;

// prototipuri de functii
void setLEDColor(bool red, bool green, bool blue);
void blinkLED(int times);
void startGame();
void stopGame();
void changeDifficulty();
void displayWord();
void checkInput();
void startStopISR();
void difficultyISR();

void setup() {
    pinMode(ledRGB_R, OUTPUT);
    pinMode(ledRGB_G, OUTPUT);
    pinMode(ledRGB_B, OUTPUT);
    pinMode(btnStartStop, INPUT_PULLUP);
    pinMode(btnLevel, INPUT_PULLUP);

    attachInterrupt(digitalPinToInterrupt(btnStartStop), startStopISR, FALLING);
    attachInterrupt(digitalPinToInterrupt(btnLevel), difficultyISR, FALLING);

    setLEDColor(true, true, true);

    Serial.begin(9600);
    randomSeed(analogRead(0));

    Serial.println("selectati dificultatea si apasati start pentru a incepe.");
}

void loop() {
    unsigned long currentMillis = millis();

    if (inGame) {
        if (currentMillis - startMillis >= gameDuration) {
            stopGame();
        } else {
            if (awaitingInput && Serial.available() > 0) {
                checkInput();
            }
        }
    }

    blinkLED(3);
}

void setLEDColor(bool red, bool green, bool blue) {
    digitalWrite(ledRGB_R, red ? HIGH : LOW);
    digitalWrite(ledRGB_G, green ? HIGH : LOW);
    digitalWrite(ledRGB_B, blue ? HIGH : LOW);
}

void blinkLED(int times) {
    unsigned long currentMillis = millis();
    if (blinkCount < times * 2) {
        if (currentMillis - blinkStartMillis >= 500) {
            blinkStartMillis = currentMillis;
            ledOn = !ledOn;
            setLEDColor(ledOn, ledOn, ledOn);
            blinkCount++;
        }
    } else if (blinkCount >= times * 2) {
        setLEDColor(false, false, false);
        blinkCount = 0;
    }
}

void startGame() {
    inGame = true;
    awaitingInput = true;
    nrCuvinte = 0;
    startMillis = millis();
    blinkCount = 0;

    Serial.println("jocul a inceput! introduceti cuvintele afisate:");
    displayWord();
}

void stopGame() {
    inGame = false;
    awaitingInput = false;
    setLEDColor(true, true, true);
    Serial.print("jocul s-a terminat. numar cuvinte corecte: ");
    Serial.println(nrCuvinte);
    Serial.println("selectati dificultatea si apasati start pentru a incepe.");
}

void changeDifficulty() {
    difficultyLevel = (difficultyLevel + 1) % 3;
    switch (difficultyLevel) {
        case 0:
            currentInterval = 7000;
            Serial.println("mod easy activat!");
            break;
        case 1:
            currentInterval = 3000;
            Serial.println("mod medium activat!");
            break;
        case 2:
            currentInterval = 1000;
            Serial.println("mod hard activat!");
            break;
    }
}

void displayWord() {
    int randIndex = random(0, dictSize);
    currentWord = String(dictionar[randIndex]);
    Serial.print("introduceti cuvantul: ");
    Serial.println(currentWord);
    awaitingInput = true;
}

void checkInput() {
    String input = Serial.readStringUntil('\n');
    input.trim();
    
    if (input.length() == 0) {
        Serial.println("input gol detectat - astept input valid.");
        return;
    }

    if (input.equals(currentWord)) {
        nrCuvinte++;
        setLEDColor(false, true, false);
        Serial.println("corect!");
    } else {
        setLEDColor(true, false, false);
        Serial.println("gresit!");
    }
    
    setLEDColor(false, false, false);
    displayWord();
}

void startStopISR() {
    unsigned long currentMillis = millis();
    if (currentMillis - lastDebounceTimeStartStop > debounceDelay) {
        if (!inGame) {
            startGame();
        } else {
            stopGame();
        }
        lastDebounceTimeStartStop = currentMillis;
    }
}

void difficultyISR() {
    unsigned long currentMillis = millis();
    if (currentMillis - lastDebounceTimeLevel > debounceDelay) {
        if (!inGame) {
            changeDifficulty();
        }
        lastDebounceTimeLevel = currentMillis;
    }
}
