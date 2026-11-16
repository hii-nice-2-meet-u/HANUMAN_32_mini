#include <HANUMAN_32_mini.h>

// in_f() = in() with filter, for sensors that flicker on IN1-IN6 (e.g. ARTRON IR-Distance)
// tune before #include if needed:
//   #define IN_F_ZERO_PCT 95

//- ================================================================================================

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  Serial.print("IN1 : ");
  Serial.print(in_f(1));
  Serial.print("   IN2 : ");
  Serial.print(in_f(2));
  Serial.print("   IN3 : ");
  Serial.print(in_f(3));
  Serial.print("   IN4 : ");
  Serial.print(in_f(4));
  Serial.print("   IN5 : ");
  Serial.print(in_f(5));
  Serial.print("   IN6 : ");
  Serial.print(in_f(6));
  Serial.print("   IN7 : ");
  Serial.print(in_f(7));
  Serial.print("   IN8 : ");
  Serial.print(in_f(8));
  Serial.print("   IN9 : ");
  Serial.print(in_f(9));
  Serial.print("   IN10 : ");
  Serial.println(in_f(10));
  delay(100);
}

//- ================================================================================================
