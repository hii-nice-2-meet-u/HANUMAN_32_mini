#include <HANUMAN_32_mini.h>

//- ================================================================================================

void setup()
{
}

void loop()
{
	swOK(); // Wait for OK switch press

	motor(1, 50); // Motor 1 | 50% - forward
	motor(2, 50); // Motor 2 | 50% - forward
	delay(500);

	ao(); // Stop [ Break motor ]
	delay(500);

	motor(1, -50); // Motor 1 | 50% - backward
	motor(2, -50); // Motor 2 | 50% - backward
	delay(500);

	ao(); // Stop [ Free motor ]
	delay(500);

	fd(50); // Forward       | 50%
	delay(500);

	bk(50); // Backward      | 50%
	delay(500);

	tl(50); // Turn  Left    | 50% [ M1 stop, M2 forward ]
	delay(500);

	tr(50); // Turn  Right   | 50% [ M1 forward, M2 stop ]
	delay(500);

	sl(50); // Spin  Left    | 50% [ M1 backward, M2 forward ]
	delay(500);

	sr(50); // Spin  Right   | 50% [ M1 forward, M2 backward ]
	delay(500);
}

//- ================================================================================================
