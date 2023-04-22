#ifndef NuttX_h
#define NuttX_h
#include "Arduino.h"

class NuttX
{
  public:
    Stream* _serial;
    String str;
    void init(Stream &stream);
    int play(String filename);
    void stop();
    void resume();
    void pause();
};

#endif
