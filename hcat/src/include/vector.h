#ifndef VECTOR_H
#define VECTOR_H

#include "common.h"

// General sequence macros
#define seq_elem_type(seq) typeof(*(seq)->elements)

#define seq_start(seq) ((seq)->elements)
#define seq_end(seq) ((seq)->elements + (seq)->length)

#define seq_len(seq) ((seq)->length)

#define make_slice(T, start, length) ((slice(T)){start, length})
#define vec_slice(vec, low, high)                                                                  \
    {                                                                                              \
        (high) - (low), vec_start(vec) + (low)                                                     \
    }

#define for_each(seq, iter)                                                                        \
    for (seq_elem_type(seq) * (iter) = seq_start(seq); (iter) < seq_end(seq); (iter)++)

// Slice type

#define slice(T) slice_##T

#define decl_slice(T)                                                                              \
    typedef struct                                                                                 \
    {                                                                                              \
        size_t length;                                                                             \
        T *elements;                                                                               \
    } slice(T)

// Vector type
#define VEC_GROWTH_RATE 2
#define vec(T) vector_##T
#define decl_vec(T)                                                                                \
    typedef struct                                                                                 \
    {                                                                                              \
        size_t length;                                                                             \
        size_t capacity;                                                                           \
        T elements[];                                                                              \
    } * vec(T);                                                                                    \
    decl_slice(T)

// Vector implementation

#define vec_total_size(vec) (sizeof(vector_header) + (vec)->capacity * sizeof(seq_elem_type(vec)))

typedef struct
{
    size_t length;
    size_t capacity;
} vector_header;

static inline void *new_vec(vector_header *header)
{
    header->length = 0;
    header->capacity = 4;
    return header;
}

#define new_vec(T) new_vec(malloc(sizeof(vector_header) + 4 * sizeof(T)))
#define free_vec(vec) free(vec)

#define vec_push(vec, ...)                                                                         \
    do                                                                                             \
    {                                                                                              \
        if ((vec)->length + 1 == (vec)->capacity)                                                  \
        {                                                                                          \
            (vec)->capacity *= VEC_GROWTH_RATE;                                                    \
            (vec) = realloc(vec, vec_total_size(vec));                                             \
        }                                                                                          \
        (vec)->elements[(vec)->length++] = __VA_ARGS__;                                            \
    } while (0)

#define vec_start(vec) seq_start(vec)
#define vec_end(vec) seq_end(vec)

#define vec_len(vec) seq_len(vec)

#endif /* VECTOR_H */
