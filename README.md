# Arduino MotoGP Viewer dengan Remote Infrared dan LCD

Proyek ini adalah sistem penampil data MotoGP menggunakan Arduino UNO yang dikendalikan dengan remote infrared. Data pembalap dan tim MotoGP ditampilkan pada layar LCD 16x2.

## Fitur Utama

- **Pengendalian Remote Infrared**: Menggunakan remote infrared untuk navigasi data
  - Tombol "1": Lanjut ke pembalap berikutnya (NEXT)
  - Tombol "2": Kembali ke pembalap sebelumnya (PREVIOUS)
  
- **Tampilan LCD**: Menampilkan nama tim dan pembalap MotoGP pada layar LCD I2C 16x2

- **Indikator LED**: 
  - LED di pin 3 (LED_PIN) blink saat tombol NEXT ditekan
  - LED di pin 5 (LED_2_PIN) blink saat tombol PREVIOUS ditekan

- **Data MotoGP**: Daftar 5 pembalap dan tim:
  - Ducati Lenovo - F. Bagnaia
  - Repsol Honda - M. Marquez
  - Monster Yamaha - F. Quartararo
  - Red Bull KTM - B. Binder
  - Aprilia Racing - A. Espargaro

## Hardware yang Dibutuhkan

- Arduino UNO
- Modul IR Receiver (TSOP4838 atau sejenisnya)
- Layar LCD I2C 16x2 (Alamat I2C: 0x27)
- 2 buah LED
- 2 buah Resistor (220Ω untuk LED)
- Remote Infrared
- Kabel dan Breadboard

## Koneksi Pin

| Komponen | Pin Arduino |
|----------|------------|
| IR Receiver | Pin 2 |
| LED 1 | Pin 3 |
| LED 2 | Pin 5 |
| LCD SDA | A4 (I2C) |
| LCD SCL | A5 (I2C) |

## Library yang Digunakan

- **IRremote** (v4.7.1) - untuk membaca signal remote infrared
- **LiquidCrystal_I2C** (v1.1.4) - untuk mengontrol LCD I2C

## Setup & Installation

1. Buka project ini di PlatformIO
2. Dependencies akan otomatis diunduh sesuai dengan konfigurasi di `platformio.ini`
3. Upload code ke Arduino UNO
4. Koneksikan hardware sesuai dengan pin configuration

## Cara Menggunakan

1. Nyalakan sistem
2. LCD akan menampilkan pembalap pertama
3. Gunakan remote infrared:
   - Tekan tombol "1" untuk melihat pembalap berikutnya
   - Tekan tombol "2" untuk kembali ke pembalap sebelumnya
4. LED akan berkedip sebagai indikator setiap kali tombol ditekan
5. Data akan berulang kembali ke awal setelah pembalap terakhir

## Monitoring Serial

Untuk melihat debug information:
- Buka Serial Monitor dengan baud rate **9600**
- Setiap kali tombol remote ditekan, akan terlihat command yang diterima
- Output: "NEXT ditekan" atau "PREVIOUS ditekan"

## Platform

- **Board**: Arduino UNO
- **Platform**: Atmel AVR
- **Framework**: Arduino

## Lisensi

Bebas digunakan untuk keperluan edukatif dan personal.
