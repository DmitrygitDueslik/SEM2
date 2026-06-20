#ifndef TEXTLIB_H
#define TEXTLIB_H

namespace TextLib
{
	int getUniqueWords ( const char* text, char uniqueWords[][50], int maxUnique );
	int countWords ( const char* text );
	void replaceWord ( const char* text, const char* oldWord, const char* newWord, char* result, int maxSize );
	void removeSpecialChars ( const char* text, char* result );
	int isPalindrome ( const char* text );
}

#endif