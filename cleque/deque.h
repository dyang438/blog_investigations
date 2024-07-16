#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>


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


deque* init_deque (int* array, int size);

int deque_pop_front (deque* input);

int deque_pop_back (deque* input);

void deque_push_front(deque *input, int val);

void deque_push_back(deque *input, int val);

void print_deque(deque* input);
