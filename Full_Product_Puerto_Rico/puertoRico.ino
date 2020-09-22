
#define JUMP_PR_DELAY 1000


#define NUM_COLORS_PR 3
rgbColor puertoColors[] = {red, white, blue};
int j = 0; //current color

//int jumpDelay = JUMP3_DELAY;
unsigned long lastPRTime = 0;


static void puertoRico(){

  if((unsigned long)(millis() - lastPRTime) > JUMP_PR_DELAY){
    lastPRTime = millis();
    j++;
    if (j>= NUM_COLORS_PR){
      j = 0;
    }
    showColor(puertoColors[j]);
    Serial.println(j);
  }
  
}

void startPuertoRico(){
  Serial.println("starting puerto rico");
  
  
  showColor(colors[j]);
  lastPRTime = millis();
  Serial.println("ending start");
}
