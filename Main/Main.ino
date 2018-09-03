/* ********************
* 24 Agosto 2018
* per Train Get Me Out
* v 0.1.0
* Giovanni Gentile
* 0lab.it projectg.it
* 
* OUTPUT
* Porte
* P1 vagoni
* P2 sala macchine
* P3 uscita
*
* Games
* C1 Q
* C2 W
* C3 E
* C4 R
* C5 T
* C6 Y
* C7 U
*
* Instructions
* Send to serial
* "_startGame" to start the game
*
* "_openAll" open all the doors and magnets
* "_reset" open all the doors and switch on the lights
* "_preparation" to close all the doors all the magnets and switch on all the lights
* 
* **********************/

// switch
boolean start_game = false;
boolean game_started = false;
boolean preparation = false;

// serial
boolean stringComplete = false;
String input = ""; //String
char inChar ;

int pauseTens = 20;

// calamite
int C1 = 10; // Q
int C2 = 11; // W
int C3 = 30; // E
int C4 = 31; // R
int C5 = 32; // T
int C6 = 33; // Y
int C7 = 34; // U

// Porte
int P1 = 9; // Vagoni 1 !
int P2 = 8; // Sala macchine 2 @
int P3 = 7; // Uscita 3 =

// Altro
int C8 = 6; //(led) I

// Arrays
int doors[] = {P1,P2,P3}; // 3 doors
int magnets[] = {C1,C2,C3,C4,C5,C6,C7}; // giochi

void setup() {
  Serial.flush();
  // Declare output
  // da 22 a 37 16 relay
  for (int i = 2; i < 36; i++){
    pinMode(i, OUTPUT);
    delay(20);
    digitalWrite(i, HIGH);
  }
  // Start up serial connection
  Serial.begin(9600); //default 115200
  input.reserve(200);

  Serial.println("####################################");
  Serial.println("You are Welcome into Breakout System");
  Serial.println("Train v 1.0");
}

void loop() {

  if (stringComplete) {
    seriale();
    delay(20);
    input = "";
    stringComplete = false;
  }
  game();
}

void game () {
   if (start_game){
      // reset booleane
      
      // Close all doors
      for (int i = 0; i < sizeof(doors); i++){
      digitalWrite(doors[i], LOW);
      delay(pauseTens);  
      }
      
      // Close all armadi
      for (int i = 0; i < sizeof(magnets); i++){
      digitalWrite(magnets[i], LOW);
      delay(pauseTens);  
      }
      
      // variables
      start_game = false;
      game_started = true;
      Serial.println("gameStarted");
  }

  else if (game_started){
    
    }
  }

void serialEvent() {
  Serial.flush();
  delay(20);
  // Read any serial input
  while (Serial.available())
  {
    inChar = (char)Serial.read(); // Read in one char at a time
    input += inChar;
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
