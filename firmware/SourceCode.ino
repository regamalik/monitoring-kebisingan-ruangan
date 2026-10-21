#include <SoftwareSerial.h>
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

const int soundSensorPin = A0; // Pin untuk sensor suara
const int threshold = 500; // Ambang batas kebisingan
bool isPlaying = false; // Status pemutaran suara

void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);
  pinMode(soundSensorPin, INPUT);
  
  if (!myDFPlayer.begin(mySerial)) {
    Serial.println("DFPlayer Mini tidak terhubung!");
    while (true);
  }
  myDFPlayer.volume(10); // Atur volume
}

void loop() {
  int sensorValue = analogRead(soundSensorPin);
  
  if (sensorValue > threshold && !isPlaying) {
    isPlaying = true; // Set status pemutaran
    myDFPlayer.play(1); // Memutar file audio pertama
    delay(10000); // Delay untuk menghindari pemutaran berulang
    isPlaying = false; // Reset status pemutaran
  }
}