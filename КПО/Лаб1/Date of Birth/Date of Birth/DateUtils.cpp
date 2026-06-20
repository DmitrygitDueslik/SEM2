#include "stdafx.h"

bool Truedays ( int date, int month, int year, bool LeapYear )
{
	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if ( LeapYear ) {
		daysInMonth[1] = 29;
	}
	if ( date > daysInMonth[month - 1] ) return false;

	return true;
}

int GetDayOfYear ( int day, int month, int year, bool LeapYear )
{
	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if ( LeapYear ) {
		daysInMonth[1] = 29;
	}

	int dayOfYear = 0;
	for ( int i = 0; i < month - 1; i++ ) {
		dayOfYear += daysInMonth[i];
	}
	dayOfYear += day;

	return dayOfYear;
}