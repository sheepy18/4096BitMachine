
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

void setup() {
  // put your setup code here, to run once:
  pinMode( 9, OUTPUT );
  c.change( 16.05, 1, 20, 1000 );
  d.change( 18.02, 1, 20, 1000 );
  e.change( 20.23, 1, 20, 1000 );
  f.change( 21.43, 1, 20, 1000 );
  g.change( 24.05, 1, 20, 1000 );
  a.change( 27.00, 1, 20, 1000 );
  h.change( 30.31, 1, 20, 1000 );
  c1.change( 32.11, 1, 20, 1000 );
  c.play(9);
  d.play(9);
  e.play(9);
  f.play(9);
  g.play(9);
  a.play(9);
  h.play(9);
  c1.play(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
