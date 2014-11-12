/* 
    Bluetooth  Örneği - 1
    Terminal Üzerinden LED Kontrol Uygulaması
 
    Arduino Bluetooth Eklentisi ile Arduino 
    kartının üzerindeki LEDleri terminal aracılığıyla
    kontrol ediyoruz.

   Sanal seri port oluşturmak için Software Serial 
   kütüphanesi kullanıldı.
 
 */
// SoftwareSerial kütüphanesini kodlarımızaa dahil ediyoruz.
#include <SoftwareSerial.h>

// Sanal seri portumuzu oluşturuyoruz(D2 ve D3)
SoftwareSerial mySerial(2,3);

// LEDlerimizin bağlı olduğu dijital pinleri tanımlıyoruz.
const int led1 = 9;
const int led2 = 8;

int gelen;

void setup()
{
  // Seri haberleşmeyi başlatıyoruz.
  Serial.begin(9600);
  
  // Bluetooth seri haberlşemesini başlatıyoruz.
  mySerial.begin(9600);
  
  // LEDlerimizi dijital çıkış olarak tanımlıyoruz.
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}


void loop()
{
  // Herhangi bir karakter gelmiş mi?
  if(mySerial.available()>0){
    // Karakter gelmişse gelen karakteri okuyoruz.
    gelen=mySerial.read();
    // Eğer gelen karakter A ise LED 1'i yakıyoruz ve ekrana "LED1 yandi" mesajını veriyoruz.
    if(gelen=='A'){
      digitalWrite(led1, HIGH);
      mySerial.println("LED1 yandi");
    }
    
    // Eğer gelen karakter D ise LED 2'yi yakıyoruz ve ekrana "LED2 yandi" mesajını veriyoruz.
    if(gelen == 'D'){
      digitalWrite(led2, HIGH);
      mySerial.println("LED2 yandi");
    }
    
    // Eğer gelen karakter S ise LED 1'i söndürüyoruz ve ekrana "LED1 sondu" mesajını veriyoruz.
    if(gelen == 'S'){
      digitalWrite(led1, LOW);
      mySerial.println("LED1 sondu");
    }
    
    // Eğer gelen karakter F ise LED 2'yi söndürüyoruz ve ekrana "LED2 sondu" mesajını veriyoruz.
    if(gelen == 'F'){
      digitalWrite(led2, LOW);
      mySerial.println("LED2 sondu");
    }
  }
}

