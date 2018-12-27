#include "musical.h"


namespace musical
{
  Tone::MilliSec Tone::quarterLength = 1;

  void Tone::play( uint8_t pin )
  {
    playForSec( noteLength, pin );
  }
  
  void Tone::buildFrequency( uint8_t pin )
  {
    uint8_t wait = (freq / 2) + ( (int) freq % 2);
    digitalWrite( pin, HIGH );
    delay( wait );
    digitalWrite( pin, LOW );
    delay( wait );
  }
  
  void Tone::playForSec( MilliSec maxS, uint8_t pin )
  {
    unsigned long start = millis();

    while( millis() - start <= maxS )
    {
      buildFrequency( pin );
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
