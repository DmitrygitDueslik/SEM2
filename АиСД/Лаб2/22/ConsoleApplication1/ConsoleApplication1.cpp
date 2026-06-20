#include <iostream>
using namespace std;

int main ( )
{
	long long N, mid, up, down = 1, ans;
	long long col[256];
	long long maxcol[256];
	int i = 0;

	cout << "Введите N:" << endl;
	cin >> N;
	if ( cin.fail ( ) || N <= 0 || N > 9223372036854775807 ) {
		cout << " ОШИБКА: Введите число от 1 до 9223372036854775807!" << endl;
		return 1;
	}

	long long forend = N;
	up = N;
	int count = 0;
	int maxsteps = 0;

	i++;

	if ( up % 2 == 0 ) {
		mid = N / 2;
	}
	else if ( up % 2 != 0 ) {
		mid = (N + 1) / 2;
	}
	col[i] = mid;
	i++;
	do {
		cout << "Это ваше число: " << mid << endl;
		cout << "1 - мало, 2 - много, 3 - угадал" << endl;
		cin >> ans;
		count++;
		if ( ans == 1 ) {
			down = mid + 1;
		}
		else if ( ans == 2 ) {
			up = mid - 1;
		}
		else if ( ans == 3 ) {
			cout << "\nПобеда!" << endl;
			break;
		}

		if ( down > up ) {
			cout << "Противоречивые ответы!" << endl;
			break;
		}

		if ( (down + up) % 2 == 1 ) {
			mid = (down + up + 1) / 2;
		}
		else {
			mid = (down + up) / 2;
		}
		col[i] = mid;
		i++;
	} while ( true );
	cout << "\nВсе шаги бинарного поиска:" << count << endl;
	for ( int j = 1; j < i; j++ ) {
		cout << col[j] << endl;
	}

	cout << ">>>>>>>>>\n" << endl;
	cout << "Теоретические максимальные шаги\n";
	while ( (forend / 2) != 0 ) {
		if ( forend % 2 == 1 ) {
			forend += 1;
			forend /= 2;
		}
		else  forend /= 2;
		cout << forend << endl;
		maxsteps++;
	}

	if ( count >= maxsteps ) {
		maxsteps = count;
		for ( int j = 0; j < i; j++ ) {
			maxcol[j] = col[j];
		}
		cout << "\nМаксимальные шаги:" << endl;
		for ( int j = 1; j < i; j++ ) {
			cout << maxcol[j] << endl;
		}5
	}

	cout << "Максимальное количество шагов : " << maxsteps << endl;
	return 0;
}