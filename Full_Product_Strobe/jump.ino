
#define JUMP3_DELAY 500
#define JUMP7_DELAY 1000


int curColorIdx = 0; //current color

int jumpDelay = JUMP3_DELAY;
unsigned long lastJumpTime = 0;


static void jump(){

  if((unsigned long)(millis() - lastJumpTime) > jumpDelay){
    lastJumpTime = millis();
    curColorIdx++;
    if (curColorIdx>= NUM_COLORS){
      curColorIdx = 0;
    }
    showColor(colors[curColorIdx]);
    Serial.println("jump");
  }
  
}

void startJump(int num){
  Serial.println("starting jump");
  if(num == 3){
    jumpDelay = JUMP3_DELAY;
  }else if (num == 7) {
    jumpDelay = JUMP7_DELAY;
  }
  
  analogWrite(REDPIN, random(0,256));
  analogWrite(GREENPIN, random(0,256));
  analogWrite(BLUEPIN, random(0,256));
  lastJumpTime = millis();
  Serial.println("ending start");
}
