#include <LCD5110_Basic.h>//Ekran kütüphanesini ekliyoruz
LCD5110 ekran(8,9,10,11,12);//ekranın pinlerini belirtiyoruz
extern uint8_t SmallFont[];//SmallFont fontunu ekliyoruz
extern uint8_t MediumNumbers[];//MediumNumbers fontunu ekliyoruz
extern uint8_t BigNumbers[];//BigNumbers fontunu ekliyoruz


void setup() {
 pinMode(A1,INPUT);//A1 pinini giriş olarak ayarlıyoruz (Potansiyometre) 
 pinMode(2,OUTPUT);//2. pini çıkış olarak ayarlıyoruz (Buzzer)
 pinMode(A0,INPUT);//A0 pinini giriş olarak ayarlıyoruz (Nem Ölçer)
 pinMode(7,OUTPUT);//7. pini çıkış olarak belirliyoruz (ekran arkaplan ışığı)
 digitalWrite(7,HIGH);//7.pine güç veriyoruz
 ekran.InitLCD();//ekranı çalıştırıyoruz
 ekran.setContrast(70);// ekran kontrastını 70 olarak ayarlıyoruz
}

void loop() {
  ekran.clrScr();//ekranı temizliyoruz
  ekran.setFont(SmallFont);//fontu SmallFont olarak belirliyoruz
  ekran.print("NEM ORANI",CENTER,16);// ekrana yazı yazdırıyoruz
  
   int deger = analogRead(A0);// Nem ölçerden aldığımız değeri deger'e eşitliyoruz
   deger = map(deger,0,1023,0,100);//deger'i aralığını düzenliyoruz
   ekran.print("o",20,32);
   ekran.print("/", 27, 32);
   ekran.print("/", 20, 40);
   ekran.print("o", 27, 40);
   //yukardaki 4 satırda ekrana % işaretini yazdırıyoruz
   ekran.setFont(MediumNumbers);//fontu MediumNumbers olarak ayarlıyoruz
   ekran.printNumI(100 - deger,42,32);//ekrana nem oranını yazdırıyoruz
    int onoff = analogRead(A1);//onoff sayısını potansiyometreden gelen değere eşitliyoruz
   onoff = map(onoff,0,1023,0,3);//onoff sayısının aralığını düzenliyoruz

    if (onoff < 1)//eğer onoff değeri 1 den küçükse (off)
{
  ekran.enableSleep();// ekranı uyku moduna al
  digitalWrite(7,LOW);// 7.pine giden gücü kes
  digitalWrite(2,LOW);//2.pine giden gücü kes
  }
else // değilse (on)
{
  ekran.disableSleep();// ekranı uyku modundan çıkar
  digitalWrite(7,HIGH);//7.pine güç ver
  digitalWrite(2,HIGH);//2.pine güç ver


   if (deger > 90)// eğer nem oranı %10'nun altındaysa 
   {digitalWrite(2,HIGH);//2.pine güç ver
   ekran.setFont(SmallFont);//fontu SmallFont olarak ayarla
   ekran.print("Lutfen Sulayin",CENTER,0)// ekrana yazı yazdır
    }
   else {digitalWrite(2,LOW);}//%10 un üstündeyse 2.pine giden gücü kes
  }
   
       
   
   delay(200);//bekleme
  
}
