/* Valvole con indicatore e sgancio da relay
 *  5 Luglio 2018
 * 
 */
 
 #include <Servo.h>

Servo myServo1;
Servo myServo2;
Servo myServo3;
Servo myServo4;

int pot1= A0;
int pot2 = A1;
int potVal1;
int potVal2;
int relay = 9;
int relay2 = 10;

int angle1;
int oldAngle1 = 90;
int angle2;
int oldAngle2 = 90;
int angle3;
int oldAngle3 = 90;
int angle4;
int oldAngle4 = 90;

int counter = 0;

int val1 = 20;
int val2 = 20;

void setup() {
  pinMode(pot1, INPUT);
  pinMode(pot2, INPUT);
  pinMode(relay, OUTPUT);
  pinMode(relay2, OUTPUT);
  
  myServo1.attach(6);
  myServo2.attach(7);
  myServo3.attach(4);
  myServo4.attach(5);
  
  digitalWrite(relay, HIGH);
  digitalWrite(relay2, HIGH);
  Serial.begin(9600);
/*
  myServo1.write(90);
  myServo2.write(90);
  myServo3.write(90);
  myServo4.write(90);
  while (1);
*/
}

void loop() {
  potVal1 = analogRead(pot1);
  potVal2 = analogRead(pot2);

  angle1 = map(potVal1, 0, 1023, 0, 110);
  angle2 = map(potVal2, 0, 1023, 0, 110);
  
  //if(angle1>110){angle1=90;}
  
  if (angle1 < oldAngle1){
    oldAngle1 = oldAngle1 - 1;
  }
  
  if (angle2 < oldAngle2){
    oldAngle2 = oldAngle2 - 1;
  }
  
  if (angle1 > oldAngle1){
    oldAngle1 = oldAngle1 + 1;
  }
  
  if (angle2 > oldAngle2){
    oldAngle2 = oldAngle2 + 1;
  }
  
  myServo1.write(oldAngle1);
  myServo2.write(oldAngle2);
  myServo3.write(val1);
  myServo4.write(val2);

  if(oldAngle1 >108){
    val1 ++;
    delay(50);
    if (val1>110){val1 = 110;}
  }
  if(oldAngle1 < 10){
    val1 --;
    delay(50);
    if (val1 < 0){val1 = 0;}
  }
  
  if(oldAngle2 > 108){
    val2 ++;
    if (val2 > 110){val2 = 110;}
    delay(50);
  }

  if(oldAngle2 < 10){
    val2 --;
    if (val2 < 5){val2 = 5;}
    delay(50);
  }
  
  if ((oldAngle1 > 25 && oldAngle1 < 35) && (oldAngle2 > 50 && oldAngle2 < 68) && (val1 > 35 && val1 < 55) && (val2 > 40 && val2 < 55))
  {
    counter++;
    delay(20);
    Serial.println("GO");
  }
  else{counter = 0;}
  
  Serial.print("olaAngle1: ");
  Serial.println(oldAngle1);
  Serial.print("olaAngle2: ");
  Serial.println(oldAngle2);
  Serial.print("val1: ");
  Serial.println(val1);
  Serial.print("val2: ");
  Serial.println(val2);

  if (counter == 30){
    Serial.println("OK");
    digitalWrite(relay, LOW);
    delay(1000);
    for(int i = 0; i<10; i++){
        myServo1.write(23);
        myServo2.write(90);
        myServo3.write(25);
        myServo4.write(90);
        delay(2000);
        myServo1.write(90);
        myServo2.write(25);
        myServo3.write(90);
        myServo4.write(25);
    }
    digitalWrite(relay2, LOW);
    while(true);
  }
 //delay(15);
}
