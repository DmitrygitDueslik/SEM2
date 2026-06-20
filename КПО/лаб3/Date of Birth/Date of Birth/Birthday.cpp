#include "stdafx.h"
#include "DateUtils.h"

int DaysUntilBirthday ( int currentDay, int currentMonth, int currentYear,
	int birthDay, int birthMonth, bool LeapYear, bool NextYear )
{
	int currentDayOfYear = GetDayOfYear ( currentDay, currentMonth, currentYear, LeapYear );
	int birthdayDayOfYear = GetDayOfYear ( birthDay, birthMonth, currentYear, NextYear );

	int daysUntil = birthdayDayOfYear - currentDayOfYear;

	if ( daysUntil < 0 ) {
		if ( NextYear ) {
			daysUntil += 366;
		}
		else {
			daysUntil += 365;
		}
	}

	return daysUntil;
}