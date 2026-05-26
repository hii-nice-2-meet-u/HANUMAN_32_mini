
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*
 *
 *	File		:	HANUMAN_32_mini.h
 *	Release		:	v0.1.2
 *
 *	Created on	:	Sun 24 May 2026
 *		Author	:	hii-nice-2-meet-u
 *
 */
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*
|
|    This product includes Bluepad32, which is licensed under the Apache License, Version 2.0.
|
|    Copyright (c) Ricardo Quesada and contributors.
|
|    You may obtain a copy of the Apache License, Version 2.0 at:
|        http://www.apache.org/licenses/LICENSE-2.0
|
|    Unless required by applicable law or agreed to in writing, software
|    distributed under the License is distributed on an "AS IS" BASIS,
|    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
|    See the License for the specific language governing permissions and
|    limitations under the License.
|
*/
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#ifndef INC_HANUMAN_32_MINI_H
#define INC_HANUMAN_32_MINI_H

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <Arduino.h>
#include <HANUMAN_32_mini___MACRO.h>

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// ================================================================================================================================

#define sleep(x)    delay(x)
#define delay_us(x) delayMicroseconds(x)

/// ================================================================================================================================

/// ================================================================================================================================
//\ • Switch
/// ================================================================================================================================

//- ================ Switch - A ================================

#define wait_swA(void) swA()

bool is_swA(void)
{
	return digitalRead(__DEFINE__Switch);
}

void swA_Press(void)
{
	while (!is_swA())
		;
	delay(25);
}

void swA_unPress(void)
{
	while (is_swA())
		;
	delay(100);
}

void swA(void)
{
	swA_Press();
	swA_unPress();
}

//- ================================================================

#define OK(void)    swA(void)
#define is_OK(void) is_swA(void)

#define swOK(void)    swA(void)
#define is_swOK(void) is_swA(void)

//- ================================================================

/// ================================================================================================================================
//\ • Signal
/// ================================================================================================================================

uint8_t pinMapping[11] = {
    0,
    __DEFINE__SIGNAL_ID1,
    __DEFINE__SIGNAL_ID2,
    __DEFINE__SIGNAL_ID3,
    __DEFINE__SIGNAL_ID4,
    __DEFINE__SIGNAL_ID5,
    __DEFINE__SIGNAL_ID6,
    __DEFINE__SIGNAL_ID7,
    __DEFINE__SIGNAL_ID8,
    __DEFINE__SIGNAL_ID9,
    __DEFINE__SIGNAL_ID10,
};

//- ================ Digital IN ================================

#define in(channel) digital(channel)
#define IN(channel) digital(channel)

uint8_t digital(uint8_t channel)
{
	if (channel > 10)
	{
		return 0;
	}
	pinMode(pinMapping[channel], INPUT);
	return digitalRead(pinMapping[channel]);
}

//- ================ Digital OUT ================================

#define out(channel, value) digital(channel, value)
#define OUT(channel, value) digital(channel, value)

void digital(uint8_t channel, uint8_t value)
{
	if (channel > 6)
	{
		return;
	}

	pinMode(pinMapping[channel], OUTPUT);
	digitalWrite(pinMapping[channel], value);
}

//- ================================================================

/// ================================================================================================================================
//\ • Motor Control
/// ================================================================================================================================

//- ================ Motor - Control ================================

void MotorCtrl__M1(int16_t speed)
{
	uint8_t PWM_value = (constrain(abs(speed), 0, 100) * 255 + 50) / 100;

	uint8_t PWM_value_A = 0;
	uint8_t PWM_value_B = 0;

	if (speed > 0)
		PWM_value_A = PWM_value;
	else
		PWM_value_B = PWM_value;

#ifdef CONFIG_BLUEPAD32_PLATFORM_CUSTOM
	ledcWrite(__DEFINE__M1_PWM_A__CHANNEL, PWM_value_A);
	ledcWrite(__DEFINE__M1_PWM_B__CHANNEL, PWM_value_B);

#else
	ledcWrite(__DEFINE__M1_PWM_A, PWM_value_A);
	ledcWrite(__DEFINE__M1_PWM_B, PWM_value_B);

#endif
}

