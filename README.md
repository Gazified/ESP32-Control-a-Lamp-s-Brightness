# BCA188 – Laboratory Activity: Control a Lamp's Brightness


## Sketch 



```cpp
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
```

For each trial, `brightnessSetting` and `switchOn` at the top of `setup()` were changed to the six combinations below, and the sketch was re-run for each one.

##  Completed Results Table

| Brightness setting | Switch state | Expected lamp brightness | Observed output |
|---|---|---|---|
| 0   | On  | 0   | 0   |
| 50  | On  | 50  | 50  |
| 100 | On  | 100 | 100 |
| 0   | Off | 0   | 0   |
| 50  | Off | 0   | 0   |
| 100 | Off | 0   | 0   |

Explanation of the function's parameters and return value

getLampBrightness() takes two parameters: switchOn (bool) and brightnessSetting (int). 
If switchOn is true, it returns brightnessSetting. If false, it returns 0. The returned value is stored in lampBrightness and printed. Note that brightnessSetting itself doesn't change — only what gets returned changes.

### Coding Check

1. In int brightnessSetting = 75;, identify the data type, variable name, and initial value. How would you change the value to 50?

    Type: int, name: brightnessSetting, value: 75. To change it: brightnessSetting = 50;

2. Why is bool suitable for switchOn, while int is suitable for brightnessSetting?

    switchOn only has two possible states (on/off), so bool fits. brightnessSetting can be any number from 0–100, so it needs int.

3. Predict the output when brightnessSetting is 80 and switchOn is false.

    Brightness setting: 80
    Lamp brightness: 0

    Switch is off, so the function returns 0 even though the setting is still 80.

4. Are switchOn and switchon the same variable? Explain.

    No, they're different variables. C++ is case-sensitive.

5. What values are passed to getLampBrightness(), and what does it return?

    It takes switchOn and brightnessSetting as arguments and returns an int — either the setting or 0.

6. If lampBrightness is declared inside setup(), can loop() access it directly? Explain.

    No. lampBrightness is local to setup(), so loop() can't see it. It would need to be global.


