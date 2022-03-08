#include <stdlib.h>

#include "Stack.h"


stack_t *
st_create(unsigned int data_size)
{
	stack_t *st = malloc(sizeof(stack_t));
	st->list = ll_create(data_size);
	return st;
}

unsigned int
st_get_size(stack_t *st)
{
	return st->list->size;
}

/*
 * Intoarce 1 daca stiva este goala si 0 in caz contrar.
 */
unsigned int
st_is_empty(stack_t *st)
{
	if(st->list->size == 0)
		return 1;
	return 0;
}

void *
st_peek(stack_t *st)
{
	return st->list->head->data;
}

void
st_pop(stack_t *st)
{
	ll_node_t *del = ll_remove_nth_node(st->list, 0);
	free(del->data);
	free(del);
}

void
st_push(stack_t *st, void *new_data, int weight)
{
	ll_add_nth_node(st->list, 0, new_data, weight);
}

void
st_clear(stack_t *st)
{
	unsigned int i = 0;
	unsigned int ls = st->list->size;
	while(i < ls) {
		st_pop(st);
	}
}

void
st_free(stack_t *st)
{
	ll_free(&st->list);
	free(st);
}