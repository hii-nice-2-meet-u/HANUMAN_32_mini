#include <HANUMAN_32_mini.h>

//- ================================================================================================

void setup() 
{
  Serial.begin(115200);

  Serial.println("Press switch to start");
  swA();
}

void loop() 
{
  if (is_swA() == 1){
    Serial.println("ON");
  } else {
    Serial.println("OFF");
  }

}

//- ================================================================================================