void MotorCtrl__M2(int16_t speed)
{
	uint8_t PWM_value = (constrain(abs(speed), 0, 100) * 255 + 50) / 100;

	uint8_t PWM_value_A = 0;
	uint8_t PWM_value_B = 0;

	if (speed > 0)
		PWM_value_A = PWM_value;
	else
		PWM_value_B = PWM_value;

#ifdef CONFIG_BLUEPAD32_PLATFORM_CUSTOM
	ledcWrite(__DEFINE__M2_PWM_A__CHANNEL, PWM_value_A);
	ledcWrite(__DEFINE__M2_PWM_B__CHANNEL, PWM_value_B);

#else
	ledcWrite(__DEFINE__M2_PWM_A, PWM_value_A);
	ledcWrite(__DEFINE__M2_PWM_B, PWM_value_B);

#endif
}

/// ----------------------------------------------------------------

#define Motor motor
#define MOTOR motor

void motor(uint8_t channel, int16_t speed)
{
	switch (channel)
	{
	case 1:
		MotorCtrl__M1(speed);
		return;

	case 2:
		MotorCtrl__M2(speed);
		return;

	default:
		return;
	}
}

//- ================ Motor - Stop ================================

void MotorCtrl__Break_M1(void)
{
#ifdef CONFIG_BLUEPAD32_PLATFORM_CUSTOM
	ledcWrite(__DEFINE__M1_PWM_A__CHANNEL, 255);
	ledcWrite(__DEFINE__M1_PWM_B__CHANNEL, 255);

#else
	ledcWrite(__DEFINE__M1_PWM_A, 255);
	ledcWrite(__DEFINE__M1_PWM_B, 255);

#endif
}

void MotorCtrl__Break_M2(void)
{
#ifdef CONFIG_BLUEPAD32_PLATFORM_CUSTOM
	ledcWrite(__DEFINE__M2_PWM_A__CHANNEL, 255);
	ledcWrite(__DEFINE__M2_PWM_B__CHANNEL, 255);

#else
	ledcWrite(__DEFINE__M2_PWM_A, 255);
	ledcWrite(__DEFINE__M2_PWM_B, 255);

#endif
}

void MotorCtrl__Coast_M1(void)
{
#ifdef CONFIG_BLUEPAD32_PLATFORM_CUSTOM
	ledcWrite(__DEFINE__M1_PWM_A__CHANNEL, 0);
	ledcWrite(__DEFINE__M1_PWM_B__CHANNEL, 0);

#else
	ledcWrite(__DEFINE__M1_PWM_A, 0);
	ledcWrite(__DEFINE__M1_PWM_B, 0);

#endif
}

void MotorCtrl__Coast_M2(void)
{
#ifdef CONFIG_BLUEPAD32_PLATFORM_CUSTOM
	ledcWrite(__DEFINE__M2_PWM_A__CHANNEL, 0);
	ledcWrite(__DEFINE__M2_PWM_B__CHANNEL, 0);

#else
	ledcWrite(__DEFINE__M2_PWM_A, 0);
	ledcWrite(__DEFINE__M2_PWM_B, 0);

#endif
}

void MotorCtrl__Break(void)
{
	MotorCtrl__Break_M1();
	MotorCtrl__Break_M2();
}

void MotorCtrl__Coast(void)
{
	MotorCtrl__Coast_M1();
	MotorCtrl__Coast_M2();
}

#define motor_stop(void) MotorCtrl__Coast()
#define ao(void)         MotorCtrl__Coast()

#define MOTOR_STOP(void) MotorCtrl__Break()
#define AO(void)         MotorCtrl__Break()

//- ================ Motor - ENABLE / DISABLE ================================

void MotorCtrl__Free(void)
{
	digitalWrite(__DEFINE__M1_INH, LOW);
	digitalWrite(__DEFINE__M2_INH, LOW);
}

void MotorCtrl__UnFree(void)
{
	digitalWrite(__DEFINE__M1_INH, HIGH);
	digitalWrite(__DEFINE__M2_INH, HIGH);
}

#define motor_free(void) MotorCtrl__Free()
#define _free(void)      MotorCtrl__Free()

#define motor_unfree(void) MotorCtrl__UnFree()
#define _unfree(void)      MotorCtrl__UnFree()

#define motor_enable(void) MotorCtrl__Free()
#define _enable(void)      MotorCtrl__Free()

