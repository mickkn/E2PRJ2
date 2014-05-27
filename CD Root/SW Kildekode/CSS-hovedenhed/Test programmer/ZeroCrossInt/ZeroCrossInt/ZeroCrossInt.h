/*
 * ZeroCrossInt interrupt header
 *
 * Styrer hvornår der skal afsendes 120 kHz bursts ud fra X10 kommandoerne i bufferen
 *
 * Af Bjørn Sørensen
 *
 */

#pragma once

#define F_CPU 3686400

#include <avr/interrupt.h>
#include <util/delay.h>
#include "Timer.h"
#include "X10IF.h"

class ZeroCrossInt
{
public:
	ZeroCrossInt();
	~ZeroCrossInt();
};
