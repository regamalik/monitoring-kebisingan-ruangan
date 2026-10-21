# 🔊 Monitoring Kebisingan Ruangan

![Platform](https://img.shields.io/badge/Platform-Mikrokontroler-black) ![Bahasa](https://img.shields.io/badge/Bahasa-C%2B%2B-00599C?logo=cplusplus&logoColor=white)

Sistem **monitoring kebisingan ruangan** berbasis mikrokontroler. Alat membaca tingkat kebisingan lingkungan melalui sensor suara, lalu memberikan indikasi sesuai ambang batas yang ditentukan.

## ✨ Fitur

- Pembacaan level kebisingan secara real-time.
- Indikasi/alert ketika kebisingan melewati ambang batas.
- Dua versi kode: `SourceCode.ino` (versi awal pengembangan) dan `FINISHER_.ino` (versi final).

## 📁 Struktur

```
monitoring-kebisingan-ruangan/
├── firmware/
│   ├── SourceCode.ino     # Versi awal pengembangan
│   └── FINISHER_.ino      # Versi final
└── docs/
    ├── alat-bahan.jpg     # Foto komponen yang digunakan
    └── flowchart.jpg      # Diagram alur kerja sistem
```

## 🚀 Cara Menggunakan

1. Siapkan Arduino IDE sesuai board yang digunakan.
2. Buka `firmware/FINISHER_.ino` (versi final).
3. Sesuaikan pin dan ambang batas kebisingan dengan rangkaian Anda.
4. Upload ke board dan amati output melalui serial monitor.

## 📄 Dokumentasi

Lihat foto perakitan alat dan flowchart sistem pada folder [`docs/`](docs/).
