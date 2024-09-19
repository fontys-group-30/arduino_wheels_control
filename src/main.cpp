#include <Arduino.h>
#include <header/control_wheels.h>
#include <header/pins.h>



void setInitialRotation()
{
    digitalWrite(motorPins[0][1], LOW);
    digitalWrite(motorPins[0][2], HIGH);
    digitalWrite(motorPins[1][1], LOW);
    digitalWrite(motorPins[1][2], HIGH);
}

void setup()
{
    Serial.begin(115200);

    for (const auto motorPin : motorPins)
    {
        for (unsigned int j = 0; j < sizeof(motorPins[0]) / sizeof(motorPins[0][0]); j++)
        {
            pinMode(motorPin[j], OUTPUT);
        }
    }

    setInitialRotation();
}

void onDataReceived(const String &data) {
    controlWheels(data.toInt());
}

void loop() {
    if (Serial.available()) {
        const String data = Serial.readStringUntil('\n');
        onDataReceived(data);
    }
}