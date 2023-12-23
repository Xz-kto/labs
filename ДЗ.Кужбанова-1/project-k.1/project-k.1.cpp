#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    //Работа с одномерными массивами

    //1 и 2
    int array[10];

    for (int i{ 0 }; i < 10; i++) {
        array[i] = rand() % 21 - 10;
    }
    for (int i{ 0 }; i < 10; i++) {
        cout << array[i] << " ";
    }
    cout << " " << endl;

    //3
    int pol[5];

    for (int i{ 0 }; i < 5; i++) {
        cout << "Введите значение для элемента " << i << ": ";
        cin >> pol[i];
    }
    for (int i{ 0 }; i < 5; i++) {
        cout << pol[i] << " ";
    }
    cout << " " << endl;

    //4
    for (int i = 0; i < 10; i++) {
        if ((i + 1) % 2 == 0) {
            array[i] *= 3;
        }
        else {
            array[i] *= 5;
        }
    }
    for (int i{ 0 }; i < 10; i++) {
        cout << array[i] << " ";
    }
    cout << " " << endl;

    //Работа с двумерными массивами

    //1
    int dva[5][5];

    for (int i{ 0 }; i < 5; i++) {
        for (int j{ 0 }; j < 5; j++) {
            dva[i][j] = rand() % 21 - 10;
        }
    }

    //2
    for (int i{ 0 }; i < 5; i++) {
        int sum{ 0 };
        for (int j{ 0 }; j < 5; j++) {
            sum += dva[i][j];
        }
        cout << "Сумма в строке " << i + 1 << ": " << sum << endl;
    }

    //3
    for (int i{ 0 }; i < 5; i++) {
        for (int j{ 0 }; j < 5; j++) {
            if (dva[i][j] < 0) {
                dva[i][j] = 0;
            }
        }
    }

    for (int i{ 0 }; i < 5; i++) {
        for (int j{ 0 }; j < 5; j++) {
            cout << dva[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}