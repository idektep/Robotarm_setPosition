#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver idektep = Adafruit_PWMServoDriver(0x40);

#define SERVOMIN  100
#define SERVOMAX  600

#define servo1 0
#define servo2 1
#define servo3 2
#define servo4 3
#define servo5 4

int pos1 = 0;
int pos2 = 0;
int pos3 = 0;
int pos4 = 0;
int pos5 = 0;

int angleToPulse(int ang) {
  int pulse = map(ang, 0, 180, SERVOMIN, SERVOMAX);
  return pulse; 
}

void setup()
{
  Serial.begin(115200);
  idektep.begin();
  idektep.setPWMFreq(60);

  pos1 = 90;
  pos2 = 90;
  pos3 = 90;
  pos4 = 30;
  pos5 = 10;  //Gripper set

//  HomePos();
  idektep.setPWM(servo1, 0, angleToPulse(pos1) );
  idektep.setPWM(servo2, 0, angleToPulse(pos2) );
  idektep.setPWM(servo3, 0, angleToPulse(pos3) );
  idektep.setPWM(servo4, 0, angleToPulse(pos4) );
  idektep.setPWM(servo5, 0, angleToPulse(pos5) );
}

void loop() {

}
