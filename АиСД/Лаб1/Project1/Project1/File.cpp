#include <iostream>
#include <ctime>
using namespace std;

unsigned long long Myf ( int N )
{
	if ( N == 0 ) {
		return 0;
	}
	if ( N == 1 ) {
		return 1;
	}
	return Myf ( N - 1 ) + Myf ( N - 2 );
}

int main ( )
{
	int N;
	int start, end;
	cout << "Введите N чисел последовательности Фибоначчи" << "\n";
	cin >> N;
	if ( N < 0 ) {
		cout << "Неправильно";
		return 0;
	}

	if ( N > 200 ) {
		cout << " N не должно быть больше 199 (маленький массив(200))" << endl;
		return 0;
	}

	unsigned long long massive[200];

	massive[0] = 0;

	massive[1] = 1;

	start = time ( 0 );

	for ( int i = 2; i <= N; i++ ) {
		massive[i] = massive[i - 1] + massive[i - 2];
	}
	end = time ( 0 );

	cout << "Число Фибоначчи" << "\n";

	cout << "\nЧисло " << N << " : " << massive[N] << "\n";
	cout << "Время циклом " << (end - start) / 60 << " минут " << (end - start) % 60 << " секунд" << endl;

	cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>" << "\n";
	start = time ( 0 );

	unsigned long long ans = Myf ( N );
	end = time ( 0 );
	cout << "\nЧисло " << N << " Рекурсией : " << ans << "\n";
	cout << "Время рекурсией " << (end - start) / 60 << " минут " << (end - start) % 60 << " секунд" << endl;

	return 0;
}