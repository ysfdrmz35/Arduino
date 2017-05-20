#include <LCD5110_Basic.h>

LCD5110 ekran(8,9,10,11,12);
extern uint8_t SmallFont[];
extern uint8_t s[];
extern uint8_t batman[];
extern uint8_t aquaman[];
extern uint8_t cyborg[];
extern uint8_t flash[];
extern uint8_t greenlantern[];
extern uint8_t superman[];
extern uint8_t wonderwoman[]; 

void setup() {
  pinMode(A0,INPUT);
  pinMode(13,INPUT_PULLUP);
  pinMode(7,OUTPUT);
  digitalWrite(7,HIGH);
  ekran.InitLCD();
  ekran.setContrast(70);

}

void loop() {


  int  secenek = analogRead(A0);
  secenek = map(secenek,0,1023,0,6);

  ekran.setFont(SmallFont);
  

  if (secenek == 0)
  {
    ekran.print("Justice League",CENTER,0);
    ekran.print("Superheroes'",CENTER,8);
    ekran.print("Logos",CENTER,16);
    ekran.print("    Batman   ",CENTER,32);
    
    if (digitalRead(13) == LOW)
      {
        ekran.clrScr();
        ekran.drawBitmap(0,0,batman,84,48);
         delay(1000);
        ekran.clrScr();
      }
    
  }

  if (secenek == 1)
  {
    ekran.print("Justice League",CENTER,0);
    ekran.print("Superheroes'",CENTER,8);
    ekran.print("Logos",CENTER,16);
    ekran.print("   Superman   ",CENTER,32);
    
    if (digitalRead(13) == LOW)
      {
        ekran.clrScr();
        ekran.drawBitmap(0,0,superman,84,48);
         delay(1000);
        ekran.clrScr();
      }
    
  }


  if (secenek == 2)
  {
    ekran.print("Justice League",CENTER,0);
    ekran.print("Superheroes'",CENTER,8);
    ekran.print("Logos",CENTER,16);
    ekran.print("    Aquaman    ",CENTER,32);
    
    if (digitalRead(13) == LOW)
      {
        ekran.clrScr();
        ekran.drawBitmap(0,0,aquaman,84,48);
         delay(1000);
        ekran.clrScr();
      }
   
  }

  if (secenek == 3)
  {
    ekran.print("Justice League",CENTER,0);
    ekran.print("Superheroes'",CENTER,8);
    ekran.print("Logos",CENTER,16);
    ekran.print("    Cyborg    ",CENTER,32);
    
    if (digitalRead(13) == LOW)
      {
        ekran.clrScr();
        ekran.drawBitmap(0,0,cyborg,84,48);
         delay(1000);
        ekran.clrScr();
      }
    
  }

  if (secenek == 4)
  {
    ekran.print("Justice League",CENTER,0);
    ekran.print("Superheroes'",CENTER,8);
    ekran.print("Logos",CENTER,16);
    ekran.print("    Flash    ",CENTER,32);
    
    if (digitalRead(13) == LOW)
      {
        ekran.clrScr();
        ekran.drawBitmap(0,0,flash,84,48);
         delay(1000);
        ekran.clrScr();
      }
    
  }

  if (secenek == 5)
  {
    ekran.print("Justice League",CENTER,0);
    ekran.print("Superheroes'",CENTER,8);
    ekran.print("Logos",CENTER,16);
    ekran.print("Green Lantern",CENTER,32);
    
    if (digitalRead(13) == LOW)
      {
        ekran.clrScr();
        ekran.drawBitmap(0,0,greenlantern,84,48);
         delay(1000);
        ekran.clrScr();
      }
   
  }

  if (secenek == 6)
  {
   
    ekran.print("Justice League",CENTER,0);
    ekran.print("Superheroes'",CENTER,8);
    ekran.print("Logos",CENTER,16);
    ekran.print(" Wonder Woman ",CENTER,32);

    if (digitalRead(13) == LOW)
      {
        ekran.clrScr();
        ekran.drawBitmap(0,0,wonderwoman,84,48);
        delay(1000);
        ekran.clrScr();
      }
    
    
  }

















  
  delay(200);
}
