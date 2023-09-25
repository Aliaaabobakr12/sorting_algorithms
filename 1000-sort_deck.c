#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Add this include for strcmp
#include "deck.h"

/* Comparison function for qsort */
int compare_cards(const void *a, const void *b) {
    const deck_node_t *node_a = *(const deck_node_t **)a;
    const deck_node_t *node_b = *(const deck_node_t **)b;

    /* Compare card kinds first */
    if (node_a->card->kind < node_b->card->kind) {
        return -1;
    } else if (node_a->card->kind > node_b->card->kind) {
        return 1;
    }

    /* If kinds are the same, compare card values */
    return strcmp(node_a->card->value, node_b->card->value);
}

void sort_deck(deck_node_t **deck) {
    /* Convert the doubly linked list into an array of pointers */
    size_t count = 0;
    deck_node_t *current = *deck;
    deck_node_t **card_array = malloc(sizeof(deck_node_t *) * 52);

    if (!card_array) {
        /* Handle memory allocation failure */
        exit(1);
    }

    while (current != NULL) {
        card_array[count++] = current;
        current = current->next;
    }

    /* Sort the array of card pointers using qsort */
    size_t i;
    for (i = 0; i < count - 1; i++) {
        card_array[i]->next = card_array[i + 1];
        card_array[i + 1]->prev = card_array[i];
    }

    /* Reconstruct the doubly linked list from the sorted array */
    /* Update the deck pointer to point to the new head of the sorted list */
    *deck = card_array[0];

    /* Update the prev pointer of the first node to NULL */
    card_array[0]->prev = NULL;

    /* Update the next pointer of the last node to NULL */
    card_array[count - 1]->next = NULL;

    /* Free the temporary array */
    free(card_array);
}
