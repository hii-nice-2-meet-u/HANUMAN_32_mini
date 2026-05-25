#include <HANUMAN_32_mini.h>
#include <Bluepad32.h>

//- ================================================================================================

GamepadPtr myGamepad = nullptr;

void onConnectedGamepad(GamepadPtr gp)
{
	myGamepad = gp;
	Serial.println("PS4 เชื่อมต่อแล้ว!");
}

void onDisconnectedGamepad(GamepadPtr gp)
{
	myGamepad = nullptr;
	Serial.println("PS4 ตัดการเชื่อมต่อ");
}

//- ================================================================================================

void setup()
{
	Serial.begin(115200);

	// Bluepad32
	BP32.setup(&onConnectedGamepad, &onDisconnectedGamepad);
	Serial.println("รอการเชื่อมต่อ PS4...");
}

void loop()
{
	BP32.update();

	if (myGamepad && myGamepad->isConnected())
	{

		bool L1 = myGamepad->l1();
		bool R1 = myGamepad->r1();
		bool L2 = myGamepad->l2();
		bool R2 = myGamepad->r2();

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
			uint16_t btn  = myGamepad->buttons();
			uint8_t  misc = myGamepad->miscButtons();

			if (btn & 0x0001)
				Serial.println("Cross (X)");
			if (btn & 0x0002)
				Serial.println("Circle (O)");
			if (btn & 0x0004)
				Serial.println("Square");
			if (btn & 0x0008)
				Serial.println("Triangle");
			if (btn & 0x0100)
				Serial.println("L3");
			if (btn & 0x0200)
				Serial.println("R3");
			if (btn & 0x0400)
				Serial.println("D-Pad Up");
			if (btn & 0x0800)
				Serial.println("D-Pad Down");
			if (btn & 0x1000)
				Serial.println("D-Pad Left");
			if (btn & 0x2000)
				Serial.println("D-Pad Right");
			if (misc & 0x01)
				Serial.println("Share");
			if (misc & 0x02)
				Serial.println("PS Button");
			if (misc & 0x04)
				Serial.println("Options");

			ao();
		}
	}
	else
	{
		Serial.println("รอการเชื่อมต่อ PS4...");
		delay(1000);
	}

	delay(50);
}

//- ================================================================================================
