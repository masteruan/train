/*
 * 17 Luglio 2018
 * Giovanni Gentile per Breakout
 * 
 * Pannello di controllo sequenza bottoni
 * Schiacciare la sequenza indicata in seq
 * 
 * Componenti:
 * Arudino uno
 * 1 buzzer
 * 1 relay
 * 8 switch
 * 1 regolatore di tensione
 * 
 */
 
 
#define Bo1  2
#define B2  3
#define B3  4
#define B4  5
#define B5  6
#define B6  7
#define B7  8
#define B8  9
#define R1  10 //relay
#define P1  12 //buzzer

boolean button1IsUp = true; 
boolean button2IsUp = true;
boolean button3IsUp = true;
boolean button4IsUp = true;
boolean button5IsUp = true; 
boolean button6IsUp = true; 
boolean button7IsUp = true;
boolean button8IsUp  = true;
int steps = 1;
int trig = 0;
int bounce = 100;

//4 3 5 2 8 1 7 6
int seq[] = {4,3,5,2,8,1,7,6};

void setup() {
  pinMode(Bo1, INPUT_PULLUP);
  pinMode(B2, INPUT_PULLUP);
  pinMode(B3, INPUT_PULLUP);
  pinMode(B4, INPUT_PULLUP);
  pinMode(B5, INPUT_PULLUP);
  pinMode(B6, INPUT_PULLUP);
  pinMode(B7, INPUT_PULLUP);
  pinMode(B8, INPUT_PULLUP);
  pinMode(R1, OUTPUT);
  pinMode(P1, OUTPUT);
  Serial.begin(9600);
  Serial.println("Start Sequenza");
  tone(P1, 1000, 500);
}

void loop() {
  Serial.println(buttontest());
  
  switch(steps) {
  
    case 1:{
      if(buttontest() == seq[0]) {steps = 2; Serial.println("Go step 2"); tone(P1,1000,200); delay(500);} 
      break;
      }
    case 2:{
      if(buttontest() == seq[1]) {steps = 3; Serial.println("Go step 3");tone(P1,1000,200);delay(500);break;}
      else if(buttontest() == 0) {steps = 2; break;}
      else {steps = 1; Serial.println("error"); tone(P1, 500, 400);delay(100); break;}
      } 
    case 3:{
      if(buttontest() == seq[2]){steps = 4;Serial.println("Go step 4");tone(P1,1000,200);delay(500);break;}
      if(buttontest() == 0){steps = 3;break;}
      else {steps = 1; Serial.println("error"); tone(P1, 500, 400);delay(100); break;}
      }
    case 4:{
      if(buttontest() == seq[3]){steps = 5;Serial.println("Go step 5");tone(P1,1000,200);delay(500);break;}
      if(buttontest() == 0){steps = 4;break;}
      else {steps = 1; Serial.println("error"); tone(P1, 500, 400);delay(100); break;}
      }
    case 5:{
      if(buttontest() == seq[4]){steps = 6;Serial.println("Go step 6");tone(P1,1000,200);delay(500);break;}
      if(buttontest() == 0){steps = 5;break;}
      else {steps = 1; Serial.println("error"); tone(P1, 500, 400);delay(100); break;}
      }
    case 6:{
      if(buttontest() == seq[5]){steps = 7;Serial.println("Go step 7");tone(P1,1000,200);delay(500);break;}
      if(buttontest() == 0){steps = 6;break;}
      else {steps = 1; Serial.println("error"); tone(P1, 500, 400);delay(100); break;}
      }
    case 7:{
      if(buttontest() == seq[6]){steps = 8;Serial.println("Go step 8");tone(P1,1000,200);delay(500);break;}
      if(buttontest() == 0){steps = 7;break;}
      else {steps = 1; Serial.println("error"); tone(P1, 500, 400);delay(100); break;}
      }
    case 8:{
      if(buttontest() == seq[7]){trig = 1;Serial.println("Done"); tone(P1,1000,200); delay(500);break;}
      if(buttontest() == 0){steps = 8;break;}
      else {steps = 1; Serial.println("error"); tone(P1, 500, 400);delay(100); break;}
      }
    default:{break;}
  }
  if(trig) {
    digitalWrite(R1, HIGH);
    for (int i = 0; i <  6; i++) {
      tone(P1, 800+(i*100), 100);
      delay(100);
    }
    while(1);
    }
  
}

int buttontest(){
  button1IsUp = digitalRead(Bo1);
     if (!button1IsUp) {
      button1IsUp = true;
      delay(bounce);
      button1IsUp = digitalRead(Bo1);
      if (!button1IsUp) {return 1;}
     }

  button2IsUp = digitalRead(B2);
     if (!button2IsUp) {
      button2IsUp = true;
      delay(bounce);
      button2IsUp = digitalRead(B2);
      if (!button2IsUp) {return 2;}
     }

   button3IsUp = digitalRead(B3);
     if (!button3IsUp) {
      button3IsUp = true;
      delay(bounce);
      button3IsUp = digitalRead(B3);
      if (!button3IsUp) {return 3;}
     }

   button4IsUp = digitalRead(B4);
     if (!button4IsUp) {
      button4IsUp = true;
      delay(bounce);
      button4IsUp = digitalRead(B4);
      if (!button4IsUp) {return 4;}
     }

   button5IsUp = digitalRead(B5);
     if (!button5IsUp) {
      button5IsUp= true;
      delay(bounce);
      button5IsUp = digitalRead(B5);
      if (!button5IsUp) {return 5;}
     }

   button6IsUp = digitalRead(B6);
     if (!button6IsUp) {
      button6IsUp = true;
      delay(bounce);
      button6IsUp = digitalRead(B6);
      if (!button6IsUp) {return 6;}
     }

   button7IsUp = digitalRead(B7);
     if (!button7IsUp) {
      button7IsUp = true;
      delay(bounce);
      button7IsUp = digitalRead(B7);
      if (!button7IsUp) {return 7;}
     }

   button8IsUp = digitalRead(B8);
     if (!button8IsUp) {
      button8IsUp = true;
      delay(bounce);
      button8IsUp = digitalRead(B8);
      if (!button8IsUp) {return 8;}
     }
   return 0; 
}

