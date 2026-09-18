# BCA188 – Laboratory Activity: Control a Lamp's Brightness



 Sketch (brightnessSetting and switchOn tested for each combination)

The decision from Example 5 was moved into a function, per step 4–5 of the activity:

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

## Explanation of the function's parameters and return value

`getLampBrightness(bool switchOn, int brightnessSetting)` takes two parameters: `switchOn`, a `bool` describing whether the lamp's switch is currently on, and `brightnessSetting`, an `int` holding the saved brightness (0–100). Inside the function, an `if`/`else` checks `switchOn`: when it is `true`, the function returns `brightnessSetting` unchanged, so the lamp shows the saved value; when it is `false`, the function returns `0`, forcing the lamp off regardless of what `brightnessSetting` holds. The caller passes in two arguments (the current `switchOn` and `brightnessSetting`) and receives a single `int` back through `return`, which `setup()` stores in `lampBrightness` and then prints. Because `brightnessSetting` itself is never modified inside the function, turning the switch off never erases the saved setting — it only changes what the lamp currently displays.

## Coding Check

**1. In `int brightnessSetting = 75;`, identify the data type, variable name, and initial value. How would you change the value to 50?**

Data type: `int`. Variable name: `brightnessSetting`. Initial value: `75`. To change it to 50, use an assignment (no type before the name, since it is already declared): `brightnessSetting = 50;`

**2. Why is `bool` suitable for `switchOn`, while `int` is suitable for `brightnessSetting`?**

`switchOn` only ever needs to represent one of two conditions — on or off — which is exactly what a Boolean models. `brightnessSetting` instead needs to hold a whole-number value across a range (0 to 100), which a `bool` cannot represent, so an `int` (a type that can store and be reassigned to any whole number in range) is the appropriate choice.

**3. Predict the output when `brightnessSetting` is 80 and `switchOn` is false.**

```
Brightness setting: 80
Lamp brightness: 0
```

The saved setting is still 80 (and is printed as such), but because the switch is off, `getLampBrightness()` returns 0, so the lamp brightness is 0.

**4. Are `switchOn` and `switchon` the same variable? Explain.**

No. C++ is case-sensitive, so `switchOn` and `switchon` are two different identifiers. Using `switchon` anywhere in the program would either refer to an unrelated/undeclared name or cause a compiler error, not the intended variable.

**5. What values are passed to `getLampBrightness()`, and what does it return?**

It receives two arguments: the current `switchOn` (a `bool`) and the current `brightnessSetting` (an `int`). It returns a single `int`: `brightnessSetting` when `switchOn` is `true`, or `0` when `switchOn` is `false`.

**6. If `lampBrightness` is declared inside `setup()`, can `loop()` access it directly? Explain.**

No. `lampBrightness` is a local variable — its scope is limited to the block/function in which it was declared (`setup()`). Once `setup()` finishes, that name is no longer visible, so `loop()` cannot reference it by name. To share the value with `loop()`, it would need to be declared as a global variable instead.

---

**Checks satisfied:** when the switch is on, the lamp brightness matches the setting (rows 1–3); when the switch is off, the lamp brightness is 0 regardless of the setting (rows 4–6); and turning the switch off never changes the stored `brightnessSetting` value itself, only the returned `lampBrightness`.
