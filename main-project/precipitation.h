#ifndef PRECIPITATION_H
#define PRECIPITATION_H

#include "constants.h"

struct date
{
    int day;
    int month;
};

struct precipitation
{
    date day;
    long double value;
    char type[MAX_STRING_SIZE];
};

#endif