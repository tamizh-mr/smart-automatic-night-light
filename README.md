# smart-automatic-night-light
ESP32-based automatic night light using PIR motion + LDR sensors
# 💡 Smart Automatic Night Light

> An ESP32-based automatic lighting system that turns ON only at night when motion is detected — saving power by staying OFF during the day and when no one is around.

---

## ⚙️ Working

- 🌞 **Daytime** → LED stays OFF (regardless of motion)
- 🌙 **Nighttime + Motion Detected** → LED turns ON
- 🌙 **Nighttime + No Motion** → LED turns OFF after a few seconds
- Combines a light sensor (LDR) and a motion sensor (PIR) so it only activates when both conditions are right

---

## 🛠️ Hardware Used

| Component                     | Purpose                              |
|--------------------------------|---------------------------------------|
| ESP32 Development Board        | Main microcontroller                  |
| PIR Motion Sensor (HC-SR501)   | Detects human/animal movement         |
| LDR Light Sensor Module        | Detects ambient light (day/night)     |
| LED (5mm)                      | Output light                          |
| 220 Ω Resistor                 | Current limiting for LED              |
| Breadboard                     | Prototyping                           |
| Male-to-Male Jumper Wires      | Connections                           |
| Micro USB Cable                | Programming + power for ESP32         |
| Arduino IDE                    | Programming environment               |

### 🔧 Planned Upgrades
- Relay Module (5V) + AC Bulb — control real room/street lighting
- Buzzer Module — optional alert on motion
- 16×2 LCD with I2C — live status display
- Dedicated 5V Power Adapter — standalone operation

---

## 🚀 Applications

- 🛣️ Street lighting
- 🪜 Staircase lighting
- 🌳 Garden lighting
- 🚪 Home entrance lighting

---

## 📸 Project Photos

*(Add your circuit/setup photos here — e.g. `photos/circuit.jpg`)*

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
