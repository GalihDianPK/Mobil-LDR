# Proyek Mobil LDR (Hybrid C & Assembly)

Proyek ini adalah sistem kendali robot mobil berbasis Arduino yang menggunakan pendekatan *Hybrid Programming*. Sistem ini menggabungkan efisiensi **AVR Assembly** untuk pembacaan sensor *low-level* dengan kemudahan **C++** untuk logika sistem utama.

## 📋 Fitur Utama
* **Optimasi Assembly:** Pembacaan pin sensor dilakukan langsung pada register `PINB` menggunakan bahasa Assembly AVR untuk akses yang lebih presisi.
* **Sistem Debouncing:** Algoritma *software debouncing* untuk meminimalisir *noise* pada sensor LDR.
* **Kendali Motor:** Logika kontrol motor yang responsif berdasarkan input sensor.

## 🔌 Konfigurasi Pin
| Komponen | Pin Arduino |
| :--- | :--- |
| **LDR 1** | PB1 (Pin 9) |
| **LDR 2** | PB2 (Pin 10) |
| **Motor IN1** | Pin 7 |
| **Motor IN2** | Pin 5 |
| **Motor IN3** | Pin 6 |
| **Motor IN4** | Pin 8 |

## 🛠️ Struktur Kode
* **`main.ino`**: Mengatur logika utama, inisialisasi pin, dan sistem *debouncing*.
* **`sensor.S`**: Berisi fungsi Assembly (`LDR_DigitalRead` & `LDR2_DigitalRead`) untuk membaca status logika sensor langsung dari hardware.

## 🚀 Cara Penggunaan
1. Pastikan Arduino IDE telah terpasang.
2. Tempatkan file kode C (`.ino`) dan file Assembly (`.S`) dalam satu folder yang sama.
3. Hubungkan Arduino ke komputer.
4. Unggah (Upload) kode ke board Arduino Anda.
5. Pastikan skema kabel sesuai dengan tabel konfigurasi pin di atas.

## 📝 Lisensi
Proyek ini bersifat *open-source*. Silakan digunakan untuk tujuan edukasi atau pengembangan lebih lanjut.
