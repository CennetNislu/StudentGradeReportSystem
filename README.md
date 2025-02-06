🎓 ÖĞRENCİ NOT RAPORU SİSTEMİ
📌 Projenin İçeriği
Bu proje, C++ kullanılarak öğrencilerin not durumlarını işleyen bir sistem geliştirme amacı taşır. Sistem, bir dosyadan öğrenci bilgilerini okuyarak, her öğrenci için bir Ogrenci sınıfı oluşturur ve nesne yönelimli programlama (OOP) ilkelerine uygun şekilde çalışır. Öğrencilerin ders bilgilerini, kredi saatlerini ve harç durumlarını işleyerek GPA hesaplama, sıralama ve raporlama gibi işlevleri yerine getirir.

📝 Proje Açıklaması
Öğrencilerin dönem ortası not raporlarını hazırlamak istemektedir. Ancak öğrencilerin bazıları harç ücretini ödemediğinden dolayı, not raporlarında bazı özel durumlar oluşmaktadır:
Harç ödemesi yapılmış öğrencilerin tüm dersleri, kredi saatleri ve not ortalamaları (GPA) hesaplanarak raporlanır.
Harç ödemesi yapılmamış öğrenciler için notlar gizlenir ve harç borcu bilgisi rapora eklenir.
Program, öğrenci verilerini giriş dosyasından (input.txt) okur ve işleyerek çıktı dosyası (output.txt) oluşturur.

⚙️ Kullanılan Yöntemler ve Fonksiyonlar
✔️ Sınıf Yapısı (Class): Öğrencileri temsil eden Ogrenci ve dersleri temsil eden Kurs sınıfları oluşturuldu.
✔️ Kalıtım (Inheritance): Ogrenci sınıfı, Kisi sınıfından türetilerek öğrenci bilgileri genişletildi.
✔️ Birleşim (Composition): Ogrenci sınıfı, öğrenciye ait dersleri bir dizi (Kurs nesneleri) olarak içerecek şekilde tasarlandı.
✔️ Dosya İşlemleri: ifstream ve ofstream kullanılarak öğrenci bilgileri dosyadan okundu ve rapor olarak yazdırıldı.
✔️ Ortalama Not Hesaplama: getGpa() fonksiyonu ile öğrencilerin kredi saatlerine göre ağırlıklı not ortalaması hesaplandı.
✔️ Sıralama Algoritması: Öğrencinin dersleri, ders numarasına göre sıralandı.
✔️ Harç Kontrolü: Öğrencinin harç ödeyip ödemediği kontrol edilerek, ödemeyenlerin notları gizlendi ve borç bilgileri raporlandı.

Bu proje sayesinde, C++ ile nesne yönelimli programlama (OOP), dosya işlemleri ve veri işleme konularında deneyim kazandık. Ayrıca:
Gerçek dünya problemlerini kodla çözmeyi, veri işlemenin ve formatlı çıktı üretmenin önemini, dinamik bellek yönetimi ve nesne yönetimi konularını öğrendik.
Bu proje, C++ ile yazılım geliştirme pratiğimizi artırırken, ekip çalışmasının önemini de pekiştirdi.

