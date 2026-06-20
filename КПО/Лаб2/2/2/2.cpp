#include <iostream>
#include <limits.h>
#include <float.h>
#include <math.h>
using namespace std;

int raz ( int x, int y ) { return x - y; }
int(*f)(int, int);

int main ( )
{
	// Исходные данные (n = 5, фамилия: Зырянов)
	int n = 5, X = 9 + n, Y = 10 + n, Z = 11 + n;
	float S = 6.0;

	// 4. bool (1 байт)
	bool tr = true;   // 01
	bool fal = false; // 00

	// 5-6. char (1 байт)
	char c_eng = 'y'; // 2-й символ лат. фамилии: 0x79 (ASCII)
	char c_ru = 'ы'; // 2-й символ рус. фамилии: 0xFB (Windows-1251)

	// 7-8. wchar_t (2 байта)
	wchar_t wc_eng = L'Z'; // 1-й символ лат: 0x005A (UTF-16LE: 5A 00)
	wchar_t wc_ru = L'З'; // 1-й символ рус: 0x0417 (UTF-16LE: 17 04)

	//  9. short (2 байта), X = 14
	short s_p = X;   // 14  = 0x000E → в памяти: 0E 00
	short s_m = -X;  // -14 = 0xFFF2 → в памяти: F2 FF

	//-X = -14:
	//	Шаг 1: 14 = 00000000 00001110
	//   Шаг 2: инверсия = 11111111 11110001
	//   Шаг 3: +1 = 11111111 11110010 = 0xFFF2

	//  10. short min/max
	short s_min = 0x8000; // -32768 = 0x8000
	short s_max = 0x7fff; //  32767 = 0x7FFF

	//  11. unsigned short
	unsigned short us_min = 0x0;
	unsigned short us_max = 0xffff; // 0 ... 0xFFFF max = 65535,

	//  12. int (4 байта), Y = 15
	int i_p = Y;   // 15  = 0x0000000F -> 0F 00 00 00
	int i_m = -Y;  // -15 = 0xFFFFFFF1 -> F1 FF FF FF

	//(15)  (00001111)->(00001111)->(00001111->)hex(0x0000000F)
	//(-15) (00001111)->(11110000)->(11110001)->hex(0xFFFFFFF1)

	//  13-14. int min/max
	int i_min = 0x80000000;
	int i_max = 0x7fffffff;
	unsigned int ui_min = 0x0;
	unsigned int ui_max = 0xffffffff;

	//  15. long (4 байта в 86x), Z = 16
	long l_p = Z;   // 16  = 0x00000010 -> 10 00 00 00
	long l_m = -Z;  // -16 = 0xFFFFFFF0 -> F0 FF FF FF

	//  16-17. long min/max
	long l_min = 0x80000000;
	long l_max = 0x7fffffff;
	unsigned long ul_min = 0x0;
	unsigned long ul_max = 0xffffffff;

	//  18. float (IEEE 754), S = 6.0
	float f_p = S;   // 6.0  = 0x40C00000 -> 00 00 C0 40
	float f_m = -S;  // -6.0 = 0xC0C00000 -> 00 00 C0 C0
	//Знак = 0 (положительное)
	//Экпонента = 2 + 127 = 129 = 10000001
	// Мантисса = 10000000000000000000000 (дробная часть 1.1)
	// Биты: 0 10000001 10000000000000000000000
	// Hex: 0100 0000 1100 0000 0000... = 0x40C00000
	// Для -6.0 знак -1
	//  Hex: 1100 0000 1100 0000 0000... = 0xС0C00000
	//  19. INF / IND
	float q1 = S / 0.0;     // 1.#INF
	cout << "q1 - " << q1 << endl;
	float q2 = -S / 0.0;    // -1.#INF
	cout << "q2 - " << q2 << endl;
	double q3 = sqrt ( -18.0 ); // -1.#IND
	cout << "q3 - " << q3 << endl;

	//  20. Указатели + арифметика
	char c0 = 'a'; // один символ один байт
	wchar_t wc0 = L'б'; // один символ один байт
	short s0 = 1;
	int i0 = 2;
	float f0 = 3.1;
	double d0 = 4.0001;

	char* pc = &c0; // eb fc 99 00
	wchar_t* pwc = &wc0; //dc fc 99 00
	short* ps = &s0;//d0 fc 99 00
	int* pi = &i0; //c4 fc 99 00
	float* pf = &f0; //b8 fc 99 00
	double* pd = &d0;//a8 fc 99 00

	// После +3: , , ps+=3 (×2)(6), pi+=3 (×4)(12), pf+=3 (×4)(12), pd+=3 (×8)(24)
	char* pc1 = pc + 3; //ee fc 99 00  pc+=3 (×1)(3байт)
	wchar_t* pwc1 = pwc + 3;//e2 fc 99 00  pwc+=3 (×2)(6байт)
	short* ps1 = ps + 3; //d6 fc 99 00  ps+=3 (×2)(6байт)
	int* pi1 = pi + 3;//d0 fc 99 00   pi+=3 (×4)(12байт)
	float* pf1 = pf + 3; //c4 fc 99 00  pf+=3 (×4)(12байт)
	double* pd1 = pd + 3;//c0 fc 99 00  pd+=3 (×8)(24байт)

	//  21. Ссылки
	char& rc = c0; //61
	wchar_t& rwc = wc0; //31 04
	short& rs = s0;//01 00
	int& ri = i0;//02 00 00 00
	float& rf = f0; //66 66 46 40
	double& rd = d0;//1c eb e2 36 1a 00 10 40

	//  22. Указатель на функцию
	f = raz;
	int res = f ( 17, 13 );  // 4
	cout << "Result: " << res << endl;

	return 0; // точка останова для отладки
}