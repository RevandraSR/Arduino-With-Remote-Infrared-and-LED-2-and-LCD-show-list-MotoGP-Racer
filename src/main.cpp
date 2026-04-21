#include <Arduino.h>

#include <IRremote.hpp>
#include <LiquidCrystal_I2C.h>

// --- Konfigurasi Pin ---
const int RECV_PIN = 2;
const int LED_PIN = 3;
const int LED_2_PIN = 5;

// --- Command Remote ---
#define CMD_KEY_1 0x30  // Tombol "1" = NEXT
#define CMD_KEY_2 0x18  // Tombol "2" = PREVIOUS

// --- LCD ---
LiquidCrystal_I2C lcd(0x27, 16, 2);

// --- Data MotoGP ---
const int jumlahData = 5;

String tim[jumlahData] = {
  "Ducati Lenovo",
  "Repsol Honda",
  "Monster Yamaha",
  "Red Bull KTM",
  "Aprilia Racing"
};

String pembalap[jumlahData] = {
  "F. Bagnaia",
  "M. Marquez",
  "F. Quartararo",
  "B. Binder",
  "A. Espargaro"
};

// Index saat ini
int indexData = 0;

// --- Fungsi tampil LCD ---
void tampilData() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Tim " + tim[indexData]);
  lcd.setCursor(0, 1);
  lcd.print(pembalap[indexData]);
}

void setup() {

  Serial.begin(9600);
  delay(200);
  Serial.println("Sistem MotoGP Viewer Siap!");

  // IR
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK);

  // LED
  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_2_PIN, OUTPUT);

  // LCD
  lcd.init();
  lcd.backlight();

  tampilData(); // tampil awal
}

void loop() {

  if (IrReceiver.decode()) {

    Serial.print("Command: ");
    Serial.println(IrReceiver.decodedIRData.command, HEX);

    // --- Tombol NEXT ---
    if (IrReceiver.decodedIRData.command == CMD_KEY_1) {
      Serial.println("NEXT ditekan");

      indexData++;
      if (indexData >= jumlahData) {
        indexData = 0; // balik ke awal
      }

      tampilData();

      // indikator LED
      digitalWrite(LED_PIN, HIGH);
      delay(150);
      digitalWrite(LED_PIN, LOW);
    }

    // --- Tombol PREVIOUS ---
    else if (IrReceiver.decodedIRData.command == CMD_KEY_2) {
      Serial.println("PREVIOUS ditekan");

      indexData--;
      if (indexData < 0) {
        indexData = jumlahData - 1; // balik ke akhir
      }

      tampilData();

      // indikator LED
      digitalWrite(LED_2_PIN, HIGH);
      delay(150);
      digitalWrite(LED_2_PIN, LOW);
    }

    IrReceiver.resume();
  }
}