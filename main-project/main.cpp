#include <iostream>

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
        for (int i = 0; i < size; i++)
        {
            cout << precipitations[i]->day.day << '\n';
            cout << precipitations[i]->day.month << '\n';
            cout << precipitations[i]->value << '\n';
            cout << precipitations[i]->type << '\n';
            
            cout << '\n';
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