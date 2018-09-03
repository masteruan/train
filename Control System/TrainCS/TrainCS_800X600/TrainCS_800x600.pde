/* Train Control System
*  24 Agosto 2018
*  Only write on port.
*  800x600
* 
*/

import static javax.swing.JOptionPane.*;
import processing.serial.*;
PFont f;
PImage img;

int bounce = 300; // debounce value

color c1 = #FF0000; // red
color c2 = #FFC000; // orange
color c3 = #E0FF00; // green
color c4 = #000000; // black
color c5 = #009933; //#66cd00; // green 2
color c6 = #FFFF33; // yellow
color c7 = #33FFFF; // light blue
color c8 = #FFFFF0; // white
color c9 = #C0C0C0; // silver

int buttColour = 100;
int textColour = 0;
int colors[] = {c5,c6,c4,c1}; // Button colors for column
int colorsEdge[] = {c8,c8,c4,c8}; // Button colors edge 

Serial myPort;  // Create object from Serial class
final boolean selectSerial = false; // select the selection of serial
final boolean debug = true;

char inChar;
String input;
String[] sommario = {""};
boolean stringComplete = false;

// Buttons variables
int dimW = 130; // 130
int dimH = 40; // 60
int buttonS = 20; // Spaziatura Y (20)
int buttonT = 50; 
int marginSx = 20; 

// boolean doors switch
boolean OP1 = false;
boolean OP11 = false;
boolean OP12 = false;

boolean OP2 = false;
boolean OP21 = false;
boolean OP22 = false;

boolean OP3 = false;
boolean OP31 = false;
boolean OP32 = false;

boolean OP4 = false;
boolean OP41 = false;
boolean OP42 = false;

boolean OP5 = false;
boolean OP51 = false;
boolean OP52 = false;

boolean OP6 = false;
boolean OP61 = false;
boolean OP62 = false;

boolean OP7 = false;
boolean OP71 = false;
boolean OP72 = false;

boolean OP8 = false;
boolean OP81 = false;
boolean OP82 = false;

int posX[] = {buttonS + marginSx, (dimW + (buttonS*2) + marginSx), ((dimW * 2) +(buttonS * 3) + marginSx), ((dimW * 3) + (buttonS * 4) + marginSx)};

int posY[] = { buttonS + dimH + buttonT,
              (buttonS*2) + (dimH*2) + buttonT,
              (buttonS*3) + (dimH*3) + buttonT,
              (buttonS*4) + (dimH*4) + buttonT,
              (buttonS*5) + (dimH*5) + buttonT,
              (buttonS*6) + (dimH*6) + buttonT,
              (buttonS*7) + (dimH*7) + buttonT,
              (buttonS*8) + (dimH*8) + buttonT,
              (buttonS*9) + (dimH*9) + buttonT,
              (buttonS*10) + (dimH*10) + buttonT,
            };

String[] pulsanti = {"Vagoni",  " Panca ",    "nome3",   "Start Game",
                     "Macchine",  " Mappa",  "nome7",   "button4b",
                     "Uscita",    "Rotativi",  "nome11",  "button4c",
                     "button1d",  "Quadro",  "nome15",  "button4d",
                     "Led Color",  "Esagoni",  "nome19",  "button4e",
                     "button1f",  "Dinamo",  "nome23",  "button4f",
                     "button1g",  "Motore",  "nome27",  "     Reset ",
                     "button1h",  "Valvole",  "nome31",  "Stop Game"};



int psX[] = {posX[0], posX[1], posX[2],posX[3]};
int psY[] = {posY[0], posY[1], posY[2], posY[3], posY[4], posY[5], posY[6], posY[7], posY[8]};

void setup(){
 String COMx, COMlist = "";
 size (800,600);
 //fullScreen(); //start at full screen
 f = createFont("viga.otf",22,true);
 img = loadImage("logo.PNG");
 
 background(255);
 stroke(0);
 noFill();
 
 if (!selectSerial){
 printArray(Serial.list());
 String portName = Serial.list()[0]; //change the 0 to a 1 or 2 etc. to match your port
 myPort = new Serial(this, portName, 9600);
 }
 
 if(selectSerial){
 /*
  Other setup code goes here - I put this at
  the end because of the try/catch structure.
*/
  try {
    if(debug) printArray(Serial.list());
    int i = Serial.list().length;
    if (i != 0) {
      if (i >= 2) {
        // need to check which port the inst uses -
        // for now we'll just let the user decide
        for (int j = 0; j < i;) {
          COMlist += char(j+'a') + " = " + Serial.list()[j];
          if (++j < i) COMlist += ",  ";
        }
        COMx = showInputDialog("Which COM port is correct? (a,b,..):\n"+COMlist);
        if (COMx == null) exit();
        if (COMx.isEmpty()) exit();
        i = int(COMx.toLowerCase().charAt(0) - 'a') + 1;
      }
      String porteName = Serial.list()[i-1];
      if(debug) println(porteName);
      myPort = new Serial(this, porteName, 9600); // change baud rate to your liking
      myPort.bufferUntil('\n'); // buffer until CR/LF appears, but not required..
    }
    else {
      showMessageDialog(frame,"Device is not connected to the PC");
      exit();
    }
  }
  catch (Exception e)
  { //Print the type of error
    showMessageDialog(frame,"COM port is not available (may\nbe in use by another program)");
    println("Error:", e);
    exit();
  }
 }
}
void keyPressed() {
  if (key == 'x') {
    exit();
  }
}

