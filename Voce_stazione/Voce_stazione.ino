 /* ***********************************
  *  Pannello esagoni colorati 3 Luglio 2018
  *  Quando sdchiacci il bottonr colorato il
  *  numero di volte corrispodente agli esagoni.
  *  Parte la registrazione audio della stazione.
  *  
  *  Componenti:
  *  Arduino nano
  *  1 led (pin 7)
  *  1 buzzer (pin 9)
  *  3 switch (A0, A1, A2, A3)
  *  1 relay (pin 5)
  *  1 scheda mp3 
  *  1 casse acustiche (su scheda mp3)
  *  1 regolatore di tensione esterno
  *  
 ***************************************/
 
 #include "Arduino.h"
 #include "SoftwareSerial.h"
 #include "DFRobotDFPlayerMini.h"

 int relay = 5;
 int led = 7;
 int pause = 300;
 int code[] = {4,3,6,3};
 
 int buttonR = A0;
 int buttonG = A1;
 int buttonB = A2;
 int buttonW = A3;
 boolean signButtonR = false;
 boolean signButtonG = false;
 boolean signButtonB = false;
 boolean signButtonW = false;
 int counterR = 0;
 int counterG = 0;
 int counterB = 0;
 int counterW = 0;
 
 SoftwareSerial mySoftwareSerial(11, 12); // RX, TX
 DFRobotDFPlayerMini myDFPlayer; 

 void setup() {
   pinMode(led, OUTPUT);
   pinMode(buttonR, INPUT_PULLUP);
   pinMode(buttonG, INPUT_PULLUP);
   pinMode(buttonB, INPUT_PULLUP);
   pinMode(buttonW, INPUT_PULLUP);
   pinMode(relay, OUTPUT);
   digitalWrite(relay, HIGH);
   mySoftwareSerial.begin(9600);
   Serial.begin(115200);
   Serial.println("OK");
   if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
     Serial.println(F("Unable to begin:"));
     Serial.println(F("1.Please recheck the connection!"));
     Serial.println(F("2.Please insert the SD card!"));
     while(true);
   }
   
   delay(10);
   myDFPlayer.volume(30);
   myDFPlayer.play(2);
   Serial.println("Setup OK");
   leddino();
   digitalWrite(relay,1);
   delay(2000);
   digitalWrite(relay,0);
}

 void loop() {
   signButtonR = digitalRead(buttonR);
   if (!signButtonR) {
     delay(pause);
     counterR++;
     leddino();
     signButtonR = true;
   }
   
   signButtonG = digitalRead(buttonG);
   if (!signButtonG) {
     delay(pause);
     counterG++;
     leddino();
     signButtonG = true;
   }
   
   signButtonB = digitalRead(buttonB);
   if (!signButtonB) {
     delay(pause);
     counterB++;
     leddino();
     signButtonB = true;
   }
   
   signButtonW = digitalRead(buttonW);
   if (!signButtonW) {
     delay(pause);
     counterW++;
     leddino();
     signButtonW = true;
   }
   
   if (counterR > 6 || counterG > 6 || counterB > 6 || counterW > 6){
    
    myDFPlayer.play(2);
    for (int i = 0; i < 30; i ++){
      digitalWrite(led, 1);
      delay(100);
      digitalWrite(led, 0);
    }
    counterR = 0;
    counterG = 0;
    counterB = 0;
    Serial.println("Error");
   }
   
   if (counterR == code[0] && counterG == code[1] && counterB == code[2] && counterW == code[3]){
    myDFPlayer.play(1);
    digitalWrite(relay, 1);
    while (true);
   }
 }

 void leddino() {
  digitalWrite(led, 1);
  delay(100);
  Serial.print("R= ");
  Serial.println(counterR);
  Serial.print("G= ");
  Serial.println(counterG);
  Serial.print("B= ");
  Serial.println(counterB);
  Serial.print("W= ");
  Serial.println(counterW);
  digitalWrite(led, 0);
 }

