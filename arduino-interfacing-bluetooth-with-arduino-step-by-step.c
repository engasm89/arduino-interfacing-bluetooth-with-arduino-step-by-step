/*
 * Course: Arduino Interfacing Bluetooth With Arduino Step By Step
 * Platform: Arduino
 * Author: Ashraf S A AlMadhoun
 * Purpose: Auto-generated metadata block to document the learning goals.
 * Notes: Auto-generated metadata block (2025-11-18)
 */

/*
 * Course: Arduino Interfacing Bluetooth With Arduino Step By Step
 * Platform: Arduino
 * Author: Ashraf S A AlMadhoun
 * Purpose: Auto-generated metadata block to document the learning goals.
 * Notes: Auto-generated metadata block (2025-11-18)
 */

#include <stdio.h> // Serial
#include <string.h> // Command parsing

#define OUTPUT 1 // Output
#define INPUT 0 // Input
#define HIGH 1 // High
#define LOW 0 // Low

// Pins for LED and HC-05 Bluetooth (Serial simulated)
static const int LED_PIN = 13; // Onboard LED

// Stubs
void pinMode(int pin, int mode) { /* set */ } // Configure
void digitalWrite(int pin, int val) { /* write */ } // Write
void delay(int ms) { /* wait */ } // Delay
void Serial_begin(long baud) { printf("Serial start %ld\n", baud); } // Serial
int Serial_available(void) { return 0; } // Available bytes
char Serial_read(void) { return '\0'; } // Read one char
void Serial_println(const char *s) { printf("%s\n", s); } // Println

char cmd[32]; // Command buffer
int cmd_len = 0; // Length

void setup(void) { // Initialize
  pinMode(LED_PIN, OUTPUT); // LED output
  digitalWrite(LED_PIN, LOW); // LED off
  Serial_begin(9600); // Bluetooth serial
  Serial_println("Bluetooth Control Ready"); // Status
}

void process(void) { // Process commands
  if (cmd_len == 0) return; // Nothing
  cmd[cmd_len] = '\0'; // Terminate
  if (!strcmp(cmd, "LED ON")) { // LED on
    digitalWrite(LED_PIN, HIGH); // Set LED
    Serial_println("LED ON"); // Feedback
  } else if (!strcmp(cmd, "LED OFF")) { // LED off
    digitalWrite(LED_PIN, LOW); // Set LED
    Serial_println("LED OFF"); // Feedback
  } else { // Unknown
    Serial_println("Unknown"); // Feedback
  } // End parsing
  cmd_len = 0; // Reset
}

void loop(void) { // Main loop
  while (Serial_available()) { // Read stream
    char c = Serial_read(); // Read char
    if (c == '\n' || c == '\r') { // End of line
      process(); // Process command
    } else if (cmd_len < (int)sizeof(cmd) - 1) { // Space left
      cmd[cmd_len++] = c; // Append
    } // End buffer check
  } // End serial read
  delay(50); // Idle delay
}

// Main routine: orchestrates the arduino interfacing bluetooth with arduino step by step scenario
int main(void) { // Entry
  setup(); // Init
  for (int i = 0; i < 10; ++i) { // Simulated cycles
    loop(); // Execute
  } // End
  return 0; // Exit
}

