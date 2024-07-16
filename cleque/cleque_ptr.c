#include <stdio.h>
#include <stdlib.h>

#include "cleque_ptr.h"


void populate_cleque (cleque* input_cleque, int* input_array, int size)
{
	input_cleque->starting = 0;
	input_cleque->internal_arr = input_array;
	input_cleque->adjusted_len = size;
	input_cleque->capacity = size;
}


int cleque_get_at (int number, cleque* input)
{
	//Defensive programming
	if (number >= input->adjusted_len + input->starting || number < input->starting) {
		fprintf(stderr, "changeAt call out of bounds at %d", number);
		exit(-1); 
	}

	return input->internal_arr[number + input->starting];
}


void cleque_change_at (int number, cleque* input, int newVal) 
{
	if (number >= input->adjusted_len + input->starting || number < 0) 
	{
		fprintf(stderr, "changeAt call out of bounds at %d", number);
		exit(-1);
	}
	input->internal_arr[number + input->starting] = newVal;
}


int cleque_pop_back (cleque* input) 
{
	int ret = input->internal_arr[input->adjusted_len - 1 + input->starting];
	input->adjusted_len--;
	return ret;
}


int cleque_pop_front (cleque* input) 
{
	// The point of this exercise is to see what happens when you just move the pointer of an array over
	int ret = input->internal_arr[input->starting];
	input->starting++;
	input->adjusted_len--;
	return ret;
}


void cleque_push_front (cleque* input, int val)
{

	if (input->starting) 
	{
		input->starting--; 
		input->adjusted_len++;
		input->internal_arr[input->starting] = val;
		return;
	}
	fprintf(stderr, "Input Cleque is full at the front\n");
}


void cleque_push_back (cleque* input, int val)
{
	if (input->starting + input->adjusted_len < input->capacity) 
	{
		input->adjusted_len++;
		input->internal_arr[input->starting + input->adjusted_len] = val;
		return;
	}
	fprintf(stderr, "Input Cleque is full at the back\n");
}
/*
Debugging statement look away!
*/

void print_cleque (cleque* input) 
{
	fprintf(stderr, "adjusted_len = %d\n", input->adjusted_len);
	fprintf(stderr, "starting = %d\n", input->starting);
	fprintf(stderr, "capacity = %d\n", input->capacity);
	fprintf(stderr, "[");
	for (int i = 0; i < input->adjusted_len; i++) {
		fprintf(stderr, "%d, ", input->internal_arr[i+input->starting]);
	}
	fprintf(stderr, "]");
}

