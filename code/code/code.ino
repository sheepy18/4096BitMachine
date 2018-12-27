
#include "musical.h"

using namespace musical;

Tone c;
Tone d;
Tone e;
Tone f;
Tone g;
Tone a;
Tone h;
Tone c1;
Tone d1;
Tone e1;
Tone f1;
Tone g1;
Tone a1;
Tone h1;
Tone c2;

unsigned long l = 500;

void changesetup()
{
  c.change( 16.05, 1, 20, 2*l );
  d.change( 18.02, 1, 20, 2*l );
  e.change( 20.23, 1, 20, 2*l );
  f.change( 21.43, 1, 20, 2*l );
  g.change( 24.05, 1, 20, 2*l );
  a.change( 27.00, 1, 20, 2*l );
  h.change( 30.31, 1, 20, 2*l );
  c1.change( 32.11, 1, 20, l );
  d1.change( 36.04, 1, 20, l );
  e1.change( 40.45, 1, 20, l );
  f1.change( 42.86, 1, 20, l );
  g1.change( 48.11, 1, 20, l );
  a1.change( 54.00, 1, 20, l );
  h1.change( 60.61, 1, 20, l );
  c2.change( 64.22, 1, 20, l );
}

void playtest()
{
  c.play(9);
  d.play(9);
  e.play(9);
  f.play(9);
  g.play(9);
  a.play(9);
  h.play(9);
  c1.play(9);
  d1.play(9);
  e1.play(9);
  f1.play(9);
  g1.play(9);
  a1.play(9);
  h1.play(9);
  c2.play(9);
}

void setup() {
  // put your setup code here, to run once:
  pinMode( 9, OUTPUT );
  Serial.begin( 9600 );
  changesetup();
  unsigned long start = millis();  
  playtest();
  unsigned long e = millis() - start ;
  Serial.println( e);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
