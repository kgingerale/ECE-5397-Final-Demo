#include <AFMotor.h> // Uses addafruit custom library to control the motor shield
#include <Servo.h> 
int i=0; // Counter used to limit loop when needed

// Declaring motors for the motor shield
AF_DCMotor LeftShoulder(1);
AF_DCMotor LeftBase(2);
AF_DCMotor RightShoulder(3);
AF_DCMotor RightBase(4);

//Inital was going to be used but due to inconsistency of the pots it was not initialized
int potls = A0;     // input pin for the left shoulder potentiometer
int potlb = A1;    // input pin for the left base potentiometer
int potrs = A2;    // input pin for the right shoulder potentiometer
int potrb = A3; // input pin for the right base potentiometer


int valls = 0;        // variable to store the value coming from the sensor on the right shoulder
int vallb = 0;       // variable to store the value coming from the sensor on the right base
int valrs = 0;       // variable to store the value coming from the sensor on the left shoulder
int valrb = 0;    // variable to store the value coming from the sensor on the left base



void setup() {
  Serial.begin(9600); // set up Serial library at 9600 bps
  Serial.println("Hope it works"); // General well wishes
}

void loop() { 
 //if (i<1){ // Comment this line in when debugging and out when not
 //Control combination used for the robot
  LSD(320); 
  STOP();

  LCC(1600);
  STOP();
  
  LSU(480); 
  STOP();

  LCW(1580);
  STOP();

  RSD(300);
  STOP();

  RCW(1700); 
  STOP();

  RSU(570);
  STOP();

  RCC(1600); 
  STOP();
  
 //i++;} // Used for debugging purposes when commentted in and not when out
}

//Function created to control the robot. They used the adafruit library custom digital write functions
// The controls are based on a timer set up that allows the motor to run for a decided amount of time before being turned off

//Controls left shoulder up movement
void LSU(int timeset){
LeftShoulder.run(BACKWARD);
LeftShoulder.setSpeed(200);
delay(timeset);}

//Controls left shoulder down movement
void LSD(int timeset){
LeftShoulder.run(FORWARD);
LeftShoulder.setSpeed(200);
delay(timeset);}

//Controls left base clockwise rotation 
void LCW(int timeset){
LeftBase.run(BACKWARD);
LeftBase.setSpeed(200);
delay(timeset);
}


//Controls left base counter clockwise rotation 
void LCC(int timeset){
LeftBase.run(FORWARD);
LeftBase.setSpeed(200);
delay(timeset);
}


//Controls right shoulder up movement
void RSU(int timeset){
RightShoulder.run(FORWARD);
RightShoulder.setSpeed(200);
delay(timeset);}



//Controls right shoulder down movement
void RSD(int timeset){
RightShoulder.run(BACKWARD);
RightShoulder.setSpeed(200);
delay(timeset);}

//Controls left base clockwise rotation 
void RCW(int timeset){
RightBase.run(FORWARD);
 RightBase.setSpeed(200);
delay(timeset);
}


//Controls left base counter clockwise rotation 
void RCC(int timeset){
RightBase.run(BACKWARD);
RightBase.setSpeed(200);
delay(timeset);
}

//Universal Stop
  void STOP(void){
    //Just sets the speed of all motors to zero
  RightBase.setSpeed(0);
  LeftBase.setSpeed(0);
  RightShoulder.setSpeed(0);
  LeftShoulder.setSpeed(0);
  delay(1000);
}


/*Code Blurb
 * The purpose of this code is control the movements of two OWI Robotic arms consectuively to get them to 
 * move from its starting positon.
 * The initial code methodlogy would've used potentiometers to monitor the positioing of the robot and move according to exact positions dictated by the pots.
 * However, due to continued unrealiability and lack of responsiveness with using pots on the base and shoulder joints, the aspects critical for our desired movement, we decided to digitally write to the motors. 
 * Digitally writing is not as precise with out the usage of pots, but it still gets the job done.
 * The motor driver used to control our robots motors is an adafruit arduino uno motor shield, that has a custom library for easy usage.
 * So, the code written is for an adafrutit arduino uno motor shield with the included custom adafruit motor library.
 * As a side note, the code does work and could be improved upon by incorperating the precision of the pots (which code regarding that methodlolgy has already been written, courtesy of demo 3 which miraculously had the pots working for a short time.
 */
