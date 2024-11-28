#include <Wire.h>
#include <RTClib.h>

#define RELAY_PIN 5
#define LED_PIN 2

RTC_DS3231 rtc;

unsigned long lastActivationTime = 0;
const unsigned long intervalSeconds = 12 * 60 * 60; 
const unsigned long pumpRunTimeMillis = 5000;       // 5 Sek

void setup() {
  Serial.begin(115200);

  // GPIO
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW); // A
  digitalWrite(LED_PIN, LOW);   // A

  // RTC
  if (!rtc.begin()) {
    Serial.println("DS3231 nicht gefunden. Bitte prüfen!");
    while (1);
  }

  // Uhrzeit
  if (rtc.lostPower()) {
    Serial.println("RTC hat Strom verloren, Uhrzeit wird auf 00:00:00 zurückgesetzt!");
    rtc.adjust(DateTime(2000, 1, 1, 0, 0, 0)); // SZ
  }

  //SZ H
  lastActivationTime = rtc.now().unixtime();
}

void loop() {
  // AZ
  unsigned long currentTime = rtc.now().unixtime();

  // 12<?
  if ((currentTime - lastActivationTime) >= intervalSeconds) {
    Serial.println("12 Stunden sind vergangen, Pumpe wird gestartet!");

    // ZAA
    lastActivationTime = currentTime;

    // LED E
    digitalWrite(RELAY_PIN, HIGH);
    digitalWrite(LED_PIN, HIGH);
    delay(pumpRunTimeMillis); // 5 SP

    // LED A
    digitalWrite(RELAY_PIN, LOW);
    digitalWrite(LED_PIN, LOW);

    Serial.println("Pumpe wurde gestoppt.");
  }

  delay(1000); // 1SEK
}

