/* Rotary encoder with attachInterrupt
*
* relay pin 9
*
*
*/

// Encoder connect to digitalpin 2 and 3 on the Arduino.

int counter = 0;  //This variable will increase or decrease depending on the rotation of encoder
int relay = 9;

void setup() {
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);
  
  Serial.begin (9600);
 
  pinMode(2, INPUT);           // set pin to input
  pinMode(3, INPUT);           // set pin to input
  
  digitalWrite(2, HIGH);       // turn on pullup resistors
  digitalWrite(3, HIGH);       // turn on pullup resistors
 
 
  //Setting up interrupt
  //A rising pulse from encodenren activated ai0(). AttachInterrupt 0 is DigitalPin nr 2 on moust Arduino.
  attachInterrupt(0, ai0, RISING);
  
  //B rising pulse from encodenren activated ai1(). AttachInterrupt 1 is DigitalPin nr 3 on moust Arduino.
  attachInterrupt(1, ai1, RISING);
 digitalWrite(relay,LOW);
  delay(1000);
  digitalWrite(relay,HIGH);
  
}

void loop() {
  // Send the value of counter
  Serial.println(counter);
  //Serial.println (counter);
  counter = counter - 100; //400 default
  if (counter < 0 || counter > 60000){
    counter = 0;
  }
  if (counter > 15000){
    digitalWrite(relay, LOW);
  }
  else{digitalWrite(relay, HIGH);}
  
  delay(300);
}

void ai0() {
  // ai0 is activated if DigitalPin nr 2 is going from LOW to HIGH
  // Check pin 3 to determine the direction
  if(digitalRead(3)==LOW) {
    counter++;
  }else{
    counter--;
  }
}

void ai1() {
  // ai0 is activated if DigitalPin nr 3 is going from LOW to HIGH
  // Check with pin 2 to determine the direction
  if(digitalRead(2)==LOW) {
    counter--;
  }else{
    counter++;
  }
}
