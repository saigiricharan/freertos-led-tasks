# 🔴🟢 FreeRTOS Dual LED Task Demo — ESP32

Demonstrates **FreeRTOS multitasking** on ESP32 using two independent tasks that blink LEDs at different rates — simultaneously, without interfering with each other.

## 📌 Key Concepts
- FreeRTOS task creation with `xTaskCreatePinnedToCore()`
- Task scheduling and `vTaskDelay()` (non-blocking delay)
- Pinning tasks to specific CPU cores (ESP32 is dual-core)
- Real-time concurrent execution

## 🛠️ Hardware / Simulator
| Component | Pin |
|-----------|-----|
| Red LED   | GPIO 2 |
| Green LED | GPIO 4 |
| Resistors (220Ω) | In series with each LED |

> ✅ **Simulate this on [Wokwi](https://wokwi.com)** — no hardware needed!

## 🔁 How It Works
```
Task 1 (Core 0) → Red LED blinks every 500ms
Task 2 (Core 1) → Green LED blinks every 1000ms
Both run SIMULTANEOUSLY — this is real multitasking!
```

## 🚀 How to Run
### On Wokwi (Recommended)
1. Go to [wokwi.com](https://wokwi.com)
2. Create new project → Select **ESP32**
3. Add 2 LEDs (GPIO 2 and GPIO 4) with 220Ω resistors
4. Paste code from `src/main.cpp`
5. Click ▶ Play

### On Real ESP32
1. Open Arduino IDE
2. Install **ESP32 board package** (if not done)
3. Open `src/main.cpp`
4. Select board: **ESP32 Dev Module**
5. Upload

## 📊 Expected Output (Serial Monitor)
```
FreeRTOS Dual Task Demo Starting...
Both tasks created. Running...
```
Red LED blinks at 2Hz, Green LED at 1Hz — both simultaneously.

## 📚 What I Learned
- FreeRTOS is used in industrial embedded systems for real-time task management
- `vTaskDelay()` yields CPU time to other tasks (unlike `delay()` which blocks)
- Each task gets its own stack — stack overflow is a real concern in RTOS

## 🔗 Simulate Online
[Open in Wokwi](https://wokwi.com) — Create project and paste the code

## 👤 Author
**S. Sai Giri Charan** — Embedded Software Engineer  
[LinkedIn](https://linkedin.com/in/sai-giri-charan-017570281) | [GitHub](https://github.com/saigiri-charan)
