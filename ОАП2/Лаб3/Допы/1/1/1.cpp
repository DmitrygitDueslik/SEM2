#include <iostream>
using namespace std;

char books[100][50];

// Статическая  общее число взятых книг
static int total = 0;

void takeBook ( )
{
    char name[50];      // локальная переменная
    int id;             // локальная переменная 

    cout << "ID: ";
    cin >> id;
    cin.ignore ( );       // пропустить Enter

    cout << "Название: ";
    cin.getline ( name, 50 );  // читаем строку с пробелами

    register int r = id;    // регистровая переменная — временно хранит ID

    if ( r >= 0 && r < 100 ) {
        // Копируем name  books[r]
        for ( int i = 0; i < 50; i++ ) {
            books[r][i] = name[i];
            if ( name[i] == '\0' ) break;
        }
        total++;  // статический счётчик
        cout << " Взята!\n";
    }
}

int main ( )
{
    takeBook ( );
    takeBook ( );
    cout << "\nВсего взято: " << total << endl;
    return 0;
}