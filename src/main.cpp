#include <Arduino.h>
#include <AccelStepper.h>

#define EN_PIN           12 // Enable
#define DIR_PIN          10 // Direction
#define STEP_PIN         11 // Step

AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN, DIR_PIN);

const int steps_per_mm = 80;

void setup() {
  Serial.begin(115200);

  Serial.println("* Connect Nema17 motor, it will turn left, then turn right in loop.");

  stepper.setMaxSpeed(50*steps_per_mm);
  stepper.setAcceleration(1000*steps_per_mm);
  stepper.setEnablePin(EN_PIN);
  stepper.setPinsInverted(false, false, true);
  stepper.enableOutputs();
}

int dir = 1;

void loop() {
    if (stepper.distanceToGo() == 0) {
        stepper.disableOutputs();
        delay(100);
        stepper.move(dir*100*steps_per_mm); // Move 100mm
        dir = dir * -1; 
        stepper.enableOutputs();
    }
    stepper.run();
}
