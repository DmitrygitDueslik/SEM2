#include "textlib.h"
#include <cstring>
#include <cctype>

namespace TextLib
{
	char toLowerChar ( char c )
	{
		return static_cast<char>(tolower ( static_cast<unsigned char>(c) ));
	}

	bool isAlphaNum ( char c )
	{
		return isalnum ( static_cast<unsigned char>(c) ) != 0;
	}

	int getUniqueWords ( const char* text, char uniqueWords[][50], int maxUnique )
	{
		int count = 0;
		int len = strlen ( text );
		int i = 0;

		while ( i < len ) {
			while ( i < len && !isAlphaNum ( text[i] ) ) {
				i++;
			}
			if ( i >= len ) break;

			char word[50];
			int j = 0;
			while ( i < len && isAlphaNum ( text[i] ) && j < 49 ) {
				word[j++] = toLowerChar ( text[i] );
				i++;
			}
			word[j] = '\0';

			bool found = false;
			for ( int k = 0; k < count; k++ ) {
				if ( strcmp ( uniqueWords[k], word ) == 0 ) {
					found = true;
					break;
				}
			}

			if ( !found && count < maxUnique ) {
				strcpy_s ( uniqueWords[count], word );
				count++;
			}
		}
		return count;
	}

	int countWords ( const char* text )
	{
		int count = 0;
		bool inWord = false;

		for ( int i = 0; text[i] != '\0'; i++ ) {
			if ( isAlphaNum ( text[i] ) ) {
				if ( !inWord ) {
					inWord = true;
					count++;
				}
			}
			else {
				inWord = false;
			}
		}
		return count;
	}

	void replaceWord ( const char* text, const char* oldWord, const char* newWord, char* result, int maxSize )
	{
		int lenOld = strlen ( oldWord );
		int lenNew = strlen ( newWord );
		int posRes = 0;
		int i = 0;
		int lenText = strlen ( text );

		while ( i < lenText && posRes < maxSize - 1 ) {
			bool match = true;
			if ( lenOld > 0 ) {
				for ( int k = 0; k < lenOld; k++ ) {
					if ( i + k >= lenText || text[i + k] != oldWord[k] ) {
						match = false;
						break;
					}
				}
				if ( match ) {
					if ( i > 0 && isAlphaNum ( text[i - 1] ) ) match = false;
					if ( i + lenOld < lenText && isAlphaNum ( text[i + lenOld] ) ) match = false;
				}
			}
			else {
				match = false;
			}

			if ( match ) {
				for ( int k = 0; k < lenNew && posRes < maxSize - 1; k++ ) {
					result[posRes++] = newWord[k];
				}
				i += lenOld;
			}
			else {
				result[posRes++] = text[i];
				i++;
			}
		}
		result[posRes] = '\0';
	}

	void removeSpecialChars ( const char* text, char* result )
	{
		int j = 0;
		for ( int i = 0; text[i] != '\0'; i++ ) {
			if ( isAlphaNum ( text[i] ) ) {
				result[j++] = text[i];
			}
		}
		result[j] = '\0';
	}

	int isPalindrome ( const char* text )
	{
		int left = 0;
		int right = strlen ( text ) - 1;

		while ( left < right ) {
			while ( left < right && !isAlphaNum ( text[left] ) ) {
				left++;
			}
			while ( left < right && !isAlphaNum ( text[right] ) ) {
				right--;
			}

			if ( toLowerChar ( text[left] ) != toLowerChar ( text[right] ) ) {
				return 0;
			}

			left++;
			right--;
		}
		return 1;
	}
}