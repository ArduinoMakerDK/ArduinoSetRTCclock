//Set RTC time
//by ArduinoMakerDK
//2019

#include <RTClib.h>
#include <Wire.h>
 
RTC_DS3231 rtc;
 
char t[32];
 
void setup() 
{
  Serial.begin(9600);
  Wire.begin();
 
  rtc.begin();
  rtc.adjust(DateTime(2019, 5, 3, 18, 42, 0));
  //rtc.adjust(DateTime(year, month, day, time, minute, second));
  
 
}
 
void loop()
{
  DateTime now = rtc.now();
 
  sprintf(t, "%02d:%02d:%02d %02d/%02d/%02d",  now.hour(), now.minute(), now.second(), now.day(), now.month(), now.year());  
  
  Serial.print(F("Date/Time: "));
  Serial.println(t);
 
  delay(1000);
}