#define motor_disable(void) MotorCtrl__UnFree()
#define _disable(void)      MotorCtrl__UnFree()

//- ================ Motor - Function ================================

#define M(LSp, RSp) m(LSp, RSp)

void m(int16_t left_speed, int16_t right_speed)
{
	uint8_t PWM_M1_value_A = 0;
	uint8_t PWM_M1_value_B = 0;
	uint8_t PWM_M2_value_A = 0;
	uint8_t PWM_M2_value_B = 0;

	if (left_speed > 0)
		PWM_M1_value_A = left_speed;
	else
		PWM_M1_value_B = left_speed;

	if (right_speed > 0)
		PWM_M2_value_A = right_speed;
	else
		PWM_M2_value_B = right_speed;

#ifdef CONFIG_BLUEPAD32_PLATFORM_CUSTOM
	ledcWrite(__DEFINE__M1_PWM_A__CHANNEL, PWM_M1_value_A);
	ledcWrite(__DEFINE__M1_PWM_B__CHANNEL, PWM_M1_value_B);
	ledcWrite(__DEFINE__M2_PWM_A__CHANNEL, PWM_M2_value_A);
	ledcWrite(__DEFINE__M2_PWM_B__CHANNEL, PWM_M2_value_B);

#else
	ledcWrite(__DEFINE__M1_PWM_A, PWM_M1_value_A);
	ledcWrite(__DEFINE__M1_PWM_B, PWM_M1_value_B);
	ledcWrite(__DEFINE__M2_PWM_A, PWM_M2_value_A);
	ledcWrite(__DEFINE__M2_PWM_B, PWM_M2_value_B);

#endif
}

/// ----------------------------------------------------------------

void fd(int8_t speed)
{
	MotorCtrl__M1(speed);
	MotorCtrl__M2(speed);
}

void fd2(int8_t left_speed, int8_t right_speed)
{
	MotorCtrl__M1(left_speed);
	MotorCtrl__M2(right_speed);
}

void bk(int8_t speed)
{
	MotorCtrl__M1(-speed);
	MotorCtrl__M2(-speed);
}

void bk2(int8_t left_speed, int8_t right_speed)
{
	MotorCtrl__M1(-left_speed);
	MotorCtrl__M2(-right_speed);
}

void tl(int8_t speed)
{
	MotorCtrl__M1(0);
	MotorCtrl__M2(speed);
}

void tr(int8_t speed)
{
	MotorCtrl__M1(speed);
	MotorCtrl__M2(0);
}

void sl(int8_t speed)
{
	MotorCtrl__M1(-speed);
	MotorCtrl__M2(speed);
}

void sr(int8_t speed)
{
	MotorCtrl__M1(speed);
	MotorCtrl__M2(-speed);
}

/// ----------------------------------------------------------------

#define FD(speed) fd(speed)
#define BK(speed) bk(speed)
#define TL(speed) tl(speed)
#define TR(speed) tr(speed)
#define SL(speed) sl(speed)
#define SR(speed) sr(speed)

#define FD2(left_speed, right_speed) fd2(left_speed, right_speed)
#define BK2(left_speed, right_speed) bk2(left_speed, right_speed)

//- ================================================================

/// ================================================================================================================================
//\ • SERVO
/// ================================================================================================================================

uint8_t ServoAttachStatus = 0;

//- ================ Servo ================================

int __Calculate_Duty(int angle)
{
	return __DEFINE__SERVO_MIN_RANGE_DUTY + ((__DEFINE__SERVO_MAX_RANGE_DUTY * angle) / 180);
}

