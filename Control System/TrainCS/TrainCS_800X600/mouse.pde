void mouse() {
// Mouse Action
 if(mousePressed){

  //exit program
  if(mouseX > 650 && mouseX < 750 && mouseY > 40 && mouseY < 80){
  exit();
  }
  
  // first raw
  if(mouseX > psX[0] && mouseX < psX[0] + dimW && mouseY > psY[0] && mouseY < psY[0] + dimH){
   if(!OP1){
     myPort.write("1\n");
     OP1=true;
     delay(bounce);
   }
   else {
     myPort.write("!\n");
     OP1= false;
     delay(bounce);
   }
  }
  
  if(mouseX > psX[1] && mouseX < psX[1] + dimW && mouseY > psY[0] && mouseY < psY[0] + dimH ){
    if(!OP11){
      myPort.write("w\n");
      OP11=true;
      delay(bounce);
  }
  else {
     myPort.write("W\n");
     OP11= false;
     delay(bounce);
    }
  }
   
  if(mouseX > psX[2] && mouseX < psX[2] + dimW && mouseY > psY[0] && mouseY < psY[0] + dimH ){
  }
  
  if(mouseX > psX[3] && mouseX < psX[3] + dimW*2 && mouseY > psY[0] && mouseY < psY[0] + dimH ){
   if(!OP12){
     myPort.write("_startGame\n");
     OP12 = true;
     delay(bounce);
   }
   else{
     OP12 = false;
     delay(bounce);
   }
 }
  
  // second raw
  if(mouseX > psX[0] && mouseX < psX[0] + dimW && mouseY > psY[1] && mouseY < psY[1] + dimH ){
   if(!OP2){
     myPort.write("2\n");
     OP2 = true;
     delay(bounce);
   }
   else {
     myPort.write("@\n");
     OP2 = false;
     delay(bounce);
   }
  }
  
  if(mouseX > psX[1] && mouseX < psX[1] + dimW && mouseY > psY[1] && mouseY < psY[1] + dimH ){
   if (!OP21){
     //OP21=true;
     delay(bounce);
  }
  else {
    //OP21 = false;
    delay(bounce);
  }
  }
  
  if(mouseX > psX[2] && mouseX < psX[2] + dimW && mouseY > psY[1] && mouseY < psY[1] + dimH ){
  }
  
  if(mouseX > psX[3] && mouseX < psX[3] + dimW*2 && mouseY > psY[1] && mouseY < psY[1] + dimH ){
   if (!OP22){
     myPort.write("d\n");
     OP22=true;
     delay(bounce);
  }
  else{
     myPort.write("D\n");
     OP22=false;
     delay(bounce);
   }
  }
  
  // tirth raw
  if(mouseX > psX[0] && mouseX < psX[0] + dimW && mouseY > psY[2] && mouseY < psY[2] + dimH ){
   if(!OP3){
     myPort.write("3\n");
     OP3 = true;
     delay(bounce);
   }
   else {
     myPort.write("=\n");
     OP3 = false;
     delay(bounce);
   }
  }
  
  if(mouseX > psX[1] && mouseX < psX[1] + dimW && mouseY > psY[2] && mouseY < psY[2] + dimH ){
   if (!OP31){
    myPort.write("q\n");
    OP31 = true;
    delay(bounce);
   }
   else {
     myPort.write("Q\n");
     OP31 = false;
     delay(bounce);
   }
 }
  
  if(mouseX > psX[2] && mouseX < psX[2] + dimW && mouseY > psY[2] && mouseY < psY[2] + dimH ){
  }
  
  if(mouseX > psX[3] && mouseX < psX[3] + dimW*2 && mouseY > psY[2] && mouseY < psY[2] + dimH ){
   if (!OP32){
     myPort.write("_tempesta\n");
     OP32 = true;
     delay(bounce);
  }
  else {
    OP32 = false;
    delay(bounce);
  }
}
  
  // fourth raw
  if(mouseX > psX[0] && mouseX < psX[0] + dimW && mouseY > psY[3] && mouseY < psY[3] + dimH ){
   if(!OP4){
     
     //OP4 = true;
     delay(bounce);
   }
   else {
     
     //OP4 = false;
     delay(bounce);
   }
  }
  
  if(mouseX > psX[1] && mouseX < psX[1] + dimW && mouseY > psY[3] && mouseY < psY[3] + dimH ){
   if (!OP41){
     
     //OP41 = true;
     delay(bounce);
  }
  else {
    
    //OP41 = false;
    delay(bounce);
  }
}
  
  if(mouseX > psX[2] && mouseX < psX[2] + dimW && mouseY > psY[3] && mouseY < psY[3] + dimH ){
   }
  
  if(mouseX > psX[3] && mouseX < psX[3] + dimW*2 && mouseY > psY[3] && mouseY < psY[3] + dimH ){
   if (!OP42){
     myPort.write("_uvfx\n");
     OP42 = true;
     delay(bounce);
  }
  else {
    
    OP42 = false;
    delay(bounce);
   }
  }
  
  // five raw
   if(mouseX > psX[0] && mouseX < psX[0] + dimW && mouseY > psY[4] && mouseY < psY[4] + dimH ){
   if(!OP5){
     myPort.write("O\n");
     OP5 = true;
     delay(bounce);
   }
   else {
     myPort.write("o\n");
     OP5 = false;
     delay(bounce);
   }
  }
  
   if(mouseX > psX[1] && mouseX < psX[1] + dimW && mouseY > psY[4] && mouseY < psY[4] + dimH ){
     if(!OP51){
       myPort.write("f\n");
       OP51 = true;
       delay(bounce);
   }
   else {
     myPort.write("F\n");
     OP51 = false;
     delay(bounce);
   }
 }
   
   if(mouseX > psX[2] && mouseX < psX[2] + dimW && mouseY > psY[4] && mouseY < psY[4] + dimH ){
   }
   
   if(mouseX > psX[3] && mouseX < psX[3] + dimW*2 && mouseY > psY[4] && mouseY < psY[4] + dimH ){
   if (!OP52){
     myPort.write("Y\n");
     OP52=true;
     delay(bounce);
   }
   else {
     myPort.write("y\n");
     OP52=false;
     delay(bounce);
   }
 }
   
  // six raw
   if(mouseX > psX[0] && mouseX < psX[0] + dimW && mouseY > psY[5] && mouseY < psY[5] + dimH ){
   if(!OP6){
     myPort.write("N\n");
     OP6 = true;
     delay(bounce);
   }
   else {
     myPort.write("n\n");
     OP6 = false;
     delay(bounce);
   }
 }
   if(mouseX > psX[1] && mouseX < psX[1] + dimW && mouseY > psY[5] && mouseY < psY[5] + dimH ){
   if (!OP61){
     
     //OP61 = true;
     delay(bounce);
   }
   else{
     
     //OP61 = false;
     delay(bounce);
   }
 }
   
   if(mouseX > psX[2] && mouseX < psX[2] + dimW && mouseY > psY[5] && mouseY < psY[5] + dimH ){
   }
   
   if(mouseX > psX[3] && mouseX < psX[3] + dimW*2 && mouseY > psY[5] && mouseY < psY[5] + dimH ){
   if (!OP62){ 
     
     //OP62 = true;
     delay(bounce);
   }
   else{
     
     //OP62 = false;
     delay(bounce);
   }
 }
  
  // seven raw
   if(mouseX > psX[0] && mouseX < psX[0] + dimW && mouseY > psY[6] && mouseY < psY[6] + dimH ){
   if(!OP7){
     myPort.write("R\n");
     OP7 = true;
     delay(bounce);
   }
   else {
     myPort.write("r\n");
     OP7 = false;
     delay(bounce);
   }
 }
 
   if(mouseX > psX[1] && mouseX < psX[1] + dimW && mouseY > psY[6] && mouseY < psY[6] + dimH ){
   if(!OP71){
     myPort.write("p\n");
     OP71=true;
     delay(bounce);
  }
  else{
    myPort.write("P\n");
    OP71 = false;
    delay(bounce);
  }
}
  
   if(mouseX > psX[2] && mouseX < psX[2] + dimW && mouseY > psY[6] && mouseY < psY[6] + dimH ){
  }
  
   if(mouseX > psX[3] && mouseX < psX[3] + dimW*2 && mouseY > psY[6] && mouseY < psY[6] + dimH ){
   if (!OP72){
     myPort.write("_openAll\n");
     OP72 = true;
     delay(bounce);
  }
  else {
    OP72 = false;
    delay(bounce);
  }
}  
  // eight raw
   if(mouseX > psX[0] && mouseX < psX[0] + dimW && mouseY > psY[7] && mouseY < psY[7] + dimH ){
   if(!OP8){
     myPort.write("K\n");
     OP8 = true;
     delay(bounce);
   }
   else {
     myPort.write("k\n");
     OP8 = false;
     delay(bounce);
   }
 }
   if(mouseX > psX[1] && mouseX < psX[1] + dimW && mouseY > psY[7] && mouseY < psY[7] + dimH ){
   if(!OP81){
   delay(bounce);
   OP81 = true;
   delay(bounce);
  }
  else{
    //myPort.write("\n");
    OP81 = false;
    delay(bounce);
  }
}
  
   if(mouseX > psX[2] && mouseX < psX[2] + dimW && mouseY > psY[7] && mouseY < psY[7] + dimH ){
  }
  
   if(mouseX > psX[3] && mouseX < psX[3] + dimW*2 && mouseY > psY[7] && mouseY < psY[7] + dimH ){
   if(!OP82){
     myPort.write("_reset\n");
     OP82 = true;
     delay(bounce);
  }
  else{
    OP82 = false;
    delay(bounce);
  }
 }
}
}