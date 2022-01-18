#include <iostream>
#include <iomanip>

using namespace std;

#include "precipitation.h"
#include "file_reader.h"
#include "constants.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Лабораторная работа №8. GIT\n";
    cout << "Вариант №3. Осадки\n";
    cout << "Автор: Илья Вежик\n\n";
    precipitation* precipitations[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", precipitations, size);
        cout << "***** Осадки *****\n\n";
        for (int i = 0; i < size; i++)
        {
            /********** вывод даты **********/
            cout << "День............: ";
            // вывод дня
            cout << precipitations[i]->day.day << '\n';
            cout << "Месяц...........: ";
            // вывод месяца
            cout << precipitations[i]->day.month << '\n';
            /********** вывод количества **********/
            cout << "Количество......: ";
            // вывод количества осадков в мм
            cout << precipitations[i]->value << '\n';
            /********** вывод типа **********/
            cout << "Характеристика..: ";
            // вывод типа осадков
            cout << precipitations[i]->type << '\n';
            cout << "\n";
        }
        for (int i = 0; i < size; i++)
        {
            delete precipitations[i];
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }
    return 0;
}