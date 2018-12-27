#include "musical.h"


namespace musical
{
  float Tone::quarterLength = 1;

  void Tone::play( uint8_t pin )
  {
    playForSec( noteLength * quarterLength, pin );
  }
  
  void Tone::buildFrequency( uint8_t pin, unsigned long wait )
  {
    digitalWrite( pin, amp );
    delay( wait / 2 );
    digitalWrite( pin, LOW );
    delay( wait / 2 );
  }
  
  void Tone::playForSec( const MilliSec maxS, const uint8_t pin )
  {
     const unsigned long wait = ( 1 / freq) * 1000;

    for( unsigned long i = 0; i <= maxS - interrupt; i = i + wait )
    {
      buildFrequency( pin, wait );
    }
    delay( interrupt );
  }

  void Tone::play( uint8_t pin, Tone* parallelTones, uint8_t parallelTonesNum )
  {
    playForSec( noteLength * quarterLength, pin, parallelTones, parallelTonesNum );
  }
  
  void Tone::playForSec( const MilliSec maxS, const uint8_t pin, Tone* parallelTones, uint8_t parallelTonesNum )
  {
     const unsigned long wait = ( 1 / freq) * 1000;

    for( unsigned long i = 0; i <= maxS - interrupt; i = i + wait )
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

  void Sample::play()
  {
    loadTones();
    for( uint8_t i = 0; i < 10 && i < maxPosTones; ++i)
    {
      buff[i].play( pin );
    }
    if( song[currentPos] != '\0') 
    {
      play();
    }
  }

  unsigned long exp10( uint8_t e )
  {
    if( e == 0)
      return 1;
    unsigned long f = 10;
    for( uint8_t i = 0; i < e; ++i)
      f *= 10;
    return f;
  }

  void Sample::loadTones()
  {
    uint8_t t = 0;

    while( t < 10 && song[currentPos] !=  '\0')
    {
      if( song[currentPos] == '(' )
      {
         uint8_t j = 0;
         float freq = 0.f;
         while( song[currentPos + j + 1] != '.')
            ++j;
            
         if( j == 3)
            freq += ((song[currentPos + 1] - '0') * 100) + ((song[currentPos + 2] - '0') * 10 ) + (song[currentPos + 3] - '0') - 1;
         if( j == 2)
            freq += ((song[currentPos + 1] - '0') * 10 ) + (song[currentPos + 2] - '0');
         else
            freq += (song[currentPos + 1] - '0');
        
         currentPos += j + 1;
         freq += (((song[currentPos + 1] - '0') * 10 + (song[currentPos + 2] - '0'))) / 100.f;

         currentPos += 3;
         unsigned long noteLength = 0;
         switch( song[ currentPos + 1] )
         {
            case '1':
              noteLength = 1000 * 4;
              break;
            case '2':
              noteLength = 1000 * 2;
              break;
            case '3':
              noteLength = 1000;
              break;
            case '4':
              noteLength = 500;
              break;
            case '5':
              noteLength = 250;
              break;
            case '6':
              noteLength = 125;
              break;
         }

         buff[ t ].change( (freq <= 0.5) ? 1 : freq, (freq <= 0.5) ? 0 : 1,  (song[ currentPos + 2] == '0')? 0 : 50, noteLength );
         
         ++t;
      }
      ++currentPos;
    }
    maxPosTones = t;
  }
}
