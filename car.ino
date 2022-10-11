char t;

int buzzer = 8; // buzzer makes beeb beeb when MQ-2 detect something
int smokeA5 = A5; // i can smell gas
int sensorThres = 250; // if reaches this make buzzer work

void setup() {
pinMode(13,OUTPUT);   // left motors forward
pinMode(12,OUTPUT);   // left motors reverse
pinMode(11,OUTPUT);   // right motors forward
pinMode(10,OUTPUT);   // right motors reverse
pinMode(buzzer, OUTPUT); // buzzer
pinMode(smokeA5, INPUT); // MQ-2

Serial.begin(9600);
}
 
void loop() {
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}

// MQ-2 
int analogSensor = analogRead(smokeA5);

// Checks if it has reached the threshold value
if (analogSensor > sensorThres){
    tone(buzzer, 1000, 200);
}
else{
    noTone(buzzer);
}

// H-Bridge
if(t == 'F'){            // move forward(all motors rotate in forward direction)
  digitalWrite(13,HIGH);
  digitalWrite(11,HIGH);
}
 
else if(t == 'B'){      // move reverse (all motors rotate in reverse direction)
  digitalWrite(12,HIGH);
  digitalWrite(10,HIGH);
}
 
else if(t == 'L'){      // turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
  digitalWrite(11,HIGH);
}
 
else if(t == 'R'){      // turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
  digitalWrite(13,HIGH);
}

else if(t == 'w'){
  digitalWrite(9,LOW);
}
 
else if(t == 'S'){      // STOP (all motors stop)
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
}
}
