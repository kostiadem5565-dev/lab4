#include <iostream>
#include <stdlib.h>
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");

    int arr[100], N, count = 0;
    cout << "Введите длину массива: ";
    cin >> N;

    cout << "Первоначальный массив: ";
    for (int i = 0; i < N; i++)
    {
        arr[i] = rand() % 20 - 10;
        cout << arr[i] << ' ';
    }
    cout << endl;
  
    for (int i = 0; i < N; i += 2)
    {
        int key = arr[i];
        count ++;
        for (int j = i; j < N; j++)
        {
            arr[j] = arr[j+1];
            arr[j+1] = key;
        }
        N --;
    }

    cout << "Массив, в котором удалены элементы с индексами, кратными 3: ";
    for (int i = 0; i < N; i++) cout << arr[i] << ' ';
    cout << endl;

    for (int i = 0; i < N; i++)
    {
        if (arr[i] < 0)
        {
            int key1 = arr[i+1], key2;
            arr[i+1] = abs(arr[i] + 1);
            for (int j = i+2; j <= N; j++)
            {
                key2 = arr[j];
                arr[j] = key1;
                key1 = key2;
            }
            N++;
        }
    }

    cout << "Массив, в котором после каждого отрицательного элемента добавлен элемент со зназчением |M[ I-1 ]+1|: ";
    for (int i = 0; i < N; i++) cout << arr[i] << ' ';
    cout << endl;

    return 0;
}