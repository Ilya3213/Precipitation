#ifndef FILTER_H
#define FILTER_H

#include "precipitation.h"

precipitation** filter(precipitation* array[], int size, bool (*check)(precipitation* element), int& result_size);

bool check_results_by_type(precipitation* element);

bool check_results_by_value(precipitation* element);

#endif