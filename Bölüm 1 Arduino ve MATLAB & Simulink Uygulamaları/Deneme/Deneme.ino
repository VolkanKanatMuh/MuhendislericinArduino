/* 
    TFT LCD Ekran Örneği - 1
    Potansiyometre Uygulaması
 
    Arduino ile analog okuduğumuz potansiyometre
   değerini Arduino etkileşimli TFT LCD ekranda gözlemliyoruz
 
 */

// Arduino TFT LCD kütüphanesini ekliyoruz.
#include <TFT.h>  

// Arduino ile ekran haberleşmesi için SPI kütüphanesini ekliyoruz.
#include <SPI.h>

// Arduino Uno modeli için kullanacağımız pinleri tanımlıyoruz.
#define cs   10
#define dc   9
#define rst  8

// TFT kütüphanesine ait nesneyi oluştuyoruz.
TFT ekran = TFT(cs, dc, rst);

char pot[4];

void setup() {

  // Grafik LCD kullanılan her uygulamanın başına bu satırı yazıyoruz.
  ekran.begin();

  // Ekranı siyah bir arka plan ile temizliyoruz.
  ekran.background(0, 0, 0);

  // Ekrana yazdıracağımız sabit ifadenin rengini beyaz olarak tanımlıyoruz.
  ekran.stroke(255, 255, 255);

  // Ekrana yazdıracağımız sabit ifadenin font değerini belirtiyoruz.
  ekran.setTextSize(2);

  // Sabit ifadeyi ekranın sol üst köşesine yazdırıyoruz.
  ekran.text("Pot Degeri :\n ", 0, 0);
  ekran.setTextSize(5);
}

void loop() {

  // Potansiyometrenin değerini okuyoruz.
  String potDegeri = String(analogRead(A0));

  // Okunan değeri dizi tipine çeviriyoruz.
  potDegeri.toCharArray(pot, 4);

  // Potansiyometre değerinin rengini beyaz olarak tanımlıyoruz.
  ekran.stroke(255, 255, 255);

  // Ekrana potansiyometre değerini yazdııyoruz.
  ekran.text(pot, 0, 20);

  // 250 ms bekliyoruz.
  delay(250);

  ekran.stroke(0, 0, 0);
  ekran.text(pot, 0, 20);
}

