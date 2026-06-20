#include <iostream>
using namespace std;

float historyfirst[10];
float historesecond[10];
char historyType[10][10];


int historySize = 0;

static float exchangeRate = 2.87;

void convert ( )
{
	float summ;
	char  from[4], to[4];
    cout << "Сумма: ";
    cin >> summ;
    cout << "Из (BYN/USD): ";
    cin >> from;
    cout << "В (BYN/USD): ";
    cin >> to;

    float result;
    int convr = 0;

    if ( from[0] == 'B' && to[0] == 'U' ) {
        convr = 1;
    }
    else if ( from[0] == 'U' && to[0] == 'B' ) {
        convr = 2;
    }
    else {
        cout << "Неверное направление\n"; 
        return;
    }
    
    if ( convr == 1 ) {
        result = summ / exchangeRate;
    }
    if ( convr == 2 ) {
        result = summ * exchangeRate;
    }

    register float res = result;
    historyfirst[historySize] = summ;
    historesecond[historySize] = res;
    //Использую 
    if ( convr == 1 ) {
        historyType[historySize][0] = 'B';
        historyType[historySize][1] = 'Y';
        historyType[historySize][2] = 'N';
        historyType[historySize][3] = '-';
        historyType[historySize][4] = '>';
        historyType[historySize][5] = 'U';
        historyType[historySize][6] = 'S';
        historyType[historySize][7] = 'D';
        historyType[historySize][8] = '\0';
    }
    else {
        historyType[historySize][0] = 'U';
        historyType[historySize][1] = 'S';
        historyType[historySize][2] = 'D';
        historyType[historySize][3] = '-';
        historyType[historySize][4] = '>';
        historyType[historySize][5] = 'B';
        historyType[historySize][6] = 'Y';
        historyType[historySize][7] = 'N';
        historyType[historySize][8] = '\0';
    }

    historySize++;
    cout << summ << " " << from << " = " << res << " " << to << "\n";
}

void showHistory ( )
{
    cout << "\n<<<<<<<История>>>>>>>\n";
    for ( int i = 0; i < historySize; i++ ) {
        cout << historyfirst[i] << "->" << historesecond[i]<<"("<<historyType[i]<<")\n";
    }
}

int main ( )
{
    cout << "Нынешний курс 1 USD = " << exchangeRate<<"\n";
    convert ( );
    convert ( );
    showHistory ( );
    return 0;
}