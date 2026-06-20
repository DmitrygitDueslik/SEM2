#include <iostream>
#include "textlib.h"

using namespace std;

int main ( )
{
	char inputText[1000];

	cout << "Vvedite stroku: ";
	cin.getline ( inputText, 1000 );

	cout << "----------------------------------------" << endl;

	int wCount = TextLib::countWords ( inputText );
	cout << "1. Kolichestvo slov: " << wCount << endl;

	char uniqueWords[20][50];
	int uniqueCount = TextLib::getUniqueWords ( inputText, uniqueWords, 20 );

	cout << "2. Unikalnye slova (" << uniqueCount << "): ";
	for ( int i = 0; i < uniqueCount; i++ ) {
		cout << uniqueWords[i] << " ";
	}
	cout << endl;

	char replacedText[1000];
	TextLib::replaceWord ( inputText, "Hello", "Hi", replacedText, 1000 );
	cout << "3. Zamena 'Hello' na 'Hi': " << replacedText << endl;

	char cleanedText[1000];
	TextLib::removeSpecialChars ( inputText, cleanedText );
	cout << "4. Bez probelov i znakov: " << cleanedText << endl;

	int result = TextLib::isPalindrome ( inputText );

	cout << "5. Stroka: \"" << inputText << "\"" << endl;
	if ( result ) {
		cout << "   -> Yavlyaetsya palindromom!" << endl;
	}
	else {
		cout << "   -> NE yavlyaetsya palindromom." << endl;
	}

	return 0;
}