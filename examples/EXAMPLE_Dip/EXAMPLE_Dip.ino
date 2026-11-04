#include <HANUMAN_32_mini.h>

//- ================================================================================================

void setup() 
{
  Serial.begin(115200);
}

void loop() 
{
  Serial.print("Dip Value : ");
  Serial.print(read_dip());
  Serial.print("   Dip CH1 : ");
  Serial.print(read_dip(1));
  Serial.print("   Dip CH2 : ");
  Serial.print(read_dip(2));
  Serial.print("   Dip CH3 : ");
  Serial.println(read_dip(3));

}

//- ================================================================================================
