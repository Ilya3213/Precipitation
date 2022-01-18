#include "processing.h";

long double process(precipitation* precipitations[], int size, int month)
{
	long double sum = 0;
	if (month <= 12 && month > 0) {
		for (int i = 0; i < size; i++) {
			if (precipitations[i]->day.month == month) {
				sum += precipitations[i]->value;
			}
		}
	}
	
	return sum;
}