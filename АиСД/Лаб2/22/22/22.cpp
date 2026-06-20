#include <iostream>

int main ( )
{
	using namespace std;
	unsigned long long N, mid, up, down = 1, ans, X;
	long long col[256];
	int i = 0, count = 1;

	cout << "Введите  N:" << endl;
	cin >> N;
	long long forend = N;
	up = N;
	if ( up % 2 == 0 ) {
		mid = N / 2;
	}
	else if ( up % 2 != 0 ) {
		mid = (N + 1) / 2;
	}
	col[i] = N;
	i++;
	col[i] = mid;
	i++;
	do {
		if ( down >= up ) {
			cout << "Противоречивые ответы!" << endl;
			break;
		}
		cout << "Это ваше число: " << mid << endl << "1 - мало, 2 - много, 3 - угадал" << endl;

		cin >> ans;

		if ( ans == 1 ) {
			down = mid;
			mid = down + (up - down + 1) / 2;
			col[i] = mid;
			i++;
			count++;
		}
		else if ( ans == 2 ) {
			up = mid;
			mid = down + (up - down + 1) / 2;
			col[i] = mid;
			i++;
			count++;
		}
		else if ( ans == 3 ) {
			cout << "Поздравляю!" << endl;
			col[i] = mid;
			break;
		}
	} while ( true );
	X = mid;
	cout << "Ваше число " << X << endl;
	if ( down >= up ) {
		for ( int i = 0; i < count; i++ ) {
			cout << col[i] << endl;
		}
	}
	else for ( i = 0; i < 6 = count; i++ ) {
		cout << col[i] << endl;
	}
	cout << "количество шагов = " << count << endl << endl;
	int maxspteps = 0;
	cout << "\n" << forend << endl;
	while ( (forend / 2) != 0 ) {
		if ( forend % 2 == 1 ) {
			forend += 1;
			forend /= 2;
		}
		else(forend /= 2);
		cout << forend << endl;
		maxspteps++;
	}
	cout << "Максимальное количество шагов : " << maxspteps << endl;

	return 0;
}