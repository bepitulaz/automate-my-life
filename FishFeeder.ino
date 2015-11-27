#include <TimedAction.h>
#include <Servo.h>

TimedAction timedAction = TimedAction(43200000, sweepServo);
Servo myServo;

void setup() {
  Serial.begin(9600);
}

void loop() {
   timedAction.check();
}

/*
 * Sweep the servo 180 degrees 
 */
void sweepServo() {
  // attach servo to pin
  myServo.attach(9);
  
  int pos = 0;
  int doLoop = 0;
  
  while (doLoop < 5) {
    for(pos=0; pos<180; pos+=1) {
      myServo.write(pos);
      delay(3);
    }
  
    for(pos=180; pos>=1; pos-=1) {
      myServo.write(pos);
      delay(3);
    }

    doLoop++;
  }

  myServo.detach();
}
