#include "NuttX.h"

NuttX Audio;

void setup() {
  Serial.begin(9600);
  Serial1.begin(115200);
  while (!Serial1);
  Audio.init(Serial1);
  pinMode(LED_BUILTIN, OUTPUT);
  delay(2000);
}

void loop() {
  Audio.play("3.wav");
  //Audio.play("3.wav");
  //Audio.play("3.wav");
  //Audio.play("3.wav");
  digitalWrite(LED_BUILTIN, Audio.isplaying());
  //delay(100);
  //Audio.play("2.wav");
  delay(10000);
  Audio.stop();
  digitalWrite(LED_BUILTIN, Audio.isplaying());
  delay(2000);
  /*Audio.play("3.wav");
  Audio.play("3.wav");
  Audio.play("3.wav");
  Audio.play("3.wav");
  Audio.play("3.wav");
  Audio.play("3.wav");
  Audio.play("3.wav");
  Audio.play("3.wav");
  delay(5000);
  Audio.stop();
  delay(2000);
  Audio.play("1.wav");
  delay(5000);
  Audio.stop();*/
}
