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
    cout << "������������ ������ �8. GIT\n";
    cout << "������� �3. ������\n";
    cout << "�����: ���� �����\n\n";
    precipitation* precipitations[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", precipitations, size);
        cout << "***** ������ *****\n\n";
        for (int i = 0; i < size; i++)
        {
            /********** ����� ���� **********/
            cout << "����............: ";
            // ����� ���
            cout << setw(2) << setfill('0') << precipitations[i]->day.day << "\n";
            cout << "�����...........: ";
            // ����� ������
            cout << setw(2) << setfill('0') << precipitations[i]->day.month << "\n";
            /********** ����� ���������� **********/
            cout << "����������......: ";
            // ����� ���������� ������� � ��
            cout << precipitations[i]->value << '\n';
            /********** ����� ���� **********/
            cout << "��������������..: ";
            // ����� ���� �������
            cout << precipitations[i]->type << '\n';
            cout << "\n";
        }

        bool (*check_function)(precipitation*) = NULL; // check_function - ��� ��������� �� �������, ������������ �������� ���� bool,
                                                         // � ����������� � �������� ��������� �������� ���� book_subscription*
        cout << "\n�������� ������ ���������� ��� ��������� ������:\n";
        cout << "1) ��� ���, � ������� ��� �����.\n";
        cout << "2) ��� ���, � ������� ����� ������� ��� ������ 1,5.\n";
        cout << "\n������� ����� ���������� ������: ";
        int item;
        cin >> item;
        cout << '\n';
        switch (item)
        {
        case 1:
            check_function = check_results_by_type; // ����������� � ��������� �� ������� ��������������� �������
            cout << "***** �������� ������������� ���� �������� ���������� Skype *****\n\n";
            break;
        case 2:
            check_function = check_results_by_value; // ����������� � ��������� �� ������� ��������������� �������
            cout << "***** �������� ������������� ���� �������� ����� 8:00:00 *****\n\n";
            break;
        default:
            throw "������������ ����� ������";
        }
        if (check_function)
        {
            int new_size;
            precipitation** filtered = filter(precipitations, size, check_function, new_size);
            for (int i = 0; i < new_size; i++)
            {
                /********** ����� ���� **********/
                cout << "����............: ";
                // ����� ���
                cout << setw(2) << setfill('0') << filtered[i]->day.day << "\n";
                cout << "�����...........: ";
                // ����� ������
                cout << setw(2) << setfill('0') << filtered[i]->day.month << "\n";
                /********** ����� ���������� **********/
                cout << "����������......: ";
                // ����� ���������� ������� � ��
                cout << filtered[i]->value << '\n';
                /********** ����� ���� **********/
                cout << "��������������..: ";
                // ����� ���� �������
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