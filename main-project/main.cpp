#include <iostream>
#include <iomanip>

using namespace std;

#include "precipitation.h"
#include "file_reader.h"
#include "constants.h"
#include "filter.h"

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
            cout << setw(2) << setfill('0') << precipitations[i]->day.day << "\n";
            cout << "Месяц...........: ";
            // вывод месяца
            cout << setw(2) << setfill('0') << precipitations[i]->day.month << "\n";
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

        bool (*check_function)(precipitation*) = NULL; // check_function - это указатель на функцию, возвращающую значение типа bool,
                                                         // и принимающую в качестве параметра значение типа book_subscription*
        cout << "\nВыберите способ фильтрации или обработки данных:\n";
        cout << "1) Все дни, в которые шёл дождь.\n";
        cout << "2) Все дни, в которые объём осадков был меньше 1,5.\n";
        cout << "\nВведите номер выбранного пункта: ";
        int item;
        cin >> item;
        cout << '\n';
        switch (item)
        {
        case 1:
            check_function = check_results_by_type; // присваиваем в указатель на функцию соответствующую функцию
            cout << "***** Протокол использования сети Интернет программой Skype *****\n\n";
            break;
        case 2:
            check_function = check_results_by_value; // присваиваем в указатель на функцию соответствующую функцию
            cout << "***** Протокол использования сети Интернет после 8:00:00 *****\n\n";
            break;
        default:
            throw "Некорректный номер пункта";
        }
        if (check_function)
        {
            int new_size;
            precipitation** filtered = filter(precipitations, size, check_function, new_size);
            for (int i = 0; i < new_size; i++)
            {
                /********** вывод даты **********/
                cout << "День............: ";
                // вывод дня
                cout << setw(2) << setfill('0') << filtered[i]->day.day << "\n";
                cout << "Месяц...........: ";
                // вывод месяца
                cout << setw(2) << setfill('0') << filtered[i]->day.month << "\n";
                /********** вывод количества **********/
                cout << "Количество......: ";
                // вывод количества осадков в мм
                cout << filtered[i]->value << '\n';
                /********** вывод типа **********/
                cout << "Характеристика..: ";
                // вывод типа осадков
                cout << filtered[i]->type << '\n';
                cout << "\n";
            }
            delete[] filtered;
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