void draw(){
 
 textFont(f,20);
 //textSize(20);
 background(0);
 noFill();
 
 // exit button
 fill(c9);
 stroke(colorsEdge[0]); // shape buttons colour
 strokeWeight(2); 
 rect(650,37,100,40,7);
 fill(c4);
 textSize(27);
 text ("Exit", 673, 67);
     
 // Logo
 image(img, marginSx+20, -10, 130, 130);
 fill(255);
 textSize(40);
 text("The Train Control System", 170,70);
 textSize(27);
 
 
 // buttons and buttons text
 for (int n = 0; n < 8; n = n+1) {
   for (int i = 0; i < 4; i = i+1) {
     fill(colors[i]);
     stroke(colorsEdge[i]); // shape buttons colour
     strokeWeight(2); // weight of edge
     
     // double last column
     if(i==3){
       rect (psX[i], psY[n], dimW*2, dimH, 7);
     }
     else{
       rect (psX[i], psY[n], dimW, dimH, 7);
     }
     fill(textColour);
     if(i==3){
     text (pulsanti[n+n+n+n+i], psX[i] + (dimW/2), psY[n]+(dimH/2) + 10);
     }
    else{
     text (pulsanti[n+n+n+n+i], psX[i] + (dimW/4) - 20, psY[n]+(dimH/2) + 10);
    }
 }
 }
 // led port opened
 fill(0,255,0);
 stroke(0);
 
 if(OP1){
   ellipse(psX[0] + (dimW/4) + 90, psY[0]+(dimH/2) + 10, 10, 10);
 }
 if(OP2){
   ellipse(psX[0] + (dimW/4) + 90, psY[1]+(dimH/2) + 10, 10, 10);
 }
 if(OP3){
   ellipse(psX[0] + (dimW/4) + 90, psY[2]+(dimH/2) + 10, 10, 10);
 }
 if(OP4){
   ellipse(psX[0] + (dimW/4) + 90, psY[3]+(dimH/2) + 10, 10, 10);
 }
 if(OP5){
   ellipse(psX[0] + (dimW/4) + 90, psY[4]+(dimH/2) + 10, 10, 10);
 }
 if(OP6){
   ellipse(psX[0] + (dimW/4) + 90, psY[5]+(dimH/2) + 10, 10, 10);
 }
 if(OP7){
   ellipse(psX[0] + (dimW/4) + 90, psY[6]+(dimH/2) + 10, 10, 10);
 }
 if(OP8){
   ellipse(psX[0] + (dimW/4) + 90, psY[7]+(dimH/2) + 10, 10, 10);
 }
 if(OP11){
   ellipse(psX[1] + (dimW/4) + 90, psY[0]+(dimH/2) + 10, 10, 10);
 }
 if(OP21){
   ellipse(psX[1] + (dimW/4) + 90, psY[1]+(dimH/2) + 10, 10, 10);
 }
 if(OP31){
   ellipse(psX[1] + (dimW/4) + 90, psY[2]+(dimH/2) + 10, 10, 10);
 }
 if(OP41){
   ellipse(psX[1] + (dimW/4) + 90, psY[3]+(dimH/2) + 10, 10, 10);
 }
 if(OP51){
   ellipse(psX[1] + (dimW/4) + 90, psY[4]+(dimH/2) + 10, 10, 10);
 }
 if(OP61){
   ellipse(psX[1] + (dimW/4) + 90, psY[5]+(dimH/2) + 10, 10, 10);
 }
 if(OP71){
   ellipse(psX[1] + (dimW/4) + 90, psY[6]+(dimH/2) + 10, 10, 10);
 }
 if(OP81){
   ellipse(psX[1] + (dimW/4) + 90, psY[7]+(dimH/2) + 10, 10, 10);
 }
 // last button leds
 if(OP12){
   ellipse(psX[3] + (dimW/4), psY[0]+(dimH/2), 20, 20);
 }
  if(OP22){
   ellipse(psX[3] + (dimW/4), psY[1]+(dimH/2), 20, 20);
 }
  if(OP32){
   ellipse(psX[3] + (dimW/4), psY[2]+(dimH/2), 20, 20);
 }
  if(OP42){
   ellipse(psX[3] + (dimW/4), psY[3]+(dimH/2), 20, 20);
 }
  if(OP52){
   ellipse(psX[3] + (dimW/4), psY[4]+(dimH/2), 20, 20);
 }
  if(OP62){
   ellipse(psX[3] + (dimW/4), psY[5]+(dimH/2), 20, 20);
 }
  if(OP72){
   ellipse(psX[3] + (dimW/4), psY[6]+(dimH/2), 20, 20);
 }
  if(OP82){
   ellipse(psX[3] + (dimW/4), psY[7]+(dimH/2), 20, 20);
 }
 
 mouse();
}