int led1 = D1;
int led2 = D6;

void setup() {
    
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    
    Spark.function("sendData", sendData);
    Spark.function("money",ledSwitch);
    Spark.function("run",go);
    Serial.begin(9600);
    Serial1.begin(9600);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    
 
    //Serial1.println("Hello Serial 1");
}
  //Serial.begin(9600);
  //while(!Serial.available()) Particle.process();

  
void loop() {
    if(Serial1.available())
		Serial.write(Serial1.read());
}

int go(String command) {
  // put your main code here, to run repeatedly:
  if(command == "1"){  //forward
    Serial1.write(1);
    return 1;
  }
  else if(command == "2"){ //backwards
    Serial1.write(2);
    return 2;
  }
  else if(command == "3"){  //left
    Serial1.write(3);
    return 3;
  }
  else if(command == "4"){ //right
    Serial1.write(4);
    return 4;
  }
  else if(command == "5"){ //shoot
    Serial1.write(5);
    return 5;
  }
  else{                 //stop
    Serial1.write(0);
    return 0;
  }
  //flush();
}


int sendData(String command) {
	Serial.print("INCOMING: ");
	Serial.println(command);

	Serial1.print("SPARK: ");
	Serial1.println(command);

	return 1;
}

int ledSwitch(String command)
{
    if (command=="1") {
        digitalWrite(led1,HIGH);
        digitalWrite(led2,LOW);
        return 1;
    }
    else if (command=="2") {
        digitalWrite(led1,LOW);
        digitalWrite(led2,HIGH);
        return 2;
    }
    else if (command == "off")
    {
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        return 0;
    }
    else {
        return -1;
    }
}