#include "file_reader.h"
#include "constants.h"

#include <fstream>
#include <cstring>

void read(const char* file_name, precipitation* array[], int& size)
{
    std::ifstream file(file_name);
    if (file.is_open())
    {
        size = 0;
        char tmp_buffer[MAX_STRING_SIZE];
        while (!file.eof())
        {
            precipitation* item = new precipitation;
            file >> item->day.day;
            file >> item->day.month;
            file >> item->value;
            file.read(tmp_buffer, 1); // чтения лишнего символа пробела
            file.getline(item->type, MAX_STRING_SIZE);
            array[size++] = item;
        }
        file.close();
    }
    else
    {
        throw "Ошибка открытия файла";
    }
}