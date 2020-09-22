#define MIN_CHANGE 40


int changeDelayUp = 5; //the larger, the slower/less it changes
int changeDelayDown = 32; //the larger, the slower/less it changes


const int minValue = 65;
int purpPeak= 768;
int bluePeak = purpPeak * 0.25;//128;//256; 
int greenPeak = purpPeak * 0.5;//256;//512;
int redPeak = purpPeak * 0.75;//384;//768;

int soundLevel = 0;


static void soundReact() {
   int blueLevel = 0;
   int greenLevel = 0;
   int redLevel = 0;
      
   int newRead = analogRead(A0);
//   Serial.print(newRead);
//   Serial.print(" ");

   //only change soundLevel if big enough change to avoid flickering
   if(abs(newRead - soundLevel) > MIN_CHANGE){
      soundLevel += changeAmount(newRead);
   }
   
   //Serial.print("soundLevel: ");
   Serial.println(soundLevel);

   if (soundLevel < minValue){
      return; 
   }
   
//   blueLevel = soundLevel;
//   greenLevel = soundLevel;
//   redLevel = soundLevel;


   
   if(soundLevel < bluePeak){
      blueLevel = map(soundLevel, 0, bluePeak, 0, 255);    //increasing blue
   }else{
      blueLevel = map(soundLevel, bluePeak, greenPeak, 255, 0); 
   }   
      
   if(soundLevel < greenPeak){                                
      greenLevel = map(soundLevel, bluePeak, greenPeak, 0, 255);
   }else{
      greenLevel = map(soundLevel, greenPeak, redPeak, 255, 0);
   }

   if(soundLevel < redPeak){
      redLevel = map(soundLevel, greenPeak, redPeak, 0, 255);
   }else{
      redLevel = 255;
      //greenLevel = map(soundLevel, redPeak, purpPeak, 0, 255);
      blueLevel = map(soundLevel, redPeak, purpPeak, 0, 255);
   }
   
   int b = constrain(blueLevel, 0, 255);
   int g = constrain(greenLevel, 0, 255);
   int r = constrain(redLevel, 0, 255);
  

//   Serial.print("blueLevel: ");
//   Serial.println(b);
//   Serial.print("greenLevel: ");
//   Serial.println(g);
//   Serial.print("redLevel: ");
//   Serial.println(r);

   analogWrite(BLUEPIN, b);
   analogWrite(GREENPIN, g);
   analogWrite(REDPIN, r);   
   
}


int changeAmount(int whereToGo){
  int diff = whereToGo - soundLevel;
  int change = 0;
  if (diff > 0){
      change = diff/changeDelayUp;
  }else{
      change = diff/changeDelayDown;
  }

  return change;
}

void startSoundReact(int num){  
  analogWrite(BLUEPIN, 0);
  analogWrite(GREENPIN, 0);
  analogWrite(REDPIN, 0);
  switch(num){
    case 1:
      purpPeak= 512;
      changeDelayUp = 5; //the larger, the slower/less it changes
      changeDelayDown = 32; //the larger, the slower/less it changes
      break;
    case 2:
      purpPeak = 768;
      changeDelayUp = 5; //the larger, the slower/less it changes
      changeDelayDown = 32; //the larger, the slower/less it changes
      break;
    case 3:
      purpPeak = 768;
      changeDelayUp = 10; //the larger, the slower/less it changes
      changeDelayDown = 45; //the larger, the slower/less it changes
      break;
    case 4:
      purpPeak = 1023;
      changeDelayUp = 5; //the larger, the slower/less it changes
      changeDelayDown = 32; //the larger, the slower/less it changes
      break;
  }
  bluePeak = purpPeak * 0.25;
  greenPeak = purpPeak * 0.5;
  redPeak = purpPeak * 0.75;
}

