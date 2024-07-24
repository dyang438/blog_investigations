#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "deque.h"


deque* init_deque () 
// Invariant is that array == size, common usage wouldn't have either have values, so default is (NULL, 0) as args
{
	deque* ret_deque = malloc(sizeof(deque));
	ret_deque->first = ret_deque->last = NULL;
	ret_deque->length = 0;

	return ret_deque;
}


int deque_pop_front (deque* input)
{
	if (!input || !input->first) {
		fprintf(stderr, "Popped empty deque");
		exit(-1);
	}

	if (input->length)
	{
	}
	
	deque_node* popped = input->first;
	int ret = popped->payload;
	input->length--;

	if (input->length == 0) {
		free(popped);
		input->first = NULL;
		input->last = NULL;
		return ret;
	}

	input->first->next->prev = input->last;
	input->last->next = popped->next;
	input->first = popped->next;

	free(popped);
	
	return ret;
}


int deque_pop_back (deque* input)
{
	if (!input || !input->first) {
		fprintf(stderr, "Popped empty deque");
		exit(-1);
	}

	deque_node* popped = input->last;
	int ret = popped->payload;
	input->length--;

	if (input->length == 0) {
		free(popped);
		input->first = NULL;
		input->last = NULL;
		return ret;
	}

	input->first->prev = popped->prev;
	input->last->prev->next = input->first;
	input->last = popped->prev;

	free(popped);

	return ret;
}


void deque_push_front(deque *input, int val, int print)
{
	deque_node* new = malloc(sizeof(deque_node));

	new->payload = val;
	new->next = NULL;
	new->prev = NULL;
	input->length ++;

	if (!input->first || !input->last) {
		input->first = new;
		input->last = new;
	}

	if (print)
	{
		fprintf(stderr, "%p\t", new);
	}
	input->first->prev = new;
	new->prev = input->last;
	new->next = input->first;
	input->last->next = new;
	input->first = new;
}


void deque_push_back(deque *input, int val, int print)
{
	deque_node* new = malloc(sizeof(deque_node));
	new->payload = val;
	new->next = new;
	new->prev = new;
	input->length ++;

	if (!input->first || !input->last) {
		input->first = new;
		input->last = new;
	}
	if (print)
	{
		fprintf(stderr, "%p\t", new);
	}
	input->first->prev = new;
	new->prev = input->last;
	new->next = input->first;
	input->last->next = new;
	input->last = new;
}


void print_deque (deque* input) 
{
	fprintf(stderr, "[");
	
	if (input->length) {
		deque_node* iter = input->first;
		deque_node* last = input->last;
		while (iter != last) 
		{
			fprintf(stderr, "%d, ", iter->payload);
			iter = iter->next;
		}
		fprintf(stderr, "%d", iter->payload);
		fprintf(stderr, "]");
	}
}


void free_deque (deque* input)
{
	deque_node* iter = input->first;
	deque_node* last = input->last;
	while (iter != last) 
	{
		deque_node* ptr = iter;
		iter = iter->next;
		free(ptr);
	}
	free(iter);
	free(input);
}
