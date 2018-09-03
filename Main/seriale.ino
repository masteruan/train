// LOW switch ON
// HIGH switch OFF

void seriale() {

  // open doors
  if (input[0] == '1'){
    digitalWrite(P1, HIGH);
    delay(pauseTens);
  }
  else if (input[0] == '2'){
    digitalWrite(P2, HIGH);
    delay(pauseTens);
  }
  else if (input[0] == '3'){
    digitalWrite(P3, HIGH);
    delay(pauseTens);
  }

  // close the doors
  else if (input[0] == '!'){
    digitalWrite(P1, LOW);
    delay(pauseTens);
  }
  else if (input[0] == '@'){
    digitalWrite(P2, LOW);
    delay(pauseTens);
  }
  else if (input[0] == '='){
    digitalWrite(P3, LOW);
    delay(pauseTens);
  }

  
  // games
  else if (input[0] == 'Q'){
    digitalWrite(C1, LOW);
    delay(pauseTens);
  }
  else if (input[0] == 'q'){
    digitalWrite(C1, HIGH);
    delay(pauseTens);
  }
  else if (input[0] == 'W'){
    digitalWrite(C2, LOW);
    delay(pauseTens);
  }
  else if (input[0] == 'w'){
    digitalWrite(C2, HIGH);
    delay(pauseTens);
  }
  else if (input[0] == 'E'){
    digitalWrite(C3, LOW);
    delay(pauseTens);
  }
  else if (input[0] == 'e'){
    digitalWrite(C3, HIGH);
    delay(pauseTens);
  }
  else if (input[0] == 'R'){
    digitalWrite(C4, LOW);
    delay(pauseTens);
  }
  else if (input[0] == 'r'){
    digitalWrite(C4, HIGH);
    delay(pauseTens);
  }
   else if (input[0] == 'T'){
    digitalWrite(C5, LOW);
    delay(pauseTens);
  }
  else if (input[0] == 't'){
    digitalWrite(C5, HIGH);
    delay(pauseTens);
  }
  else if (input[0] == 'Y'){
    digitalWrite(C6, LOW);
    delay(pauseTens);
  }
  else if (input[0] == 'y'){
    digitalWrite(C6, HIGH);
    delay(pauseTens);
  }
  else if (input[0] == 'U'){
    digitalWrite(C7, LOW);
    delay(pauseTens);
  }
  else if (input[0] == 'u'){
    digitalWrite(C7, HIGH);
    delay(pauseTens);
  }
  else if (input[0] == 'I'){
    digitalWrite(C8, LOW);
    delay(pauseTens);
  }
  else if (input[0] == 'i'){
    digitalWrite(C8, HIGH);
    delay(pauseTens);
  }
  
  // SEQUENCES

  // start
  // start game TRUE
  else if (input == "_startGame\n" && !start_game){
    Serial.println("start");
    start_game = true;
    game_started = false;
  }

  // Open All
  // _openAll Open all doors, all games and switch on lights
  else if (input == "_openAll\n") {
    for (int i = 0; i < 3; i++){
      digitalWrite(doors[i], HIGH);
      delay (pauseTens);
    }
    for (int i = 0; i < 6; i++){
      digitalWrite(magnets[i], HIGH);
      delay (pauseTens);
    }
  }

  // reset
  // _reset open all doors and switch on lights
  else if (input == "_reset\n"){
    for (int i = 0; i < 3; i++){
      digitalWrite(doors[i], HIGH);
      delay (pauseTens);
    }
    for (int i = 0; i < 7; i++){
      digitalWrite(magnets[i], HIGH);
      delay (pauseTens);
    }
  }

  //preparation
  // _preparation close all doors and magnets and switch on the lights
  else if (input == "_preparation\n"){
    
    for (int i = 0; i < 3; i++){
      digitalWrite(doors[i], LOW);
      delay (pauseTens);
    }
    for (int i = 0; i < 7; i++){
      digitalWrite(magnets[i], LOW);
      delay (pauseTens);
    }
  }
}
