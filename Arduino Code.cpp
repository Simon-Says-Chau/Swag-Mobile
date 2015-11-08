#include <SoftwareSerial.h>

int S1 = 6;
int S2 = 5;
int M1 = 8;
int M2 = 7;
int reading = 0;
int ledWhite = 13;
int ledBlue = 12;
int sensor = A0;
int irReading = 0;
int prevIr = 0;
bool cop = true;

SoftwareSerial mySerial(0, 1); // RX, TX

void setup() {
  // put your setup code here, to run once:
  pinMode(S1, OUTPUT); //M1 speed
  pinMode(S2, OUTPUT); //M1 speed
  pinMode(M1, OUTPUT); //M1 speed
  pinMode(M2, OUTPUT); //M1 speed
  pinMode(ledWhite,OUTPUT);
  pinMode(ledBlue, OUTPUT);


  Serial.begin(9600);  //open serial communicaton
  
  pinMode(sensor, INPUT);
   
 Serial.println("READY");
//  while(!Serial){
//    ;
//  }
 mySerial.begin(9600);
 mySerial.println("SOFTWARE READY");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(mySerial.available()) {
    reading = mySerial.read();
    Serial.write(mySerial.read());
    Serial.println("read");
  }
  if (reading == 1){
    digitalWrite(M1, HIGH);
    digitalWrite(M2, HIGH);
    analogWrite(S1, 150);
    analogWrite(S2, 150);
  }
  else if (reading == 2){    //backwards
    digitalWrite(M1, LOW);
    digitalWrite(M2, LOW);
    analogWrite(S1, 200);
    analogWrite(S2, 200);
  }
  else if (reading == 3){    //Right
    digitalWrite(M1, HIGH);
    digitalWrite(M2, LOW);
    analogWrite(S1, 255);
    analogWrite(S2, 150);
  }
  else if (reading == 4){    //Left
    digitalWrite(M1, LOW);
    digitalWrite(M2, HIGH);
    analogWrite(S1, 150);
    analogWrite(S2, 255);
  }
  else if (reading == 5){   //Shoot
  }
  else{
    digitalWrite(M1, HIGH);
    digitalWrite(M2, HIGH);
    analogWrite(S1, 0);
    analogWrite(S2, 0);
  }
 
  prevIr = irReading;
  irReading = analogRead(sensor);
  //if (prevIr - irReading >= 350)
  if(irReading < 300)
  {
    if(cop) {
      digitalWrite(ledWhite, HIGH);
      digitalWrite(ledBlue, LOW);
      cop = false;
      digitalWrite(M1, LOW);
      digitalWrite(M2, LOW);
     analogWrite(S1, 150);
     analogWrite(S2, 150);
     reading = 2;
    }
    else{
      digitalWrite(ledBlue, HIGH);
      digitalWrite(ledWhite, LOW);
      cop = true;
      analogWrite(S1, 0);
      analogWrite(S2, 0);
      reading = 0;
    }
    //digitalWrite(ledBlue, HIGH);

    
   }
  Serial.print("Reading: ");
  Serial.println(irReading);
  //Serial.println();
  delay(500);
}
