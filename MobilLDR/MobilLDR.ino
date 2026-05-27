#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// =========================
// RGB
// =========================
#define LED_R 9
#define LED_G 10
#define LED_B 11

// =========================
// FAN
// =========================
#define FAN_PIN 5

// =========================
// BUZZER
// =========================
#define BUZZER_PIN 6

String data = "";

// =========================
// STATUS
// =========================
bool redStatus = false;
bool greenStatus = false;
bool blueStatus = false;

bool fanStatus = false;
bool buzzerStatus = false;

void setup() {
  Serial.begin(9600);

  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(FAN_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("SMART CONTROL");
  lcd.setCursor(0,1);
  lcd.print("SYSTEM READY");

  delay(2000);
  lcd.clear();
  updateOutput();
}

void loop() {
  if (Serial.available()) {
    data = Serial.readStringUntil('\n');
    data.trim();

    // =========================
    // RGB LOGIC (Anti-Mix)
    // =========================
    if(data == "RED_ON"){
      if(!greenStatus && !blueStatus) redStatus = true;
    }
    else if(data == "GREEN_ON"){
      if(!redStatus && !blueStatus) greenStatus = true;
    }
    else if(data == "BLUE_ON"){
      if(!redStatus && !greenStatus) blueStatus = true;
    }
    else if(data == "LED_OFF"){
      // Matikan semua warna
      redStatus = false;
      greenStatus = false;
      blueStatus = false;
    }

    // =========================
    // FAN LOGIC
    // =========================
    else if(data == "FAN_ON"){
      fanStatus = true;
    }
    else if(data == "FAN_OFF"){
      fanStatus = false;
    }

    // =========================
    // BUZZER LOGIC
    // =========================
    else if(data == "BUZZ_ON"){
      buzzerStatus = true;
    }
    else if(data == "BUZZ_OFF"){
      buzzerStatus = false;
    }

    // Update Output Hardware
    updateOutput();
  }
}

// ======================================
// UPDATE OUTPUT
// ======================================
void updateOutput(){
  // Update RGB
  digitalWrite(LED_R, redStatus);
  digitalWrite(LED_G, greenStatus);
  digitalWrite(LED_B, blueStatus);

  // Update FAN
  if(fanStatus){
    analogWrite(FAN_PIN, 180);
  } else {
    analogWrite(FAN_PIN, 0);
  }

  // Update BUZZER
  if(buzzerStatus){
    tone(BUZZER_PIN, 1500);
  } else {
    noTone(BUZZER_PIN);
  }

  // Update LCD
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("R:"); lcd.print(redStatus ? "1" : "0");
  lcd.print(" G:"); lcd.print(greenStatus ? "1" : "0");
  lcd.print(" B:"); lcd.print(blueStatus ? "1" : "0");

  lcd.setCursor(0,1);
  lcd.print("F:"); lcd.print(fanStatus ? "ON " : "OFF");
  lcd.print(" BZ:"); lcd.print(buzzerStatus ? "ON" : "OFF");
}