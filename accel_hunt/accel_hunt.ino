/* RGB */
int rPin = 11;
int gPin = 10;
int bPin = 9;

int xPin = A5;
int yPin = A6;
int zPin = A7;

int rVal, gVal, bVal; 

int accel[3]; //Array with accelerometer values, XYZ
float realAccel[3];  // calculated acceleration values here XYZ
float dist[3]; //distance from starting point XYZ

float samplesX[32];
float samplesY[32];

float currentPos[2]; //The players current coordinates XY

float targetX[5]; //X-coordinates for target position
float targetY[5]; //Y-coordinates for target position
boolean targetFound[5] = {true, false, false, false, true}; //True if the targets have been found

int playArea; //This determines the radius of the play area

int targetGrace; //How much grace the target positions gives 
  
void setup() {
  Serial.begin(9600);

  /* Setup digital outputs */
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);

  //Generate new targets
  setTargets();
}

void loop() {

  //Updating position
  updatePosition();
  updateLight();

  //Debugging
  Serial.println(accel[0]);
  Serial.println(accel[1]);
  Serial.println(accel[2]);
  Serial.println();
  Serial.println(targetsFound());
  Serial.println();
  delay(500);

  //Setting light intensities
  analogWrite(rPin, rVal);
  analogWrite(gPin, gVal);
  analogWrite(bPin, bVal);
}

/* Found out that you can't return arrays in C, so it is easier to call getPosition in the loop and use it to set an array */
void updatePosition() {

  //Reading sensors
  accel[0] = analogRead(xPin);
  accel[1] = analogRead(yPin);
  //accel[2] = analogRead(zPin);
  
  currentPos[0] = 0;
  currentPos[0] = 0;
      
  }

void updateLight() {
  //Updates the light intensities to the correct values according to game progress
  }

void setTargets() {
  //
  for (int i = 0; i < sizeof(targetX); i++) {
    targetX[i] = random(-playArea,playArea);
    targetY[i] = random(-playArea,playArea); 
    }
  
  }

int checkForTarget() {
  //Checks whether the player is in a Target zone. 
  //Returns a integer that correspond with the target number, when the player reaches a target.
  }

int targetsFound() {
  int found = 0;
  for (int i = 0; i < sizeof(targetFound); i++) {
    if(targetFound[i]) {
      found++;
      }     
    }
  return found;
  }
