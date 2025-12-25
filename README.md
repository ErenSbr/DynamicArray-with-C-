# 📂 C++ Dynamic Array Implementation (OOP Assignment)

![Language](https://img.shields.io/badge/language-C++-blue)
![Course](https://img.shields.io/badge/Course-Object%20Oriented%20Programming-green)
![Status](https://img.shields.io/badge/Status-Completed-success)

Bu proje, C++ kullanılarak standart `std::vector` yapısına benzer, dinamik olarak boyutlanabilen bir dizi sınıfı ve bu sınıftan türetilmiş özel yapıları içerir. **Nesne Yönelimli Programlama (OOP)** prensipleri olan Kalıtım (Inheritance), Kapsülleme (Encapsulation) ve Çok Biçimlilik (Polymorphism) kullanılarak geliştirilmiştir.
Proje üç ana sınıftan oluşmaktadır:
1. `DynamicArray` (Temel Sınıf)
Dinamik bellek yönetimi kullanılarak oluşturulmuş, boyutu otomatik artan/azalan dizi yapısı.
- **Özellikler:** Ekleme, silme, indeksleme operatörü (`[]`), kapasite yönetimi.
- **Bellek Yönetimi:** Deep Copy (Derin Kopyalama), Copy Constructor ve Destructor ile bellek sızıntıları önlenmiştir.
- 
2. `SortedArray` (Türetilmiş Sınıf)
`DynamicArray` sınıfından miras alır. Elemanları her zaman **sıralı** tutar.
- **Algoritma:** Eklenen elemanlar uygun konuma yerleştirilir (Insertion Logic).
- **Arama:** `binarySearch` algoritması ile $O(\log n)$ karmaşıklığında arama yapar.
 3. `UniqueArray` (Türetilmiş Sınıf)
`DynamicArray` sınıfından miras alır. Dizi içerisinde **tekrar eden elemanlara izin vermez**.
- **Mantık:** `push` işlemi öncesinde elemanın varlığı `contains` metodu ile kontrol edilir.
Öğrenci No	GitHub Kullanıcı Adı
```bash
ErenSbr
enesd-r
