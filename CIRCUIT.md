# Arduino Bluetooth — Circuit Schematic

- Course: Arduino: Interfacing Bluetooth with Arduino Step by Step
- Author: Ashraf S A AlMadhoun
- Link: https://www.udemy.com/course/arduino-interfacing-bluetooth-with-arduino-step-by-step/?couponCode=JULYMAXDICOUNT

## Connections (HC-05)

- `HC-05 VCC -> 5V`
- `HC-05 GND -> GND`
- `HC-05 TXD -> Arduino RX (D0)` or `D10` via SoftwareSerial
- `HC-05 RXD -> Arduino TX (D1)` or `D11` via SoftwareSerial (use voltage divider)
- LED: Onboard `D13`

## Diagram (ASCII)

```
 HC-05              Arduino UNO
  VCC ---- 5V       D0 (RX) <--- TXD
  GND ---- GND      D1 (TX) ---> RXD (via divider)
                     D13 LED onboard
```

## Notes

- Use a voltage divider on HC-05 `RXD` to avoid 5V direct drive.
- Alternatively use SoftwareSerial on 3.3V-tolerant pins.

## Purchase With Discount

Get the full Bluetooth guide with a discounted price — enroll via the link above.

