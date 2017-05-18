#include <LCD5110_Basic.h>

LCD5110 ekran(8,9,10,11,12);
extern uint8_t SmallFont[];
extern uint8_t MediumNumbers[];
extern uint8_t BigNumbers[];

const int r = 3;
const int g = 5;
const int b = 6;




void setup() {
  pinMode(r,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(A0,INPUT);
  pinMode(2, INPUT_PULLUP); 
  ekran.clrScr(),
  ekran.InitLCD();
  ekran.setContrast(70);
  

}

void loop() {
  digitalWrite(7,HIGH);
  ekran.setFont(SmallFont);
  ekran.print("COLOUR",CENTER,8);

  int renk = analogRead(A0);
  renk = map(renk,0,1023,0,11);

  if (renk == 0)
  {
    ekran.clrRow(3);
    ekran.print("Red",CENTER,24);
    if (digitalRead(2) == LOW ){
      analogWrite(r,0);
      analogWrite(g,0);
      analogWrite(b,0);
      analogWrite(r,255);}
  }
  

if (renk == 4)
  {
    ekran.clrRow(3);
    ekran.print("Green",CENTER,24);
    if (digitalRead(2) == LOW ){
      analogWrite(r,0);
      analogWrite(g,0);
      analogWrite(b,0);
      analogWrite(g,255);}
  }

 if (renk == 8)
  {
    ekran.clrRow(3);
    ekran.print("Blue",CENTER,24);
    if (digitalRead(2) == LOW ){
      analogWrite(r,0);
      analogWrite(g,0);
      analogWrite(b,0);
      analogWrite(b,255);}
  }

  if (renk == 10)
  {
    ekran.clrRow(3);
    ekran.print("Magenta",CENTER,24);
    if (digitalRead(2) == LOW ){
      analogWrite(r,0);
      analogWrite(g,0);
      analogWrite(b,0);
      analogWrite(r,255);
      analogWrite(b,255);}
  }

  if (renk == 6)
  {
    ekran.clrRow(3);
    ekran.print("Cyan",CENTER,24);
    if (digitalRead(2) == LOW ){
      analogWrite(r,0);
      analogWrite(g,0);
      analogWrite(b,0);
      analogWrite(g,255);
      analogWrite(b,255);}
  }

  if (renk == 5)
  {
    ekran.clrRow(3);
    ekran.print("Yellow",CENTER,24);
    if (digitalRead(2) == LOW ){
      analogWrite(r,0);
      analogWrite(g,0);
      analogWrite(b,0);
      analogWrite(r,255);
      analogWrite(g,255);}
  }

  if (renk == 1)
  {
    ekran.clrRow(3);
    ekran.print("Orange",CENTER,24);
    if (digitalRead(2) == LOW ){
      analogWrite(r,0);
      analogWrite(g,0);
      analogWrite(b,0);
      analogWrite(r,255);
      analogWrite(g,125);}
  }

  if (renk == 3)
  {
    ekran.clrRow(3);
    ekran.print("Spring Green",CENTER,24);
    if (digitalRead(2) == LOW ){
      analogWrite(r,0);
      analogWrite(g,0);
      analogWrite(b,0);
      analogWrite(r,125);
      analogWrite(g,255);}
  }

  if (renk == 5)
  {
    ekran.clrRow(3);
    ekran.print("Turquoise",CENTER,24);
    if (digitalRead(2) == LOW ){
      analogWrite(r,0);
      analogWrite(g,0);
      analogWrite(b,0);
      analogWrite(g,255);
      analogWrite(b,1255);}
  }

  if (renk == 7)
  {
    ekran.clrRow(3);
    ekran.print("Ocean",CENTER,24);
    if (digitalRead(2) == LOW ){
      analogWrite(r,0);
      analogWrite(g,0);
      analogWrite(b,0);
      analogWrite(g,125);
      analogWrite(b,255);}
  }

  if (renk == 9)
  {
    ekran.clrRow(3);
    ekran.print("Violet",CENTER,24);
    if (digitalRead(2) == LOW ){
      analogWrite(r,0);
      analogWrite(g,0);
      analogWrite(b,0);
      analogWrite(r,125);
      analogWrite(b,255);}
  }

  if (renk == 11)
  {
    ekran.clrRow(3);
    ekran.print("Raspberry",CENTER,24);
    if (digitalRead(2) == LOW ){
      analogWrite(r,0);
      analogWrite(g,0);
      analogWrite(b,0);
      analogWrite(r,255);
      analogWrite(b,125);}
  }

  delay(200);
  }
