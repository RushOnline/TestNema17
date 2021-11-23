#include <Arduino.h>
#include <AccelStepper.h>

#define EN_PIN           11 // Enable
#define DIR_PIN          12 // Direction
#define STEP_PIN         13 // Step

AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN, DIR_PIN);

const int ms = 16;

void setup() {
  Serial.begin(115200);

  Serial.println("* Connect Nema17 motor, it will turn left, then turn right in loop.");

  //stepper.setMinPulseWidth(10);
  stepper.setMaxSpeed(16000);
  stepper.setAcceleration(32000);
  stepper.setEnablePin(EN_PIN);
  stepper.setPinsInverted(false, false, true);
  stepper.enableOutputs();
}

int dir = 1;

void loop() {
    if (stepper.distanceToGo() == 0) {
        delay(100);
        stepper.move(dir*1000*ms);
        dir = -dir; 
    }
    stepper.run();
}
