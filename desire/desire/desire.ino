/* 

LDR is currently placed in pin A0 and 5V
RGB LED uses pin 9, 10, 11.  

*/ 

//RGB
int rPin = 11;
int gPin = 10;
int bPin = 9;

int rVal, gVal, bVal; 

//LDR
int LDRPin = A0;

int stimulationThreshold = 10;
int stimulation;

int pulse;
boolean countingUp = true;

void setup() {
  Serial.begin(9600);

  /* Setup digital outputs */
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  
}

void loop() {

  updateStimulation();
  
  updateLight();
  Serial.println(stimulation);

  if (stimulation > 10) {
    openBox();
  }

  //Delay to make Serial easier to read.
  delay(100);
}

int updateStimulation() {
  int light = analogRead(A0);
  
  if (light < 10) {
    stimulation++;
  } else if (light > 10 && stimulation > 0) {
    stimulation--;  
  }
}

void updateLight(){
  
  if (pulse < 255 && stimulation >= 0) {
    if (countingUp) {
      pulse++;
      rVal = int(rVal + 1 * stimulation/10);  
    } else {
      pulse--;
      rVal = int(rVal - 1 * stimulation/10);  
    }
  } else if (pulse >= 255) {
    pulse = 255;  
    countingUp = false;
  } else if (pulse <= 0) {
    pulse = 0; 
    countingUp = true;
    }

  Serial.println("Red");
  Serial.println(rVal);
  Serial.println("pulse");
  Serial.println(pulse); 
  analogWrite(rPin, rVal);
  analogWrite(gPin, gVal);
  analogWrite(bPin, bVal);
}

void openBox() {
  
}

void closeBox() {
}
