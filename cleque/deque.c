#include <stdio.h>
#include <stdlib.h>
#include "deque.h"


deque* init_deque (int* array, int size) 
// Invariant is that array == size, common usage wouldn't have either have values, so default is (NULL, 0) as args
{
	deque* ret_deque = malloc(sizeof(deque));
	ret_deque->length = size;
	if (!ret_deque) 
	{
		fprintf(stderr, "call to malloc failed on deque");
	}

	if (!array) 
	{
		ret_deque->first = NULL;
		ret_deque->last = NULL;
		return ret_deque;
	}
	
	deque_node* head = malloc(sizeof(deque_node));
	if (!head)
	{
		fprintf(stderr, "call to malloc failed on deque_node");
	}
	head->payload = array[0];
	ret_deque->first = head;
	deque_node* iter = head;
	for (int i = 1; i < size; i++) 
	{
		deque_node* new = malloc(sizeof(deque_node));
		iter->next = new;
		new->payload = array[i];
		new->next = NULL;
		new->prev = iter;
		iter = iter->next;
	}	
	iter->next = head;
	ret_deque->last = iter;

	return ret_deque;
}


int deque_pop_front (deque* input)
{
	if (!input || !input->first) {
		exit(-1); 
	}

	int ret = input->first->payload;
	input->first->next->prev = input->last;
	input->last->next = input->first->next;
	input->first = input->first->next;
	input->length--;
	return ret;
}


int deque_pop_back (deque* input)
{
	if (!input || !input->first) {
		exit(-1); 
	}

	int ret = input->last->payload;
	input->first->prev = input->last->prev;
	input->last->prev->next = input->first;
	input->last = input->last->prev;
	input->length--;
	return ret;
}


void deque_push_front(deque *input, int val)
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

	input->first->prev = new;
	new->prev = input->last;
	new->next = input->first;
	input->last->next = new;
	input->first = new;
}


void deque_push_back(deque *input, int val)
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

	input->first->prev = new;
	new->prev = input->last;
	new->next = input->first;
	input->last->next = new;
	input->last = new;
}


void print_deque (deque* input) 
{
	fprintf(stderr, "[");

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
