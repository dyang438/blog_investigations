#include <stdio.h>
#include <stdlib.h>

typedef struct deque_node 
{
	int payload;
	struct deque_node* next;
	struct deque_node* prev;
} 
deque_node;


typedef struct deque
{
	struct deque_node* first;
	struct deque_node* last;
	int length;
}
deque;


deque* init_deque() {
	deque* ret = malloc(sizeof(deque));
	ret->first = NULL;
	ret->last = NULL;
	return ret;
}

void deque_push_front (deque* input, int val)
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

int main() {
	deque* main = init_deque();
	deque_push_front(main, 2);
}
