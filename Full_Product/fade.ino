
#define FADE3_DELAY 10     // make this higher to slow down
#define FADE7_DELAY 1


unsigned long lastFadeTime = 0;
int fadeDelay = FADE3_DELAY;

int currentPinChanging = REDPIN;
int currentPinValue = 0;
bool currentPinGoingUp = true;


static void fade(){
  
  if((unsigned long)(millis() - lastFadeTime) > fadeDelay){
    lastFadeTime = millis();

    if(currentPinGoingUp){
      currentPinValue++;
      if(currentPinValue > 255){
        currentPinValue = 255;
        //change pin and direction
        changePin();
        currentPinGoingUp = false;
      }
    }else{
      currentPinValue--;
      if(currentPinValue < 0){
        currentPinValue = 0;
        //change pin and direction
        changePin();
        currentPinGoingUp = true;
      }
    }
    
    
    analogWrite(currentPinChanging, currentPinValue);
    Serial.print(currentPinChanging);
    Serial.print(" ");
    Serial.println(currentPinValue);
  }
}

void changePin(){
  switch(currentPinChanging){
    case REDPIN:
      currentPinChanging = BLUEPIN; 
    break;
    case GREENPIN:
      currentPinChanging = REDPIN;
    break;
    case BLUEPIN:
      currentPinChanging = GREENPIN;
    break;
  }
}

void startFade(int num){
  Serial.println("starting fade");
  if(num == 3){
    fadeDelay = FADE3_DELAY;
  }else if (num == 7) {
    fadeDelay = FADE7_DELAY;
  }
  
  analogWrite(REDPIN, 0);
  analogWrite(GREENPIN, 0);
  analogWrite(BLUEPIN, 255);

  currentPinChanging = REDPIN;
  currentPinValue = 0;
  currentPinGoingUp = true;
  
    Serial.print(currentPinChanging);
    Serial.print(" ");
    Serial.println(currentPinValue);
    Serial.println("ending start");

    
}
