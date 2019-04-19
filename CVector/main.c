#include "vector.h"

int cmp(const void* a, const void* b)
{
    return (char)(*(void**)a) - (char)(*(void**)b);
}

void print(vector* v)
{
    for (int i = 0; i < v->size; i++)
    {
        printf(i != v->size - 1 ? "%c, " : "%c", vector_get(v, i));
    }
    printf("\n");
}

int main()
{
    vector v1;
    vector v2;
    vector v3;

    vector_init(&v1);
    vector_init(&v2);
    vector_init(&v3);

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

    vector_sub_list(&v3, &v1, 0, 8);
    print(&v3);

    vector_shrink(&v1);
    vector_shrink(&v2);

    print(&v1);
    print(&v2);

    vector_resize(&v1, 3);
    vector_resize(&v2, 2);

    vector_add_all(&v2, &v1);

    print(&v1);
    print(&v2);

    vector_destroy(&v1);
    vector_destroy(&v2);

    return 0;
}
