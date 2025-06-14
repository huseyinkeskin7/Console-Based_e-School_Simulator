# Console-Based_e-School_Simulator
# Türkçe
Bu proje, C dili ile yazılmış, terminal üzerinden çalışan bir öğrenci bilgi ve yönetim sistemidir. Proje, kullanıcı girişiyle çalışan ve öğrenci bilgilerini .txt dosyaları üzerinde tutan bir e-okul simülasyonu işlevi görür.
🧩 Temel Özellikler:
    🔐 Kullanıcı ve admin girişi (admin / 0000)
    👥 Öğrenci ekleme / silme (sınıf dosyaları: 9A.txt, 10B.txt vs.)
    📋 Sınıf ve öğrenci bilgilerini sıralı listeleme
    🔎 Öğrenci adına/soyadına göre arama
    👨‍🏫 Kullanıcı (öğretmen) ekleme/silme (users.txt)
    📁 Tüm veriler düz metin dosyalarında tutulur
🗂️ Dosya Yapısı:
    text.c → Ana program ve menü sistemi
    add_remove.c → Öğrenci/öğretmen ekleme ve silme işlevleri
    disp.c → Listeleme ve arama işlemleri
    users.txt → Giriş yapan kullanıcı verileri
    *.txt → Sınıf dosyaları (örnek: 11A.txt, 12B.txt)
    
# English
This is a console-based student information system written in C, designed to simulate a basic version of a school management platform (e.g., Turkey’s "e-Okul").
🧩 Key Features:
    🔐 Login system (admin: admin / 0000)
    👥 Add/remove students (stored in class-specific .txt files)
    📋 List and sort class data
    🔎 Search students by name and/or surname
    👨‍🏫 Add/remove users (teachers) via users.txt
    📁 All data is stored in plain text files for simplicity
🗂️ File Overview:
    text.c → Main loop and user interface
    add_remove.c → Handles adding/removing students or users
    disp.c → Handles display and search features
    users.txt → Authentication data
    *.txt → Class files (e.g., 9A.txt, 10B.txt)
