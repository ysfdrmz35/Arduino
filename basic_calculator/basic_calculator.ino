#include <LCD5110_Basic.h>//Ekran kütüphanesini ekliyoruz

LCD5110 ekran(8,9,10,11,12);//ekranın pinlerini belirtiyoruz
extern uint8_t SmallFont[];//SmallFont fontunu ekliyoruz
extern uint8_t MediumNumbers[];//MediumNumbers fontunu ekliyoruz
extern uint8_t BigNumbers[];//BigNumbers fontunu ekliyoruz

void setup() {
  pinMode(5,OUTPUT);//5. pini çıkış olarak belirliyoruz (beyaz ışık)
  pinMode(3,OUTPUT);//3. pini çıkış olarak belirliyoruz (kırmızı ışık)
  pinMode(2,INPUT_PULLUP);//2. pini giriş olarak belirliyoruz (buton)
  pinMode(A0,INPUT);//A0 pinini giriş olarak belirliyoruz (potansiyometre)
  pinMode(A1,INPUT);//A1 pinini giriş olarak belirliyoruz (potansiyometre)
  pinMode(A2,INPUT);//A2 pinini giriş olarak belirliyoruz (potansiyometre)
  pinMode(7,OUTPUT);//7. pini çıkış olarak belirliyoruz (ekran arkaplan ışığı)
  digitalWrite(7,HIGH);//7.pine güç veriyoruz
  ekran.InitLCD();//ekranı çalıştırıyoruz
  ekran.setContrast(70);// ekran kontrastını 70 olarak ayarlıyoruz
}

void loop() {
  
    ekran.clrScr();//ekranı temizliyoruz
    ekran.setFont(SmallFont);//fontu SmallFont olarak belirliyoruz
    ekran.print("Hesap Makinesi", CENTER,0);//ekrana yazımızı yazdırıyoruz
    digitalWrite(5,HIGH);//5.pine güç veriyoruz
    
    
    int ideger = analogRead(A0);// ilk değeri (ideger) A0 potansiyometresinden aldığımız değere eşitliyoruz
    ideger = map(ideger,0,1023,0,100);//ideger'in aralığını düzenliyoruz
    ekran.printNumI(ideger,LEFT,16);// ekrana ilk değeri yazdırıyoruz
    
    int sdeger = analogRead(A2);// son değeri (sdeger) A2 potansiyometresinden aldığımız değere eşitliyoruz
    sdeger = map(sdeger,0,1023,0,100);//sdeger'in aralığını düzenliyoruz
    ekran.printNumI(sdeger,RIGHT,16);// ekrana son değeri yazdırıyoruz
  
    int islem = analogRead(A1);// işlemi (islem) A1 potansiyometresinden aldığımız değere eşitliyoruz
    islem = map(islem,0,1023,0,3);//islem'in aralığını düzenliyoruz
    if (islem == 0){ekran.print("+",CENTER,16);}
    if (islem == 1){ekran.print("-",CENTER,16);}
    if (islem == 2){ekran.print("*",CENTER,16);}
    if (islem == 3){ekran.print("/",CENTER,16);}
    // üstteki 4 satırda değere göre ekrana işareti yazdırıyoruz 
    
    if (digitalRead(2) == LOW)// eğer butona basılıyorsa...
    {
      ekran.setFont(MediumNumbers);//fontu MediumNumbers olarak ayarla...
      if (islem == 0){ekran.printNumI(ideger + sdeger,CENTER,32);}
      if (islem == 1){ekran.printNumI(ideger - sdeger,CENTER,32);}
      if (islem == 2){ekran.printNumI(ideger * sdeger,CENTER,32);}
      if (islem == 3){ekran.printNumI(ideger / sdeger,CENTER,32);}
      //(yukardaki 4 satırda) islem değerine göre sonucu ekrana yazdır...
      digitalWrite(3,HIGH);//3. pine güç ver.
       
    }
    delay(500);//bekleme yapıyoruz
    digitalWrite(3,LOW);//3. pine giden gücü kesiyoruz.
    
    
    delay(200);//bekleme yapıyoruz
  
}
