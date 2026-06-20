#include <iostream>
#include <deque>
#include <string>
using namespace std;

deque<string> park;
deque<string> waitList;

void Status ( )
{
	cout << "\n----Стоянка-----" << endl;
	if ( park.empty ( ) ) {
		cout << "Машин нет" << endl;
	}
	else {
		for ( int i = 0; i < park.size ( ); i++ ) {
			cout << " " << (i + 1) << ". " << park.at ( i ) << endl;
		}
	}
	cout << "\n----Очеред Ожидания------\n";
	if ( waitList.empty ( ) ) {
		cout << "Пусто \n";
	}
	else {
		for ( int i = 0; i < waitList.size ( ); i++ ) {
			cout << "  " << (i + 1) << ". " << waitList.at ( i ) << endl;
		}
	}
	cout << endl;
}

void rent ( string user )
{
	if ( !park.empty ( ) ) {
		string car = park.front ( );
		park.pop_front ( );
		cout << user << " взял: " << car << endl;
	}
	else {
		waitList.push_back ( user );
		cout << user << "В очереди " << endl;
	}
}
void returnCar ( string car )
{
	cout << "Машина возвращена " << car << endl;
	cout << endl;
	if ( !waitList.empty ( ) ) {
		string nextUser = waitList.front ( );
		waitList.pop_front ( );
		cout << "Машина передана: " << nextUser << endl;
	}
	else {
		park.push_back ( car );
		cout << "Машина на стоянку " << endl;
	}
}

int main ( )
{
	park.push_back ( "Ferrari" );
	park.push_back ( "BMW" );

	Status ( );
	rent ( "Иван" );
	rent ( "Дима" );
	rent ( "Володя" );//Попадет в очередь
	Status ( );
	returnCar ( "Ferrari" );
	Status ( );
	return 0;
}