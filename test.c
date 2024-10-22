#include "vec.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

int main(void) {
    int* vector = newvec(int, 0);

	assert(vector != NULL);

	vector[0] = 2;
	vecpush(vector, 3);
	assert(vector[1] == 3);

	int* removedelem = vecpop(vector);
	printf("%d\n", *removedelem);
	assert(*removedelem == 3);
    return 0;
}
