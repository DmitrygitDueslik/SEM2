#include <iostream>
using namespace std;
class Text
{

private:
	static int total;// общее количество обработанных текстов
public:
	void CountWords ( const char* text )
	{
		int count = 0;//Это локал переменная
		bool newWord = true;    // Для нового слова
		for ( int i = 0; text[i] != '\0'; i++ ) {
			if ( text[i] == ' ' ) {
				newWord = true;
			}
			else if ( newWord ) {
				count++;
				newWord = false;
			}
		}

		cout << "Слов: " << count << "\n";
		total++;  // увеличиваем общее количество обработанных текстов
	}
	static void showTotal ( )
	{
		cout << "Всего обработано текстов: " << total << "\n";
	}
};
int Text::total = 0;// мы не можем иницилизировать в самом классе

	int main ( )
	{
		Text tp;
		const char* a = "Hello world";
		const char* b = "Hi Dmitry";
		const char* c = "Chocolate on talbe";
		cout << a << "\n" << b << "\n" << c << "\n";
		tp.CountWords ( a );
		tp.CountWords ( b);	
		tp.CountWords ( c );

		Text::showTotal ( );

		return 0;
	}
