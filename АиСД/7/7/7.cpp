#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector<int> tower[4];
int moveCount = 0;

void drawTowers ( )
{
	int maxHeight = 0;
	for ( int i = 1; i <= 3; i++ ) {
		if ( tower[i].size ( ) > maxHeight ) {
			maxHeight = tower[i].size ( );
		}
	}

	cout << "\n";
	for ( int level = maxHeight - 1; level >= 0; level-- ) {
		for ( int t = 1; t <= 3; t++ ) {
			if ( level < tower[t].size ( ) ) {
				int diskSize = tower[t][level];
				string disk ( diskSize * 2 - 1, '=' );
				cout << setw ( 4 ) << disk << setw ( 4 ) << diskSize;
			}
			else {
				cout << " | ";
			}
			cout << " ";
		}
		cout << "\n";
	}

	cout << " _______ _______ _______\n";
	cout << " 1  2  3\n";
}

void MoveDisk ( int from, int to )
{
	moveCount++;
	int Disk = tower[from].back ( );
	tower[from].pop_back ( );
	tower[to].push_back ( Disk );
	cout << "\n[Ход " << moveCount << " ]Переместить диск " << Disk << " Со стержня "
		<< from << " На стержень " << to << "\n";
}

void hanoi ( int from, int to, int n )
{
	if ( n <= 0 ) {
		cerr << "Ошибка";
		return;
	}
	if ( from < 1 || from>3 || to < 1 || to > 3 ) {
		cerr << "Ошибка";
		return;
	}
	if ( from == to ) {
		cerr << "Ошибка";
	}
	if ( n == 1 ) {
		MoveDisk ( from, to );
	}
	else {
		int tmp = 6 - from - to;//Вспомогательный стержень
		hanoi ( from, tmp, n - 1 );
		MoveDisk ( from, to );
		hanoi ( tmp, to, n - 1 );
	}
}