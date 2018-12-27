#include "musical.h"


namespace musical
{
  Tone::MilliSec Tone::quarterLength = 1000;

  void Tone::play( uint8_t pin )
  {
    playForSec( noteLength, pin );
  }
  
  void Tone::buildFrequency( uint8_t pin, unsigned long wait )
  {
    digitalWrite( pin, HIGH );
    delay( wait / 2 );
    digitalWrite( pin, LOW );
    delay( wait / 2 );
  }
  
  void Tone::playForSec( MilliSec maxS, uint8_t pin )
  {
     unsigned long wait = ( 1 / freq) * 1000;

    for( unsigned long i = 0; i <= maxS; i = i + wait )
    {
      buildFrequency( pin, wait );
    }
    delay( interrupt );
  }
  
  void Tone::change( const Tone::Hz fr, const Tone::Volt am, const Tone::MilliSec in, MilliSec nLength )
  {
    freq = fr;
    amp = am;
    interrupt = in;
    noteLength = nLength;
  }
}
