#include "filter.h"
#include <cstring>
#include <iostream>

precipitation** filter(precipitation* array[], int size, bool (*check)(precipitation* element), int& result_size)
{
	precipitation** result = new precipitation * [size];
	result_size = 0;
	for (int i = 0; i < size; i++)
	{
		if (check(array[i]))
		{
			result[result_size++] = array[i];
		}
	}
	return result;
}

bool check_results_by_type(precipitation* element)
{
	return strcmp(element->type, "дождь") == 0;
}

bool check_results_by_value(precipitation* element)
{
	return element->value < 1.5;
}