#include <SoftwareSerial.h>
#include "DFPlayerMini_Fast.h"

SoftwareSerial mySerial(10, 11); // Pin 10 ke TX DFPlayer, Pin 11 ke RX DFPlayer
DFPlayerMini_Fast myDFPlayer;

int sensorPin = A3;              // Pin analog untuk sensor suara
unsigned long lastPlayTime = 0;  // Waktu terakhir suara dimainkan
unsigned long cooldownTime = 7000; // Waktu jeda (ms) sebelum suara dapat diputar lagi
int threshold = 45;              // Threshold dB untuk mendeteksi suara

void setup() {
  Serial.begin(9600);         // Memulai komunikasi serial untuk debugging
  mySerial.begin(9600);       // Inisialisasi komunikasi dengan DFPlayer Mini
  Serial.println("Inisialisasi...");

  if (!myDFPlayer.begin(mySerial)) { // Cek koneksi DFPlayer melalui SoftwareSerial
    Serial.println("DFPlayer tidak terdeteksi. Periksa koneksi.");
    while (true); // Berhenti jika DFPlayer tidak terdeteksi
  }

  Serial.println("DFPlayer Mini siap!");
  myDFPlayer.volume(30); // Atur volume (0-30)
}

void loop() {
  unsigned long currentTime = millis(); // Waktu saat ini
  int sensorValue = analogRead(sensorPin); // Membaca nilai analog dari sensor

  // Konversi nilai analog ke dB (kira-kira)
  int sensorDb = map(sensorValue, 0, 1023, 0, 100);

  Serial.print("Nilai Analog: ");
  Serial.print(sensorValue);
  Serial.print(" -> dB: ");
  Serial.println(sensorDb);

  // Jika sensor mendeteksi suara melebihi threshold dan cooldown selesai
  if (sensorDb >= threshold && (currentTime - lastPlayTime >= cooldownTime)) {
    Serial.println("Suara terdeteksi! Memutar suara...");
    myDFPlayer.play(1); // Memutar file pertama di DFPlayer
    lastPlayTime = currentTime; // Perbarui waktu terakhir suara dimainkan
  }

  delay(100); // Delay untuk pembacaan yang lebih stabil
}
