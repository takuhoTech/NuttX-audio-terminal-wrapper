#include "NuttX.h"

void NuttX::init(Stream &stream)
{
  _serial = &stream;
  do {
    _serial->println("");
    str = _serial->readStringUntil('>');
  } while ((str.lastIndexOf("nsh") == -1) && (str.lastIndexOf("nxplayer") == -1));
  do {
    _serial->println("nxplayer");
    str = _serial->readStringUntil('>');
  } while (str.lastIndexOf("nxplayer") == -1);
}

int NuttX::play(String filename)
{
  String temp = "play ";
  temp.concat(filename);
  do {
    _serial->println(temp);
    str = _serial->readStringUntil('>');
  } while (str.lastIndexOf("nxplayer") == -1);

  if (str.lastIndexOf("Audio device busy") != -1)
  {
    return 0;
  }
  else if (str.lastIndexOf("not found") != -1)
  {
    return -1;
  }
  return 1;
}

void NuttX::stop()
{
  do {
    _serial->println("stop");
    str = _serial->readStringUntil('>');
  } while (str.lastIndexOf("nxplayer") == -1);
}
