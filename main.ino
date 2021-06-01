#include <SoftwareSerial.h> // Sanal Serial Kütüphanesi

#define Bluetooth_RX 6  // Bluetooth Pinleri
#define Bluetooth_TX 7

SoftwareSerial Bluetooth(Bluetooth_TX,Bluetooth_RX); // RX,TX

#define RGB_Kirmizi 8 // RGB Led Bağlantısı
#define RGB_Yesil 9
#define RGB_Mavi 10

char GelenData; // Bluetooth'tan Gelen Veri

void setup()
{
 Serial.begin(9600);  // 9600 Bps 

 Bluetooth.begin(9600);

 pinMode(RGB_Kirmizi,OUTPUT);  // RGB Çıkış Olarak Atanır.
 pinMode(RGB_Yesil,OUTPUT); 
 pinMode(RGB_Mavi,OUTPUT); 

 digitalWrite(RGB_Kirmizi,HIGH); // Başlangıçta RGB Sönük Olsun
 digitalWrite(RGB_Yesil,HIGH);
 digitalWrite(RGB_Mavi,HIGH);

}

void loop() 
{

if(Bluetooth.available())    // Eğer Bluetoothtan Veri Gelirse Bu Veriyi GelenData Değişkenine Ata.
  {
     GelenData = Bluetooth.read(); 
     Serial.println(GelenData); 
  }

  switch(GelenData)
  {
    case 'K' : digitalWrite(RGB_Kirmizi,LOW); digitalWrite(RGB_Yesil,HIGH); digitalWrite(RGB_Mavi,HIGH); break; // Kırmızı
    case 'Y' : digitalWrite(RGB_Kirmizi,HIGH); digitalWrite(RGB_Yesil,LOW); digitalWrite(RGB_Mavi,HIGH); break; // Yeşil
    case 'M' : digitalWrite(RGB_Kirmizi,HIGH); digitalWrite(RGB_Yesil,HIGH); digitalWrite(RGB_Mavi,LOW); break; // Mavi
    case 'P' : digitalWrite(RGB_Kirmizi,LOW); digitalWrite(RGB_Yesil,HIGH); digitalWrite(RGB_Mavi,LOW); break; // Pembe
    case 'S' : digitalWrite(RGB_Kirmizi,LOW); digitalWrite(RGB_Yesil,LOW); digitalWrite(RGB_Mavi,HIGH); break; // Sari
    case 'B' : digitalWrite(RGB_Kirmizi,LOW); digitalWrite(RGB_Yesil,LOW); digitalWrite(RGB_Mavi,LOW); break; // Beyaz
    case 'C' : digitalWrite(RGB_Kirmizi,HIGH); digitalWrite(RGB_Yesil,LOW); digitalWrite(RGB_Mavi,LOW); break; // Cyan
  }

}
