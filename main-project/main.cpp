#include <iostream>
#include <iomanip>

using namespace std;

#include "precipitation.h"
#include "file_reader.h"
#include "constants.h"

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
            cout << precipitations[i]->day.day << '\n';
            cout << "�����...........: ";
            // ����� ������
            cout << precipitations[i]->day.month << '\n';
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