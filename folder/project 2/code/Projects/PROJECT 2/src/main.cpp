#include <Arduino.h>

// configuratia pinilor pentru LED RGB si butoane
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
unsigned long lastDebounceTime = 0; // timpul ultimei apasari pentru debounce
const unsigned long debounceDelay = 50; // delay pentru debounce

// dictionar de cuvinte
const char* dictionar[] = {
    "apple", "banana", "cherry", "date", "elderberry", "fig", "grape",
    "honeydew", "kiwi", "jackfruit", "kumquat", "lemon", "mango",
    "nectarine", "orange", "papaya", "quince", "raspberry", "strawberry",
    "tomato", "ugli", "vanilla", "watermelon", "xigua", "yam", "zucchini"
};
const int dictSize = sizeof(dictionar) / sizeof(dictionar[0]);
String currentWord; // cuvantul curent care trebuie introdus de utilizator

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

    setLEDColor(true, true, true); // LED alb in starea initiala

    Serial.begin(9600);
    randomSeed(analogRead(0));

    Serial.println("Selectati dificultatea si apasati start pentru a incepe.");
}

void loop() {
    if (inGame) {
        unsigned long currentMillis = millis();
        
        // verifica durata totala a jocului
        if (currentMillis - startMillis >= gameDuration) {
            stopGame();
        } else {
            // verifica inputul de la utilizator numai cand asteptam input
            if (awaitingInput && Serial.available() > 0) {
                checkInput();
            }
        }
    }
}

void setLEDColor(bool red, bool green, bool blue) {
    digitalWrite(ledRGB_R, red ? HIGH : LOW);   // HIGH aprinde culoarea rosie
    digitalWrite(ledRGB_G, green ? HIGH : LOW); // HIGH aprinde culoarea verde
    digitalWrite(ledRGB_B, blue ? HIGH : LOW);  // HIGH aprinde culoarea albastra
}

void blinkLED(int times) {
    for (int i = 0; i < times; i++) {
        setLEDColor(true, true, true); // alb
        delay(500);
        setLEDColor(false, false, false); // stins
        delay(500);
    }
}

void startGame() {
    inGame = true;
    awaitingInput = true;
    nrCuvinte = 0;
    startMillis = millis(); // start cronometrul general pentru durata jocului
    blinkLED(3); // numaratoare inversa
    setLEDColor(false, false, false); // stinge LED-ul la inceputul jocului
    Serial.println("Jocul a inceput! Introduceti cuvintele afisate:");
    displayWord(); // afiseaza primul cuvant
}

void stopGame() {
    inGame = false;
    awaitingInput = false;
    setLEDColor(true, true, true); // LED alb la sfarsitul jocului
    Serial.print("Jocul s-a terminat. Numar cuvinte corecte: ");
    Serial.println(nrCuvinte);
    Serial.println("Selectati dificultatea si apasati start pentru a incepe.");
}

void changeDifficulty() {
    difficultyLevel = (difficultyLevel + 1) % 3;
    switch (difficultyLevel) {
        case 0:
            currentInterval = 5000;
            Serial.println("Mod easy activat!");
            break;
        case 1:
            currentInterval = 3000;
            Serial.println("Mod medium activat!");
            break;
        case 2:
            currentInterval = 1000;
            Serial.println("Mod hard activat!");
            break;
    }
}

void displayWord() {
    int randIndex = random(0, dictSize);
    currentWord = String(dictionar[randIndex]); // salveaza cuvantul curent
    Serial.print("Introduceti cuvantul: ");
    Serial.println(currentWord);
    awaitingInput = true; // asteapta inputul utilizatorului
}

void checkInput() {
    String input = Serial.readStringUntil('\n');
    input.trim(); // elimina spatiile albe de la inceput si sfarsit
    
    if (input.length() == 0) {
        Serial.println("Input gol detectat - astept input valid.");
        return; // iese din functie daca nu a primit input valid
    }

    if (input.equals(currentWord)) { // compara cu cuvantul salvat
        nrCuvinte++;
        setLEDColor(false, true, false); // LED verde pentru raspuns corect
        Serial.println("Corect!");
    } else {
        setLEDColor(true, false, false); // LED rosu pentru raspuns gresit
        Serial.println("Gresit!");
    }
    
    delay(500);
    setLEDColor(false, false, false); // stingem LED-ul
    awaitingInput = false; // seteaza inputul ca fiind primit
    displayWord(); // afiseaza urmatorul cuvant
}

void startStopISR() {
    if (!inGame) {
        startGame();
    } else {
        stopGame();
    }
}

void difficultyISR() {
    unsigned long currentMillis = millis();
    if (currentMillis - lastDebounceTime > debounceDelay) {
        if (!inGame) {
            changeDifficulty();
        }
        lastDebounceTime = currentMillis;
    }
}
