#include <SoftwareSerial.h>
SoftwareSerial nodemcu(2,3);
int parkingslot1=4;
int parkingslot2=5;
int parkingslot3=6;
int parkingslot4=7;
int parkingslot5=8;
int parkingslot6=9;

String sensor1;
String sensor2;
String sensor3;
String sensor4;
String sensor5;
String sensor6;

String cdata ="";

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
nodemcu.begin(9600);

pinMode(parkingslot1,INPUT);
pinMode(parkingslot2,INPUT);
pinMode(parkingslot3,INPUT);
pinMode(parkingslot4,INPUT);
pinMode(parkingslot5,INPUT);
pinMode(parkingslot6,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
plsslot1();
plsslot2();
plsslot3();
plsslot4();
plsslot5();
plsslot6();

cdata=cdata + sensor1 +","+sensor2 +","+sensor3 +","+sensor4 +"," +sensor5 +","+sensor6 +"," ;
Serial.println(cdata);
nodemcu.println(cdata);
delay(6000);
cdata= "";
digitalWrite(parkingslot1,HIGH);
digitalWrite(parkingslot2,HIGH);
digitalWrite(parkingslot3,HIGH);
digitalWrite(parkingslot4,HIGH);
digitalWrite(parkingslot5,HIGH);
digitalWrite(parkingslot6,HIGH);

}
void plsslot1(){
  if(digitalRead(parkingslot1)==LOW){
    sensor1= "255";
    delay(200);
  }
  if(digitalRead(parkingslot1)==HIGH){
    sensor1= "0";
    delay(200);
  }
}
void plsslot2(){
  if(digitalRead(parkingslot2)==LOW){
    sensor2= "255";
    delay(200);
  }
  if(digitalRead(parkingslot2)==HIGH){
    sensor2= "0";
    delay(200);
  }
}
void plsslot3(){
  if(digitalRead(parkingslot3)==LOW){
    sensor3= "255";
    delay(200);
  }
  if(digitalRead(parkingslot3)==HIGH){
    sensor3= "0";
    delay(200);
  }
}
void plsslot4(){
  if(digitalRead(parkingslot4)==LOW){
    sensor4= "255";
    delay(200);
  }
  if(digitalRead(parkingslot4)==HIGH){
    sensor4= "0";
    delay(200);
  }
}
void plsslot5(){
  if(digitalRead(parkingslot5)==LOW){
    sensor5= "255";
    delay(200);
  }
  if(digitalRead(parkingslot5)==HIGH){
    sensor5= "0";
    delay(200);
  }
}
void plsslot6(){
  if(digitalRead(parkingslot6)==LOW){
    sensor6= "255";
    delay(200);
  }
  if(digitalRead(parkingslot6)==HIGH){
    sensor6= "0";
    delay(200);
  }
}


