#include "vector.h"

int cmp(const void* a, const void* b) {
	return (char)(*(void**)a) - (char)(*(void**)b);
}

int main() {
	vector v;

	vector_init(&v);

	vector_add(&v, 'P');
	vector_add(&v, 'K');
	vector_add(&v, 'A');
	vector_add(&v, 'D');
	vector_add(&v, 'E');
	vector_add(&v, 'J');
	vector_add(&v, 'M');

	vector_sort(&v, cmp);

	vector_remove(&v, 2);

	for (int i = 0; i < v.size; i++) {
		printf(i != v.size - 1 ? "%c, " : "%c", vector_get(&v, i));
	}

	vector_destroy(&v);

	return 0;
}
