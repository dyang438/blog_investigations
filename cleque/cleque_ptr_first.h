#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

typedef struct {
	int* internal_arr;
	int adjusted_len;
} cleque_ptr;

cleque_ptr* init_cleque_ptr (int* input_arr, int size) 
{
	cleque_ptr* ret = (cleque_ptr*) malloc(sizeof(cleque_ptr)); 
	if (!ret) {
		exit(-1);
	}
	ret->adjusted_len = 0;
	if (!input_arr) {
		ret->internal_arr = NULL;
		ret->internal_arr = 0;
	}
	ret->internal_arr = input_arr;
	ret->adjusted_len = size;
	return ret;
}

int getAt (int number, cleque_ptr* input_cleque)
{
	//Defensive programming
	if (number >= input_cleque->adjusted_len || number < 0) {
		fprintf(stderr, "changeAt call out of bounds at %d", number);
		exit(-1); 
	}

	return input_cleque->internal_arr[number];
}

void changeAt (int number, cleque_ptr* input_cleque, int newVal) 
{
	if (number >= input_cleque->adjusted_len || number < 0) {
		fprintf(stderr, "changeAt call out of bounds at %d", number);
		exit(-1);
	}
	input_cleque->internal_arr[number] = newVal;

}

int pop_back (cleque_ptr* input_cleque) {
	int ret = input_cleque->internal_arr[input_cleque->adjusted_len - 1];
	input_cleque->adjusted_len--;
	return ret;
}

/*
Here is where the fun would theoretically start
*/

int pop_front (cleque_ptr* input_cleque) {
	// The point of this exercise is to see what happens when you just move the pointer of an array over
	int ret = input_cleque->internal_arr[0];
	input_cleque->internal_arr = input_cleque->internal_arr + 1;
	input_cleque->adjusted_len--;
	return ret;
}

/*
Here is where the pain begins in practice
*/

int pop_at (cleque_ptr* input_cleque, int idx) {
	int breaking_point = input_cleque->adjusted_len/2;
	bool direction_forwards = idx > breaking_point ? false : true;
	if (breaking_point > idx) {
		for (int i = 0; i <= idx; i++) {
			
		}
		
	} else {
		for (int i = input_cleque->adjusted_len; i >= idx; i--) {
			
		}
	}
}

/*
Debugging statement look away!
*/

void print_all (cleque_ptr* input_cleque) {
	fprintf(stdout, "adjusted_len = %d\n", input_cleque->adjusted_len);
	fprintf(stdout, "[");
	for (int i = 0; i < input_cleque->adjusted_len; i++) {
		fprintf(stdout, "%d, ", input_cleque->internal_arr[i]);
	}
	fprintf(stdout, "]");
}
