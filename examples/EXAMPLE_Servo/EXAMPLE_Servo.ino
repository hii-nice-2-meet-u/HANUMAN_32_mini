#include <HANUMAN_32_mini.h>

//- ================================================================================================

void setup()
{
}

void loop()
{
	swOK(); // Wait for OK switch press

	servo(1, 0); // Servo 1 | 0 degree
	servo(2, 0); // Servo 2 | 0 degree
	servo(3, 0); // Servo 3 | 0 degree
	servo(4, 0); // Servo 4 | 0 degree
	servo(5, 0); // Servo 5 | 0 degree
	servo(6, 0); // Servo 6 | 0 degree
	delay(500);

	servo(1, 90); // Servo 1 | 90 degree
	servo(2, 90); // Servo 2 | 90 degree
	servo(3, 90); // Servo 3 | 90 degree
	servo(4, 90); // Servo 4 | 90 degree
	servo(5, 90); // Servo 5 | 90 degree
	servo(6, 90); // Servo 6 | 90 degree
	delay(500);

	servo(1, 180); // Servo 1 | 180 degree
	servo(2, 180); // Servo 2 | 180 degree
	servo(3, 180); // Servo 3 | 180 degree
	servo(4, 180); // Servo 4 | 180 degree
	servo(5, 180); // Servo 5 | 180 degree
	servo(6, 180); // Servo 6 | 180 degree
	delay(500);

	servo(1, -1); // Servo 1 | Free [ detach signal ]
	servo(2, -1); // Servo 2 | Free [ detach signal ]
	servo(3, -1); // Servo 3 | Free [ detach signal ]
	servo(4, -1); // Servo 4 | Free [ detach signal ]
	servo(5, -1); // Servo 5 | Free [ detach signal ]
	servo(6, -1); // Servo 6 | Free [ detach signal ]
	delay(500);
}

//- ================================================================================================
