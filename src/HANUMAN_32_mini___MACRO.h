
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*
 *
 *	File		:	HANUMAN_32_mini___MACRO.h
 *	Release		:	v0.1.0
 *
 *	Created on	:	Sun 24 May 2026
 *		Author	:	hii-nice-2-meet-u
 *
 */
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#ifndef INC_HANUMAN_32_MINI__MACRO_H
#define INC_HANUMAN_32_MINI__MACRO_H

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <Arduino.h>

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//* ----------------------------------------------------------------

#define __DEFINE__SW_A 4

//* ----------------------------------------------------------------

#define __DEFINE__M1_PWM_A 25
#define __DEFINE__M1_PWM_B 33
#define __DEFINE__M1_INH   32

#define __DEFINE__M2_PWM_A 26
#define __DEFINE__M2_PWM_B 27
#define __DEFINE__M2_INH   13

//* ----------------------------------------------------------------

#define __DEFINE__MOTOR_PWM_FREQ 20000
#define __DEFINE__MOTOR_PWM_RES  8

//* ----------------------------------------------------------------

#define __DEFINE__SERVO_PWM_FREQ 50
#define __DEFINE__SERVO_PWM_RES  16

#define __DEFINE__SERVO_MIN_RANGE_DUTY 1638
#define __DEFINE__SERVO_MAX_RANGE_DUTY 6554

//* ----------------------------------------------------------------

#define __DEFINE__Switch 4

#define pinSwitch __DEFINE__Switch
#define pinSw     __DEFINE__Switch

#define __DEFINE__SIGNAL_ID1  5
#define __DEFINE__SIGNAL_ID2  19
#define __DEFINE__SIGNAL_ID3  23
#define __DEFINE__SIGNAL_ID4  18
#define __DEFINE__SIGNAL_ID5  10
#define __DEFINE__SIGNAL_ID6  9
#define __DEFINE__SIGNAL_ID7  34
#define __DEFINE__SIGNAL_ID8  35
#define __DEFINE__SIGNAL_ID9  37
#define __DEFINE__SIGNAL_ID10 38

//* ----------------------------------------------------------------

#define __DEFINE__SPI_CS   __DEFINE__SIGNAL_1
#define __DEFINE__SPI_MISO __DEFINE__SIGNAL_2
#define __DEFINE__SPI_MOSI __DEFINE__SIGNAL_3
#define __DEFINE__SPI_SCLK __DEFINE__SIGNAL_4

//* ----------------------------------------------------------------

#define __DEFINE__DIP_1 22
#define __DEFINE__DIP_2 21
#define __DEFINE__DIP_3 14

//* ----------------------------------------------------------------

#define __DEFINE__I2C_SCL __DEFINE__DIP_1
#define __DEFINE__I2C_SDA __DEFINE__DIP_2

//* ----------------------------------------------------------------

#define __DEFINE__MIN_PULSE_SERVO 500
#define __DEFINE__MAX_PULSE_SERVO 2500

//* ----------------------------------------------------------------

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~1