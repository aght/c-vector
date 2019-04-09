#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	size_t size;
	size_t capacity;
	void** data;
} vector;

void vector_init(vector*);
void vector_destroy(vector*);

bool vector_add(vector*, void*);
bool vector_remove(vector*, size_t);

void* vector_get(vector*, size_t);
bool vector_set(vector*, size_t, void*);

bool vector_shrink(vector*);

bool vector_contains(vector*, int (*)(const void*, const void*), void*);
void* vector_bsearch(vector*, int (*)(const void*, const void*), void*);
void vector_sort(vector*, int (*)(const void*, const void*));

#endif
