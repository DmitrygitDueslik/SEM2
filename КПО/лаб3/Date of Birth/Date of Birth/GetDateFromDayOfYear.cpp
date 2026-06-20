#include "stdafx.h"
void GetDateFromDayOfYear ( int dayOfYear, int year, bool isLeap, int& outDay, int& outMonth )
{
	int daysInMonth[] = { 0, 31, 28 + isLeap, 31, 30, 31, 30,
						  31, 31, 30, 31, 30, 31 };

	int maxDays = isLeap ? 366 : 365;
	if ( dayOfYear < 1 || dayOfYear > maxDays ) {
		outDay = -1;
		outMonth = -1;
		return;
	}

	outMonth = 1;
	for ( int i = 1; i <= 12; i++ ) {
		if ( dayOfYear <= daysInMonth[i] ) {
			outMonth = i;
			break;
		}
		dayOfYear -= daysInMonth[i];
	}
	outDay = dayOfYear;  // Остаток число месяца
}