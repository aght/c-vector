#ifndef _VECTOR_
#define _VECTOR_

#include "vector.h"

#define ALLOC_BLOCK_SIZE 10

bool index_in_range(vector *, size_t);

void vector_init(vector *v) {
    v->size = 0;
    v->capacity = 0;
    v->data = NULL;
}

void vector_destroy(vector *v) {
    free(v->data);

    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

bool vector_add(vector *v, void *e) {
    if (v->size == 0) {
        v->data = malloc(ALLOC_BLOCK_SIZE * sizeof(void *));

        if (!v->data) {
            return false;
        }

        v->capacity = ALLOC_BLOCK_SIZE;
    }

    if (v->size == v->capacity) {
        void **tmp = realloc(v->data, (v->size + ALLOC_BLOCK_SIZE) * sizeof(void *));

        if (!tmp) {
            return false;
        }

        v->data = tmp;
        v->capacity += ALLOC_BLOCK_SIZE;
    }

    v->data[v->size] = e;
    v->size++;

    return true;
}

bool vector_remove(vector *v, size_t index) {
    if (!index_in_range(v, index)) {
        return false;
    }

    memcpy(&v->data[index], &v->data[index + 1], (v->capacity - index) * sizeof(void *));

    v->size--;

    return true;
}

void *vector_get(vector *v, size_t index) {
    if (!index_in_range(v, index)) {
        return NULL;
    }

    return v->data[index];
}

bool vector_set(vector *v, size_t index, void *e) {
    if (!index_in_range(v, index)) {
        return false;
    }

    v->data[index] = e;

    return true;
}

bool vector_shrink(vector *v) {
    void **tmp = malloc(v->size * sizeof(void *));

    if (!tmp) {
        return false;
    }

    for (size_t i = 0; i < v->size; i++) {
        tmp[i] = v->data[i];
    }

    free(v->data);

    v->data = tmp;
    v->capacity = v->size;

    return true;
}

bool vector_contains(vector *v, int (*cmp)(const void *, const void *), void *e) {
    for (size_t i = 0; i < v->size; i++) {
        if (cmp(&e, &v->data[i]) == 0) {
            return true;
        }
    }

    return false;
}

void *vector_bsearch(vector *v, int (*cmp)(const void *, const void *), void *e) {
    int l = 0;
    int h = v->size - 1;

    while (l <= h) {
        int mid = l + (h - l) / 2;

        if (cmp(&e, &v->data[mid]) == 0) {
            return &v->data[mid];
        } else if (cmp(&e, &v->data[mid]) < 0) {
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return NULL;
}

void insertion_sort(vector *v, int (*cmp)(const void *, const void *)) {
    long long i, j;
    void *p;

    for (i = 1; i < v->size; i++) {
        p = v->data[i];
        j = i - 1;

        while (j >= 0 && cmp(&p, &v->data[j]) < 0) {
            v->data[j + 1] = v->data[j];
            j = j - 1;
        }

        v->data[j + 1] = p;
    }
}

void quick_sort(vector *v, int (*cmp)(const void *, const void *)) {
    
}

void vector_sort(vector *v, int (*cmp)(const void *, const void *)) {
    // qsort(v->data, v->size, sizeof(void *), cmp);
    insertion_sort(v, cmp);
}

bool index_in_range(vector *v, size_t index) {
    return (index >= v->size || index < 0) ? false : true;
}

#endif