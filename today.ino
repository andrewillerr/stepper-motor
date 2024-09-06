#include <Stepper.h>

const int stepsPerRevolution = 2048;

Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

int val = 0;
int speedS = 0;
String mode;
float time;
void setup() {
  pinMode(3, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.flush();
}

void loop() {
  if (digitalRead(3) == 0) {
    Serial.println("Start");
    val = analogRead(A5);
    if (val <= 341) {
      speedS = 5;
      mode = "Slow";
    } else if (val <= 682) {
      speedS = 10;
      mode = "Normal";
    } else {
      speedS = 15;
      mode = "Fast";
    }
    myStepper.setSpeed(speedS);
    Serial.print("Mode : ");
    Serial.println(mode);
    Serial.println("--------------------");
    Serial.print("Position : ");
    Serial.print("0");
    Serial.println(" degrees");
    Serial.print("Time : ");
    time = float(millis()) / 1000;
    Serial.print((float(millis()) / 1000) - time);
    Serial.println(" seconds");
    Serial.println("--------------------");
    for (int i = 90; i < 450; i += 90) {
      myStepper.step(512);
      Serial.print("Position : ");
      Serial.print(i);
      Serial.println(" degrees");
      Serial.print("Time : ");
      Serial.print((float(millis()) / 1000) - time);
      Serial.println(" seconds");;
      Serial.println("--------------------");
    }
    delay(1000);
  }
}
