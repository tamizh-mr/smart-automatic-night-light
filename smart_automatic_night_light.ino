#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// ---------- Pin Definitions ----------
const int PIR = 18;
const int LDR = 19;
const int RELAY = 23;
const int BUZZER = 5;
const int LED = 2;

// ---------- Config ----------
const unsigned long delayTime = 10000; // 10 seconds after last motion before turning off

// NOTE: Some relay modules are ACTIVE-LOW (LOW = ON, HIGH = OFF).
// If your bulb behaves opposite to what's expected, swap HIGH/LOW below
// for RELAY_ON / RELAY_OFF.
const int RELAY_ON  = HIGH;
const int RELAY_OFF = LOW;

// NOTE: Some LDR modules output HIGH when dark, others output LOW when dark.
// Test yours — if day/night detection seems reversed, flip this.
const int LDR_DARK_VALUE = HIGH;

unsigned long lastMotionTime = 0;

// Track system state so we only update the LCD when something actually changes
// (prevents constant lcd.clear() flicker every loop)
enum SystemState { STATE_NONE, STATE_ACTIVE, STATE_DAY, STATE_NO_MOTION };
SystemState lastState = STATE_NONE;

void setup()
{
  Serial.begin(115200);

  pinMode(PIR, INPUT);
  pinMode(LDR, INPUT);
  pinMode(RELAY, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);

  digitalWrite(RELAY, RELAY_OFF);
  digitalWrite(BUZZER, LOW);
  digitalWrite(LED, LOW);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("SMART NIGHT");
  lcd.setCursor(0, 1);
  lcd.print("LIGHT SYSTEM");
  delay(3000);
  lcd.clear();
}

void loop()
{
  bool motion = digitalRead(PIR);
  bool dark = (digitalRead(LDR) == LDR_DARK_VALUE);

  Serial.print("Motion: ");
  Serial.print(motion);
  Serial.print("  Dark: ");
  Serial.println(dark);

  if (motion == HIGH && dark)
  {
    // Motion detected at night -> turn everything ON
    digitalWrite(RELAY, RELAY_ON);
    digitalWrite(LED, HIGH);
    digitalWrite(BUZZER, HIGH);
    lastMotionTime = millis();

    if (lastState != STATE_ACTIVE)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Motion Found");
      lcd.setCursor(0, 1);
      lcd.print("Bulb ON");
      lastState = STATE_ACTIVE;
    }
  }
  else
  {
    if (millis() - lastMotionTime >= delayTime)
    {
      digitalWrite(RELAY, RELAY_OFF);
      digitalWrite(LED, LOW);
      digitalWrite(BUZZER, LOW);

      if (!dark)
      {
        // Daytime
        if (lastState != STATE_DAY)
        {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("DAY TIME");
          lcd.setCursor(0, 1);
          lcd.print("Bulb OFF");
          lastState = STATE_DAY;
        }
      }
      else
      {
        // Nighttime, no motion
        if (lastState != STATE_NO_MOTION)
        {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("No Motion");
          lcd.setCursor(0, 1);
          lcd.print("Bulb OFF");
          lastState = STATE_NO_MOTION;
        }
      }
    }
  }

  delay(200);
}
