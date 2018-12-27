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
    
      friend class Sample;
      static float quarterLength;
    
      Tone() : freq{ 0 }, amp{ 0 }, interrupt{ 20 }, noteLength{ 1 } {}
      Tone( Hz freqArg ) : freq{ freqArg }, amp{ 1 }, interrupt{ 20 } {}
      
      void change( const Hz fr, const Volt am, const MilliSec in, MilliSec nLength );
      void play( const uint8_t pin );
     
      //multiple tones parallel
      void play( const uint8_t pin, Tone* parallelTones, uint8_t parallelTonesNum);
      
      Hz getFreq() { return freq; }
      Volt getAmp() { return amp; }
      MilliSec getNoteLength() { return noteLength; }
      MilliSec getInterrupt() { return interrupt; }
      
    private:
      Hz freq;
      Volt amp; 
      MilliSec noteLength; 
      MilliSec interrupt; 

      void playForSec( const MilliSec MaxS, const uint8_t pin );
      
      //multiple tones parallel
      void playForSec( const MilliSec MaxS, const uint8_t pin, Tone* parallelTones, uint8_t parallelTonesNum );
      void buildFrequency( const uint8_t pin, const unsigned long wait );  
  };

  class Sample
  {
    public:
      Sample( const char* songArg, const uint8_t pinArg ) : song{ songArg }, pin{ pinArg } { pinMode( pin, OUTPUT ); }    
      void play();
      
      Tone* getBuffer(){ return buff; }
      uint8_t getMaxPosTones() { return maxPosTones; }

    private:
      const char* song;
      const uint8_t pin;      
      unsigned long currentPos;
      uint8_t maxPosTones;
      Tone buff[ 10 ];

      void loadTones();      
  };
}

#endif
