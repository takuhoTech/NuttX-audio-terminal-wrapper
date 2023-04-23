#ifndef NuttX_h
#define NuttX_h
#include "Arduino.h"

class NuttX
{
  public:
    void init(Stream &stream);
    int play(String filename);
    void stop();
    void pause();
    void resume();
    bool isplaying();
  private:
    Stream* _serial;
    String str;
    unsigned long lasttime_play = 0;
    unsigned long interval_play = 100;
};

#endif
