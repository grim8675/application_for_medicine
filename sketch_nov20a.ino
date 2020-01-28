#include <SoftwareSerial.h>

int SensorPin1 = A0; //analog pin 0
int SensorPin2 = A1; //analog pin 1
int SensorPin3 = A2; //analog pin 2
int blueTx = 2;
int blueRx = 3;
SoftwareSerial mySerial(blueTx, blueRx);

void setup(){
  Serial.begin(9600);
  mySerial.begin(9600);
  
  // trig를 출력모드로 설정, echo를 입력모드로 설정

}
 
void loop(){
  int SensorReading = analogRead(SensorPin1);  
  int mfsr_r18 = map(SensorReading, 0, 1024, 0, 255);
  Serial.print("sensor0 = ");
  Serial.println(mfsr_r18);
  if(mfsr_r18 > 10)
  {
    if(mySerial.available()){
        mySerial.print('1');
    }
  }
  else if(mfsr_r18< 10)
  {
     if(mySerial.available()){
        mySerial.print('0');
    }
  }
  
  SensorReading = analogRead(SensorPin2);  
  mfsr_r18 = map(SensorReading, 0, 1024, 0, 255);
  Serial.print("sensor1 = ");
  Serial.println(mfsr_r18);
 if(mfsr_r18 > 10)
  {
    if(mySerial.available()){
        mySerial.print('3');
    }
  }
  else if(mfsr_r18< 10)
  {
     if(mySerial.available()){
        mySerial.print('2');
    }
  }
  
  SensorReading = analogRead(SensorPin3);  
  mfsr_r18 = map(SensorReading, 0, 1024, 0, 255);
  Serial.print("sensor2 = ");
  Serial.println(mfsr_r18);
   if(mfsr_r18 > 10)
  {
    if(mySerial.available()){
        mySerial.print('5');
    }
  }
  else if(mfsr_r18< 10)
  {
     if(mySerial.available()){
        mySerial.print('4');
    }
  }
  
  
  delay(1000); 
}
