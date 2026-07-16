# 💡 Smart Automatic Night Light

> An ESP32-based automatic lighting system that turns ON only at night when motion is detected — saving power by staying OFF during the day and when no one is around.

> 🧪 This is a mini project — built for learning and hands-on practice with ESP32, sensors, and IoT logic.

![Status](https://img.shields.io/badge/Status-Completed-brightgreen)
![Hardware](https://img.shields.io/badge/Hardware-ESP32-blue)
![License](https://img.shields.io/badge/License-MIT-yellow)

---

## ✨ Features

- Automatic day/night detection using LDR
- Motion-based activation using PIR sensor
- Auto shut-off after 10 seconds of no motion
- Live status display on 16x2 LCD
- Buzzer alert on motion detection
- Relay-controlled AC bulb output

---

## ⚙️ Working

- 🌞 **Daytime** → Bulb stays OFF (regardless of motion)
- 🌙 **Nighttime + Motion Detected** → Bulb turns ON, buzzer sounds, LCD shows status
- 🌙 **Nighttime + No Motion** → Bulb turns OFF after 10 seconds
- Combines a light sensor (LDR) and a motion sensor (PIR) so it only activates when both conditions are right

---

## 🔄 Project Flow

Since hardware photos aren't available yet, here's the logic flow of the system:

1. System starts and continuously reads the PIR motion sensor and LDR light sensor
2. Checks: is it dark **and** is motion detected?
   - **No** → stays idle (day time or no motion) — bulb OFF
   - **Yes** → turns ON the relay, LED, and buzzer; LCD shows "Motion Found"
3. If no motion is detected for 10 seconds while active, everything turns OFF automatically
4. This check repeats continuously every ~200ms

---

## 🛠️ Hardware Used

1. ESP32 Development Board
2. PIR Motion Sensor (HC-SR501)
3. LDR Light Sensor Module
4. LED (5 mm)
5. 220 Ω Resistor
6. Breadboard
7. Male-to-Male Jumper Wires
8. Micro USB Cable (for ESP32 programming and power supply)
9. Laptop/PC with Arduino IDE
10. Relay Module (5V)
11. AC Bulb with Bulb Holder
12. Buzzer Module
13. 16×2 LCD Display with I2C Module
14. ESP32 Power Adapter (5V)

---

## 🔌 Pin Connections

| Component      | ESP32 Pin |
|-----------------|-----------|
| PIR Sensor      | GPIO 18   |
| LDR Module      | GPIO 19   |
| Relay Module    | GPIO 23   |
| Buzzer          | GPIO 5    |
| LED             | GPIO 2    |
| LCD (I2C)       | SDA/SCL (default I2C pins) |

---

## 🧰 Tech Stack

`ESP32` `Arduino IDE` `C++` `I2C` `PIR Sensor` `LDR`

---

## 🚀 Applications

- 🛣️ Street lighting
- 🪜 Staircase lighting
- 🌳 Garden lighting
- 🚪 Home entrance lighting

---

## 🔮 Future Improvements

- Add Wi-Fi/Telegram alerts on prolonged motion detection
- Solar-powered standalone version
- Adjustable sensitivity via mobile app
- Data logging of motion events with timestamps

---

## 🚀 How to Set Up

1. Clone this repo
```bash
git clone https://github.com/tamizh-mr/smart-automatic-night-light
```

2. Open the `.ino` file in Arduino IDE

3. Install the ESP32 board package in Arduino IDE (if not already installed)

4. Connect components as per the wiring table above

5. Upload the code to your ESP32 and power it on ✅

---

## 👤 Author

**Tamilmurugan M R**
- GitHub: [@tamizh-mr](https://github.com/tamizh-mr)

---

*Built with ESP32 + PIR + LDR*