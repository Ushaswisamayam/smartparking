#define BLYNK_TEMPLATE_ID "TMPL3qqh4OCVM"
#define BLYNK_TEMPLATE_NAME "Parking"
#define BLYNK_AUTH_TOKEN "ty9a2xke4hoE8_fP022q_16o9KsurSk1"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SoftwareSerial.h>

char auth[] = "ty9a2xke4hoE8_fP022q_16o9KsurSk1";
char ssid[] = "OnePlus";
char pass[] = "12345678";
const unsigned long interval = 1000; // Interval in milliseconds
unsigned long previousMillis = 0;
String myString;
char rdata;
int firstVal, secondVal, thirdVal;
int led1, led2, led3, led4, led5,led6;
void myTimerEvent() {
  Blynk.virtualWrite(V1, millis() / 1000);
}
void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}
void loop() {
  unsigned long currentMillis = millis();
  // Check if it's time to execute the timer event
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis; // Update the previousMillis for the next iteration
    myTimerEvent();
    sensorvalue1();
    sensorvalue2();
    sensorvalue3();
    sensorvalue4();
    sensorvalue5();
    sensorvalue6();
  }
  if (Serial.available() > 0) {
    rdata = Serial.read();
    myString = myString + rdata;
    if (rdata == '\n') {
      Serial.println(myString);
      String l = getValue(myString, ',', 0);
      String m = getValue(myString, ',', 1);
      String n = getValue(myString, ',', 2);
      String o = getValue(myString, ',', 3);
      String p = getValue(myString, ',', 4);
      String q = getValue(myString, ',', 5);
      led1 = l.toInt();
      led2 = m.toInt();
      led3 = n.toInt();
      led4 = o.toInt();
      led5 = p.toInt();
      led6 = q.toInt();
      myString = "";
    }
  }
  Blynk.run();
}
void sensorvalue1() {
  static unsigned long sensor1PreviousMillis = 0;
  unsigned long sensor1CurrentMillis = millis();
  if (sensor1CurrentMillis - sensor1PreviousMillis >= interval) {
    sensor1PreviousMillis = sensor1CurrentMillis;
    int sdata = led1;
    Blynk.virtualWrite(V10, sdata);
  }
}
void sensorvalue2() {
  static unsigned long sensor2PreviousMillis = 0;
  unsigned long sensor2CurrentMillis = millis();
  if (sensor2CurrentMillis - sensor2PreviousMillis >= interval) {
    sensor2PreviousMillis = sensor2CurrentMillis;
    int sdata = led2;
    Blynk.virtualWrite(V11, sdata);
  }
}
void sensorvalue3() {
  static unsigned long sensor3PreviousMillis = 0;
  unsigned long sensor3CurrentMillis = millis();
  if (sensor3CurrentMillis - sensor3PreviousMillis >= interval) {
    sensor3PreviousMillis = sensor3CurrentMillis;
    int sdata = led3;
    Blynk.virtualWrite(V12, sdata);
  }
}
void sensorvalue4() {
  static unsigned long sensor4PreviousMillis = 0;
  unsigned long sensor4CurrentMillis = millis();
  if (sensor4CurrentMillis - sensor4PreviousMillis >= interval) {
    sensor4PreviousMillis = sensor4CurrentMillis;
    int sdata = led4;
    Blynk.virtualWrite(V13, sdata);
  }
}
void sensorvalue5() {
  static unsigned long sensor5PreviousMillis = 0;
  unsigned long sensor5CurrentMillis = millis();
  if (sensor5CurrentMillis - sensor5PreviousMillis >= interval) {
    sensor5PreviousMillis = sensor5CurrentMillis;
    int sdata = led5;
    Blynk.virtualWrite(V14, sdata);
  }
}
void sensorvalue6() {
  static unsigned long sensor5PreviousMillis = 0;
  unsigned long sensor5CurrentMillis = millis();
  if (sensor5CurrentMillis - sensor5PreviousMillis >= interval) {
    sensor5PreviousMillis = sensor5CurrentMillis;
    int sdata = led6;
    Blynk.virtualWrite(V15, sdata);
  }
}
String getValue(String data, char separator, int index) {
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length() - 1;
  for (int i = 0; i <= maxIndex && found <= index; i++) {
    if (data.charAt(i) == separator || i == maxIndex) {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }
  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
