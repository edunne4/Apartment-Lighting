#define STROBE_DELAY 50 // the lower the faster



unsigned long lastStrobeTime = 0;
bool strobeOn = true;

void strobe(){
  if((unsigned long)(millis() - lastStrobeTime) > STROBE_DELAY){
    lastStrobeTime = millis();
    toggleStrobe(white);
  }
}

void randomStrobe(){
  if((unsigned long)(millis() - lastStrobeTime) > STROBE_DELAY){
    lastStrobeTime = millis();
    
    toggleStrobe(colors[random(0, NUM_COLORS)]);
  }
}



void toggleStrobe(rgbColor color){
  if (strobeOn){
    showColor(off);
    strobeOn = false;
  }else{
    showColor(color);
    strobeOn = true;
  }
}