void servo(uint8_t channel, int16_t angle)
{
	uint8_t PWM_Channel;
	uint8_t ServoPin;

	switch (channel)
	{

	case 1:
		PWM_Channel = SERVO_1__CHANNEL;
		ServoPin    = __DEFINE__SIGNAL_ID1;
		break;

	case 2:
		PWM_Channel = SERVO_2__CHANNEL;
		ServoPin    = __DEFINE__SIGNAL_ID2;
		break;

	case 3:
		PWM_Channel = SERVO_3__CHANNEL;
		ServoPin    = __DEFINE__SIGNAL_ID3;
		break;

	case 4:
		PWM_Channel = SERVO_4__CHANNEL;
		ServoPin    = __DEFINE__SIGNAL_ID4;
		break;

	case 5:
		PWM_Channel = SERVO_5__CHANNEL;
		ServoPin    = __DEFINE__SIGNAL_ID5;
		break;

	case 6:
		PWM_Channel = SERVO_6__CHANNEL;
		ServoPin    = __DEFINE__SIGNAL_ID6;
		break;

	default:
		return;
	}

	if (angle < 0)
	{
#ifdef CONFIG_BLUEPAD32_PLATFORM_CUSTOM
		ledcDetachPin(ServoPin);
#else
		ledcDetach(PWM_Channel);
#endif
		ServoAttachStatus &= ~(1 << channel);
	}
	else
	{
		if (!(ServoAttachStatus & (1 << channel)))
#ifdef CONFIG_BLUEPAD32_PLATFORM_CUSTOM
		{
			ledcSetup(PWM_Channel, __DEFINE__SERVO_PWM_FREQ, __DEFINE__SERVO_PWM_RES);
			ledcAttachPin(ServoPin, PWM_Channel);
			ServoAttachStatus |= (1 << channel);
		}
		ledcWrite(PWM_Channel, __Calculate_Duty(angle));
#else
		{
			ledcAttach(ServoPin, __DEFINE__SERVO_PWM_FREQ, __DEFINE__SERVO_PWM_RES);
			ServoAttachStatus |= (1 << channel);
		}
		ledcWrite(ServoPin, __Calculate_Duty(angle));
#endif
	}
}

//- ================================================================

/// ================================================================================================================================
//\ • Controller
/// ================================================================================================================================

#ifdef CONFIG_BLUEPAD32_PLATFORM_CUSTOM

//- ================================================================

#include <Bluepad32.h>

GamepadPtr myGamepad;

//- ================================================================

void onConnectedGamepad(GamepadPtr gp)
{
	myGamepad = gp;
}

void onDisconnectedGamepad(GamepadPtr gp)
{
	myGamepad = nullptr;
}

void Controller_Connect(void)
{
	BP32.setup(&onConnectedGamepad, &onDisconnectedGamepad);
	BP32.forgetBluetoothKeys();
	BP32.enableVirtualDevice(false);
}

bool Controller_Update(void)
{
	if (BP32.update())
	{
		return (myGamepad && myGamepad->isConnected());
	}
	return 0;
}

//- ================================================================

bool isController_A(void)
{
	return myGamepad->a();
}

bool isController_B(void)
{
	return myGamepad->b();
}

bool isController_X(void)
{
	return myGamepad->x();
}

bool isController_Y(void)
{
	return myGamepad->y();
}

//- ================================================================

bool isController_L1(void)
{
	return myGamepad->l1();
}

bool isController_R1(void)
{
	return myGamepad->r1();
}

bool isController_L2(void)
{
	return myGamepad->l2();
}

bool isController_R2(void)
{
	return myGamepad->r2();
}

//- ================================================================

bool isController_UP(void)
{
	return myGamepad->dpad() & DPAD_UP;
}

bool isController_DOWN(void)
{
	return myGamepad->dpad() & DPAD_DOWN;
}

bool isController_LEFT(void)
{
	return myGamepad->dpad() & DPAD_LEFT;
}

bool isController_RIGHT(void)
{
	return myGamepad->dpad() & DPAD_RIGHT;
}

//- ================================================================

bool isController_Home(void)
{
	return myGamepad->miscButtons() & 0x01;
}

bool isController_Share(void)
{
	return myGamepad->miscButtons() & 0x02;
}

bool isController_Option(void)
{
	return myGamepad->miscButtons() & 0x04;
}

//- ================================================================

bool isController_LeftStick(void)
{
	return myGamepad->buttons() & BUTTON_THUMB_L;
}

bool isController_RightStick(void)
{
	return myGamepad->buttons() & BUTTON_THUMB_R;
}

//- ================================================================

int32_t Controller_getLX(void)
{
	return myGamepad->axisX();
}

int32_t Controller_getLY(void)
{
	return myGamepad->axisY();
}

int32_t Controller_getRX(void)
{
	return myGamepad->axisRX();
}

int32_t Controller_getRY(void)
{
	return myGamepad->axisRY();
}

//- ================================================================

int32_t Controller_getL2(void)
{
	return myGamepad->brake();
}

