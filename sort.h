#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdbool.h>

/* Definition of listint_t */
typedef struct listint_s
{
    int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

/* Provided print_array and print_list functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* 0. Bubble Sort */
void bubble_sort(int *array, size_t size);

/* 1. Insertion Sort */
void insertion_sort_list(listint_t **list);

/* 2. Selection Sort */
void selection_sort(int *array, size_t size);

/* 3. Quick Sort */
void quick_sort(int *array, size_t size);

/* Additional functions if needed */

#endif /* SORT_H */
