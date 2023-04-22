#include "NuttX.h"

NuttX Audio;

void setup() {
  Serial1.begin(115200);
  while (!Serial1);
  Audio.init(Serial1);
  Audio.play("3.wav");
  delay(10000);
  Audio.stop();
}

void loop() {

}
