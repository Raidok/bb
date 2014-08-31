/*
 * Aeg ja logimine
 * 
 * Näide, kuidas kellaaega konsooli logida.
 */

#include <Time.h>
#include <Wire.h>
#include <Logging.h>

void setup() {
  Log.Init(LOG_LEVEL_VERBOSE, 9600);
  setTime(1409508957);
}

void loop() {
  Log.Debug("%s testing"CR, getTimestamp().c_str());
  delay(1000);
}

String getTimestamp() {
  TimeElements tm;
  breakTime(now(), tm);
  char buffer[20];
  sprintf(buffer, "%04d.%02d.%02d %02d:%02d:%02d",
    1970+tm.Year, tm.Month, tm.Day, tm.Hour, tm.Minute, tm.Second);
  String str(buffer);
  return str.c_str();
}

