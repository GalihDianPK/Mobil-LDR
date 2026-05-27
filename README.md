🚗 LDR Light Following Car using Arduino + AVR Assembly

Mobil robot sederhana berbasis Arduino Uno yang menggunakan 2 sensor LDR untuk mendeteksi cahaya dan menggerakkan motor DC menggunakan driver L298N.
Project ini menggabungkan pemrograman C/C++ dan AVR Assembly untuk membaca sensor secara low-level.

📸 Preview Project
✨ Features
Menggunakan 2 sensor LDR
Kontrol motor DC dengan driver L298N
Pembacaan sensor menggunakan AVR Assembly
Debounce sensor agar pembacaan stabil
Robot bergerak mengikuti arah cahaya
🛠 Components Used
Arduino Uno
L298N Motor Driver
2x LDR Sensor Module
Chassis Robot Car
2x DC Motor + Wheel
Battery / Power Supply
Jumper Wires
⚙️ How It Works
Sensor kiri mendeteksi cahaya → mobil bergerak ke satu arah
Sensor kanan mendeteksi cahaya → mobil bergerak ke arah sebaliknya
Jika tidak ada cahaya terdeteksi → motor berhenti

Assembly digunakan untuk membaca pin digital secara langsung dari register AVR (PINB) agar lebih cepat dan low-level.
