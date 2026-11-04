#include <HANUMAN_32_mini.h>

//- ================================================================================================

void setup() 
{
  Serial.begin(115200);
}

void loop() 
{
  Serial.print("IN1 : ");
  Serial.print(in(1));
  Serial.print("   IN2 : ");
  Serial.print(in(2));
  Serial.print("   IN3 : ");
  Serial.print(in(3));
  Serial.print("   IN4 : ");
  Serial.print(in(4));
  Serial.print("   IN5 : ");
  Serial.print(in(5));
  Serial.print("   IN6 : ");
  Serial.print(in(6));
  Serial.print("   IN7 : ");
  Serial.print(in(7));
  Serial.print("   IN8 : ");
  Serial.print(in(8));
  Serial.print("   IN9 : ");
  Serial.print(in(9));
  Serial.print("   IN10 : ");
  Serial.println(in(10));
}

//- ================================================================================================
