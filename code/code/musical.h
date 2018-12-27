#ifndef MUSICAL_HH
#define MUSICAL_HH


#include "Arduino.h"

namespace musical
{
  class Tone
  {     
    private:   
      using Hz = float;
      using Volt = float;
      using MilliSec = unsigned long;
    
    public:
      static MilliSec quarterLength;
    
      Tone() : freq{ 0 }, amp{ 0 }, interrupt{ 20 }, noteLength{ 1 } {}
      Tone( Hz freqArg ) : freq{ freqArg }, amp{ 1 }, interrupt{ 20 } {}
      
      void change( const Hz fr, const Volt am, const MilliSec in, MilliSec nLength );
      void play( uint8_t pin );
      
    private:
      Hz freq;
      Volt amp; 
      MilliSec noteLength; 
      MilliSec interrupt; 

      void playForSec( MilliSec MaxS, uint8_t pin );
      void buildFrequency( uint8_t pin, unsigned long wait );  
  }; 
}

#endif
