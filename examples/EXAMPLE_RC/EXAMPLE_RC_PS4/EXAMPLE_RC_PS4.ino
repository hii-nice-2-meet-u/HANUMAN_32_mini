#include <HANUMAN_32_mini.h>

//- ================================================================================================

#define DRIVE_SPEED 100

//- ================================================================================================

void setup()
{
	Serial.begin(115200);
	Controller_Connect();
}

void loop()
{

	if (Controller_Update())
	{

		bool L1 = isController_L1_Press();
		bool R1 = isController_R1_Press();
		bool L2 = isController_L2_Press();
		bool R2 = isController_R2_Press();

		if (L1 && R1)
		{
			fd(DRIVE_SPEED);
		}
		else if (L2 || R2)
		{
			bk(DRIVE_SPEED);
		}
		else if (L1 && !R1)
		{
			tl(DRIVE_SPEED);
		}
		else if (R1 && !L1)
		{
			tr(DRIVE_SPEED);
		}
		else
		{

			if (isController_A_Press())
				Serial.println("Cross (X) / (A)");
			if (isController_B_Press())
				Serial.println("Circle (O) / (B)");
			if (isController_X_Press())
				Serial.println("Square / (X)");
			if (isController_Y_Press())
				Serial.println("Triangle / (Y)");
			if (isController_LeftStick_Press())
				Serial.println("L3");
			if (isController_RightStick_Press())
				Serial.println("R3");
			if (isController_UP_Press())
				Serial.println("D-Pad Up");
			if (isController_DOWN_Press())
				Serial.println("D-Pad Down");
			if (isController_LEFT_Press())
				Serial.println("D-Pad Left");
			if (isController_RIGHT_Press())
				Serial.println("D-Pad Right");
			if (isController_Share_Click())
				Serial.println("Share");
			if (isController_Home_Click())
				Serial.println("PS Button");
			if (isController_Option_Click())
				Serial.println("Options");

			ao();
		}
	}

	delay(50);
}

//- ================================================================================================
