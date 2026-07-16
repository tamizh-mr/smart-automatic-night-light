# smart-automatic-night-light
ESP32-based automatic night light using PIR motion + LDR sensors
# 💡 Smart Automatic Night Light

> 🧪 This is a mini project — built for learning and hands-on practice with ESP32, sensors, and IoT logic.

> An ESP32-based automatic lighting system that turns ON only at night when motion is detected — saving power by staying OFF during the day and when no one is around.

---

## ⚙️ Working

- 🌞 **Daytime** → LED stays OFF (regardless of motion)
- 🌙 **Nighttime + Motion Detected** → LED turns ON
- 🌙 **Nighttime + No Motion** → LED turns OFF after a few seconds
- Combines a light sensor (LDR) and a motion sensor (PIR) so it only activates when both conditions are right

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

## 🚀 Applications

- 🛣️ Street lighting
- 🪜 Staircase lighting
- 🌳 Garden lighting
- 🚪 Home entrance lighting

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

## 🚀 How to Set Up

1. Clone this repo
```bash
git clone https://github.com/tamizh-mr/smart-automatic-night-light
```

2. Open the `.ino` file in Arduino IDE

3. Install the ESP32 board package in Arduino IDE (if not already installed)

4. Connect components as per the wiring:
   - PIR sensor → GPIO pin (define in code)
   - LDR module → GPIO pin (define in code)
   - LED → GPIO pin (with 220Ω resistor)

5. Upload the code to your ESP32 and power it on ✅

---

## 👤 Author

**Tamilmurugan M R**
- GitHub: [@tamizh-mr](https://github.com/tamizh-mr)

---

*Built with ESP32 + PIR + LDR*
