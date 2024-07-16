#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int* internal_arr;
	int starting;
	int adjusted_len;
	int capacity;
} cleque;


void populate_cleque (cleque* input_cleque, int* input_array, int size);

int cleque_getAt (int number, cleque* input);

void cleque_changeAt (int number, cleque* input, int newVal);

int cleque_pop_back (cleque* input);

int cleque_pop_front (cleque* input); 

void cleque_push_back (cleque* input, int val);

void cleque_push_front (cleque* input, int val);

int cleque_pop_at (cleque* input, int index);

void print_cleque (cleque* input);

void free_cleque (cleque* input);
