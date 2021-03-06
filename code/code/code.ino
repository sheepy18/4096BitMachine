
#include "musical.h"

using namespace musical;


//const char* test7{ "(16.05,21)(18.02,21)(20.23,21)(21.43,21)(24.05,21)(27.00,21)(30.31,21)" };
//const char* test100{ "(16.05,41)(18.02,41)(20.23,41)(21.43,41)(24.05,41)(27.00,41)(30.31,41)(32.32,41)(36.04,41)(40.45,41)(16.05,41)(18.02,41)(20.23,41)(21.43,41)(24.05,41)(27.00,41)(30.31,41)(32.32,41)(36.04,41)(40.45,41)(16.05,41)(18.02,41)(20.23,41)(21.43,41)(24.05,41)(27.00,41)(30.31,41)(32.32,41)(36.04,41)(40.45,41)(16.05,41)(18.02,41)(20.23,41)(21.43,41)(24.05,41)(27.00,41)(30.31,41)(32.32,41)(36.04,41)(40.45,41)(16.05,41)(18.02,41)(20.23,41)(21.43,41)(24.05,41)(27.00,41)(30.31,41)(32.32,41)(36.04,41)(40.45,41)(16.05,41)(18.02,41)(20.23,41)(21.43,41)(24.05,41)(27.00,41)(30.31,41)(32.32,41)(36.04,41)(40.45,41)(16.05,41)(18.02,41)(20.23,41)(21.43,41)(24.05,41)(27.00,41)(30.31,41)(32.32,41)(36.04,41)(40.45,41)(16.05,41)(18.02,41)(20.23,41)(21.43,41)(24.05,41)(27.00,41)(30.31,41)(32.32,41)(36.04,41)(40.45,41)(16.05,41)(18.02,41)(20.23,41)(21.43,41)(24.05,41)(27.00,41)(30.31,41)(32.32,41)(36.04,41)(40.45,41)(16.05,41)(18.02,41)(20.23,41)(21.43,41)(24.05,41)(27.00,41)(30.31,41)(32.32,41)(36.04,41)(40.45,41)" };
//const char* tes3{"(64.22,31(72.08,31(80.91,31(85.72,31(96.22,31(108.00,31(121.23,31(128.43,31"};
const char* bella{ "(60.61,41(80.91,41(90.82,41(96.22,41(80.91,40(80.91,31(0.00,41(60.61,41(80.91,41(90.82,41(96.22,41(80.91,40(80.91,31(0.00,41(60.61,41(80.91,41(90.82,41(96.22,31(85.72,41(80.91,41(96.22,31(90.82,41(80.91,41(121.23,31(121.23,31(121.23,41(121.23,41(108.00,41(121.23,41(128.43,41(128.43,40(128.43,31(0.00,41(128.43,41(121.23,41(108.00,41(128.43,41(121.23,40(121.23,31(0.00,41(121.23,41(108.00,41(96.22,41(90.82,31(121.23,31(96.22,31(90.82,31(80.91,21" };
Sample t1{ bella, 9};
Sample t2{ bella, 9};

void printTone( Sample s )
{
  Tone * buff = s.getBuffer();
  for( int i = 0; i < s.getMaxPosTones(); ++i)
  {
    Tone t = buff[i];
    Serial.print("(");
    Serial.print(t.getFreq());
    Serial.print(",");
    Serial.print(t.getNoteLength());
    Serial.println(")");
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin( 9600 );
  Tone::quarterLength = 2.f / 4;
  t1.play();
  t2.play();
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
