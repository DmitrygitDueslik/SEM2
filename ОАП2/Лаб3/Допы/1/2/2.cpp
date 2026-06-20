#include <iostream>
using namespace std;

// 1. Глобальная количество кандидатов
int candidateCount = 3;

// 2. Статический массив  сколько голосов получил каждый кандидат
static int votes[10] = {0};  //  до 10 кандидатов

// проголосовать по номеру
void vote(int choice) {
    // 3. Локальные для проверки и обработки
    int isValid = 0;

    if (choice >= 0 && choice < candidateCount) {
        votes[choice]++;      // добавляем голос
        isValid = 1;
    }

    if (isValid) {
        cout << "Голос за кандидата " << choice << " засчитан.\n";
    } else {
        cout << "Ошибка: нет кандидата с номером " << choice << "\n";
    }
}

//  найти и вывести победителя
void showWinner() {
    // 4. Регистровая пвременно хранит индекс лидера
    register int winner = 0;

    // Ищем кандидата с максимальным числом голосов
    for (int i = 1; i < candidateCount; i++) {
        if (votes[i] > votes[winner]) {
            winner = i;
        }
    }

    cout << "\n--- Результаты ---\n";
    for (int i = 0; i < candidateCount; i++) {
        cout << "Кандидат " << i << ": " << votes[i] << " голосов\n";
    }
    cout << "Победитель: кандидат " << winner 
         << " (" << votes[winner] << " голосов)\n";
}

int main() {
    cout << "Голосование среди " << candidateCount << " кандидатов (0–" 
         << candidateCount - 1 << ")\n\n";

   
    vote(0);
    vote(1);
    vote(0);
    vote(2);
    vote(0);

    showWinner();

    return 0;
}