int32_t Controller_getR2(void)
{
	return myGamepad->throttle();
}

//- ================================================================

uint8_t Controller_getBattery(void)
{
	return myGamepad->battery() / 255.00 * 100;
}

//- ================================================================

void Controller_Rumble(void)
{
	return myGamepad->playDualRumble(0, 250, 0x80, 0x80);
}

void Controller_Rumble(uint16_t duration, uint8_t strong, uint8_t weak)
{
	return myGamepad->playDualRumble(0, duration, strong, weak);
}

//- ================================================================

void Controller_setColor(uint8_t red, uint8_t green, uint8_t blue)
{
	myGamepad->setColorLED(red, green, blue);
}

//- ================================================================

int32_t Controller_gyroX(void)
{
	return myGamepad->gyroX();
}

int32_t Controller_gyroY(void)
{
	return myGamepad->gyroY();
}

int32_t Controller_gyroZ(void)
{
	return myGamepad->gyroZ();
}

int32_t Controller_accelX(void)
{
	return myGamepad->accelX();
}

int32_t Controller_accelY(void)
{
	return myGamepad->accelY();
}

int32_t Controller_accelZ(void)
{
	return myGamepad->accelZ();
}

//- ================================================================

#endif

/// ================================================================================================================================
//\ • Initialization
/// ================================================================================================================================

void __initialize_Hanuman32(void)
{
	pinMode(__DEFINE__M1_INH, OUTPUT);
	pinMode(__DEFINE__M2_INH, OUTPUT);
	digitalWrite(__DEFINE__M1_INH, LOW);
	digitalWrite(__DEFINE__M2_INH, LOW);

#ifdef CONFIG_BLUEPAD32_PLATFORM_CUSTOM
	ledcSetup(__DEFINE__M1_PWM_A__CHANNEL, __DEFINE__MOTOR_PWM_FREQ, __DEFINE__MOTOR_PWM_RES);
	ledcSetup(__DEFINE__M1_PWM_B__CHANNEL, __DEFINE__MOTOR_PWM_FREQ, __DEFINE__MOTOR_PWM_RES);
	ledcSetup(__DEFINE__M2_PWM_A__CHANNEL, __DEFINE__MOTOR_PWM_FREQ, __DEFINE__MOTOR_PWM_RES);
	ledcSetup(__DEFINE__M2_PWM_B__CHANNEL, __DEFINE__MOTOR_PWM_FREQ, __DEFINE__MOTOR_PWM_RES);

	ledcAttachPin(__DEFINE__M1_PWM_A, __DEFINE__M1_PWM_A__CHANNEL);
	ledcAttachPin(__DEFINE__M1_PWM_B, __DEFINE__M1_PWM_B__CHANNEL);
	ledcAttachPin(__DEFINE__M2_PWM_A, __DEFINE__M2_PWM_A__CHANNEL);
	ledcAttachPin(__DEFINE__M2_PWM_B, __DEFINE__M2_PWM_B__CHANNEL);

#else
	ledcAttach(__DEFINE__M1_PWM_A, __DEFINE__MOTOR_PWM_FREQ, __DEFINE__MOTOR_PWM_RES);
	ledcAttach(__DEFINE__M1_PWM_B, __DEFINE__MOTOR_PWM_FREQ, __DEFINE__MOTOR_PWM_RES);
	ledcAttach(__DEFINE__M2_PWM_A, __DEFINE__MOTOR_PWM_FREQ, __DEFINE__MOTOR_PWM_RES);
	ledcAttach(__DEFINE__M2_PWM_B, __DEFINE__MOTOR_PWM_FREQ, __DEFINE__MOTOR_PWM_RES);

	ledcWrite(__DEFINE__M1_PWM_A, 0);
	ledcWrite(__DEFINE__M1_PWM_B, 0);
	ledcWrite(__DEFINE__M2_PWM_A, 0);
	ledcWrite(__DEFINE__M2_PWM_B, 0);

#endif

	delay(100);
	digitalWrite(__DEFINE__M1_INH, HIGH);
	digitalWrite(__DEFINE__M2_INH, HIGH);
}

/// ================================================================================================================================
//\ ================================================================================================================================

void initVariant(void)
{
	__initialize_Hanuman32();
}

//\ ================================================================================================================================
/// ================================================================================================================================

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~