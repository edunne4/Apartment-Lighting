#include <IRremote.h>
#include "receiverCodes.h"
#include "colors.h"


#define REDPIN 5
#define GREENPIN 6
#define BLUEPIN 9

#define RECV_PIN 11

bool activeMode = false;

IRrecv irrecv(RECV_PIN);

decode_results results;

//declare this here so it can be used as the default mode.
extern void fade();

void (*mode)() = fade;

float litLvl = 1; //between 0 and 1
rgbColor currentColor = red;

void setup()
{
  Serial.begin(9600);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  //Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  //Serial.println("Enabled IRin");


  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
  
  
  showColor(off);
}



void loop() {
  if (irrecv.decode(&results)) {
    //Serial.println(results.value, HEX);
    switch (results.value){
      case ON_BTN:
        litLvl = 1;
//        rgbColor randCol;
//        randCol = {random(0,256), random(0,256), random(0,256)};
//        currentColor = randCol;
//        showColor(randCol);
        showColor(currentColor);
        activeMode = false;
      break;
      case OFF_BTN:
        litLvl = 1;
        showColor(off);
        //currentColor = off;
        activeMode = false;
      break;
      case BRIGHT_UP:
        litLvl += 0.1;
        if(litLvl > 1){
          litLvl = 1;
        }
        showColor(currentColor);
        activeMode = false;
      break;
      case BRIGHT_DOWN:
        litLvl -= 0.1;
        if(litLvl < 0.1){
          litLvl = 0.1;
        }
        showColor(currentColor);
        activeMode = false;
      break;
      case RED_BTN:
        showColor(red);
        currentColor = red;
        activeMode = false;
      break;
      case GREEN_BTN:
        showColor(green);
        currentColor = green;
        activeMode = false;
      break;
      case BLUE_BTN:
        showColor(blue);
        currentColor = blue;
        activeMode = false;
      break;
      case WHITE_BTN:
        showColor(white);
        currentColor = white;
        activeMode = false;
      break;
      case ORANGE_BTN:
        showColor(orange);
        currentColor = orange;
        activeMode = false;
      break;
      case YELLOW_BTN:
        showColor(yellow);
        currentColor = yellow;
        activeMode = false;
      break;
      case CYAN_BTN:
        showColor(cyan);
        currentColor = cyan;
        activeMode = false;
      break;
      case PURPLE_BTN:
        showColor(purple);
        currentColor = purple;
        activeMode = false;
      break;
      case JUMP3_BTN:
        startJump(3);
        activeMode = true;
        mode = jump;
      break;
      case JUMP7_BTN:
        //startJump(7);
        startPuertoRico();
        activeMode = true;
        mode = puertoRico;
      break;
      case FADE3_BTN:
        startFade(3);
        activeMode = true;
        mode = fade;
      break;
      case FADE7_BTN:
        startFade(7);
        activeMode = true;
        mode = fade;
      break;
      case SOUND1_BTN:
        activeMode = true;
        startSoundReact(1);
        mode = soundReact;
      break;
      case SOUND2_BTN:
        activeMode = true;
        startSoundReact(2);
        mode = soundReact;
      break;
      case SOUND3_BTN:
        activeMode = true;
        startSoundReact(3);
        mode = soundReact;
      break;
      case SOUND4_BTN:
        activeMode = true;
        startSoundReact(4);
        mode = soundReact;
      break;
      case 0xFFFFFFFF:
        Serial.println("Repeat");
      break;
      default:
        Serial.println("Unknown");
      break;
    }
    irrecv.resume(); // Receive the next value
  }

  if(activeMode){
    mode();
  }
}

void showColor(rgbColor color){
  //currentColor = color;
  analogWrite(REDPIN, litLvl*color.r);
  analogWrite(GREENPIN, litLvl*color.g);
  analogWrite(BLUEPIN, litLvl*color.b);
}
