#ifndef VECTOR_C
#define VECTOR_C

#include <stddef.h>
#include <stdlib.h>

#define HEADER_SIZE 3

typedef int* vec;

#define veclen(vec) vec[-HEADER_SIZE + 1]

#define vecsize(vec) vec[-HEADER_SIZE + 2]

#define elemsize(vec) vec[-HEADER_SIZE]

/*
 * Return a new pointer of given type with `len` length.
 * Caller is responsible of freeing the vector.
 * */
#define newvec(type, len) ({                                                    \
	type *vector = malloc(len * sizeof (type) + sizeof (type) * HEADER_SIZE);   \
	vector[0] = sizeof (type);                                                  \
	vector[1] = len;                                                            \
	vector[2] = len * sizeof (type);                                            \
	vector += HEADER_SIZE;                                                      \
	vector;                                                                     \
})\

#define vecpush(vec, elem) ({                                                   \
	vec -= HEADER_SIZE;                                                         \
	vec = realloc(vec, vecsize(vec) + elemsize(vec) + HEADER_SIZE);             \
	vec += HEADER_SIZE;                                                         \
	vec[-1] += vec[-3];                                                         \
	vec[-2]++;                                                                  \
	vec[veclen(vec)] = elem;                                                    \
	0;																			\
})

#define vecpop(vec) ({															\
	void* elem = &(vec[veclen(vec)]);											\
	vec[veclen(vec)] = 0;														\
	vec -= HEADER_SIZE;                                                         \
	vec = realloc(vec, vecsize(vec) - elemsize(vec) + HEADER_SIZE);             \
	vec += HEADER_SIZE;                                                         \
	vec[-1] += vec[-3];                                                         \
	vec[-2]--;                                                                  \
	elem;																		\
})
#endif
