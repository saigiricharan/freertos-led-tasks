/**
 * Project: FreeRTOS Dual LED Task Demo
 * Board: ESP32 (Wokwi Simulator)
 * Author: S. Sai Giri Charan
 * Description: Demonstrates FreeRTOS multitasking on ESP32.
 *              Two independent tasks blink LEDs at different rates.
 */

#include <Arduino.h>

#define RED_LED   2
#define GREEN_LED 4

// Task 1: Blink Red LED every 500ms
void redLedTask(void *pvParameters) {
  pinMode(RED_LED, OUTPUT);
  while (1) {
    digitalWrite(RED_LED, HIGH);
    vTaskDelay(500 / portTICK_PERIOD_MS);
    digitalWrite(RED_LED, LOW);
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}

// Task 2: Blink Green LED every 1000ms
void greenLedTask(void *pvParameters) {
  pinMode(GREEN_LED, OUTPUT);
  while (1) {
    digitalWrite(GREEN_LED, HIGH);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    digitalWrite(GREEN_LED, LOW);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void setup() {
  Serial.begin(115200);
  Serial.println("FreeRTOS Dual Task Demo Starting...");

  // Create Task 1 on Core 0
  xTaskCreatePinnedToCore(
    redLedTask,   // Task function
    "RedLED",     // Task name
    1000,         // Stack size (bytes)
    NULL,         // Parameters
    1,            // Priority
    NULL,         // Task handle
    0             // Core 0
  );

  // Create Task 2 on Core 1
  xTaskCreatePinnedToCore(
    greenLedTask,
    "GreenLED",
    1000,
    NULL,
    1,
    NULL,
    1             // Core 1
  );

  Serial.println("Both tasks created. Running...");
}

void loop() {
  // FreeRTOS handles everything — loop is intentionally empty
  vTaskDelay(portMAX_DELAY);
}
