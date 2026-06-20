#include "stdafx.h"

void Month ( int month, char* monthName )
{
	const char* NameMonth[] = {
	" ","January", "February", "March", "April",
	"May", "June", "July", "August",
	"September", "October", "November", "December"
	};

	if ( month < 1 || month > 12 ) {
		monthName[0] = '?';
		monthName[1] = '\0';
		return;
	}

	int i = 0;
	for ( i = 0; NameMonth[month][i] != '\0' && i < 14; i++ ) {
		monthName[i] = NameMonth[month][i];
	}
	monthName[i] = '\0';
}