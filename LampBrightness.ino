#include <Arduino.h>

// Returns the brightness the lamp should actually show,
// given the switch state and the stored brightness setting.
int getLampBrightness(bool switchOn, int brightnessSetting) {
  if (switchOn) {
    return brightnessSetting;   // switch is on -> use the saved setting
  } else {
    return 0;                   // switch is off -> lamp forced off
  }
}

void setup() {
  Serial.begin(115200);

  int brightnessSetting = 100;  // change to 0, 50, 100 for each trial
  bool switchOn = true;         // change to true / false for each trial

  int lampBrightness = getLampBrightness(switchOn, brightnessSetting);

  Serial.print("Brightness setting: ");
  Serial.println(brightnessSetting);
  Serial.print("Lamp brightness: ");
  Serial.println(lampBrightness);
}

void loop() {
}
