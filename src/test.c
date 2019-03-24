#include "vector.h"

int cmp(const void *a, const void *b) {
    return (char)(*(void **)a) - (char)(*(void **)b);
}

int main() {
    vector v;

    vector_init(&v);

    for (int i = 65 + 26 - 1; i >= 65; i--) {
        vector_add(&v, (char)i);
    }

    vector_sort(&v, cmp);

    char *cptr = vector_bsearch(&v, cmp, 'G');
    if (cptr) {
        printf("Found: %c\n", *cptr);
    } else {
        printf("Not found\n");
    }

    for (int i = 0; i < v.size; i++) {
        printf(i < v.size - 1 ? "%c, " : "%c", vector_get(&v, i));
    }
    printf("\n");

    printf("Contains B: %s\n", vector_contains(&v, cmp, 'B') == true ? "true" : "false");
    printf("Contains 9: %s\n", vector_contains(&v, cmp, '9') == true ? "true" : "false");

    vector_destroy(&v);

    return 0;
}
