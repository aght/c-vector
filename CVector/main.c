#include "vector.h"

int cmp(const void* a, const void* b) {
	return (char)(*(void**)a) - (char)(*(void**)b);
}

void print(vector* v) {
	for (int i = 0; i < v->size; i++) {
		printf(i != v->size - 1 ? "%c, " : "%c", vector_get(v, i));
	}
	printf("\n");
}

int main() {
	vector v1;
    vector v2;

	vector_init(&v1);
    vector_init(&v2);

	vector_add(&v1, 'P');
	vector_add(&v1, 'K');
	vector_add(&v1, 'A');
	vector_add(&v1, 'D');
	vector_add(&v1, 'E');
	vector_add(&v1, 'J');
	vector_add(&v1, 'M');
	vector_add(&v1, 'S');

    vector_add(&v2, 'L');
    vector_add(&v2, '9');
    vector_add(&v2, 'R');

    vector_shrink(&v1);
    vector_shrink(&v2);

	print(&v1);
    print(&v2);

    vector_add_all(&v1, &v2);

    vector_shrink(&v1);

    print(&v1);
    print(&v2);

    printf("index of L: %d\n", vector_rfind(&v1, 'L'));
    printf("index of K: %d\n", vector_find(&v1, 'K'));
    printf("cmp index of L: %d\n", vector_rfindc(&v1, 'L', cmp));
    printf("cmp index of K: %d\n", vector_findc(&v1, 'K', cmp));

	vector_destroy(&v1);
    vector_destroy(&v2);

	return 0;
}
