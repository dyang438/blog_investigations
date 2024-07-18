#include <stdio.h>
#include "deque.h"
#include "test_timing.h"

#define TEST_SIZE 10
#define MOVING_SIZE 10

int test_one (deque* main_deque);

int test_two (deque* main_deque);

int test_three (deque* main_deque);

int test_four (deque* main_deque);

int main () 
{
	fprintf(stderr, "Starting moving test with TEST_SIZE = %d and MOVING_SIZE = %d\n", TEST_SIZE, MOVING_SIZE);

	deque* deque_1 = init_deque();
	test_one(deque_1);
	free_deque(deque_1);

	deque* deque_2 = init_deque();
	test_two(deque_2);
	free_deque(deque_2);

	deque* deque_3 = init_deque();
	test_three(deque_3);
	free_deque(deque_3);

	deque* deque_4 = init_deque();
	test_four(deque_4);
	free_deque(deque_4);
}


int test_one (deque* main_deque) 
{
	char* test_name = "Deque Test Push_front Pop_Front";

	for (int i = 0; i < MOVING_SIZE; i++) 
	{ 
		deque_push_back(main_deque, i, 1);
	}

	fprintf(stderr, "length %d\n", main_deque->length);

	clock_t start_time = timer_start_time(test_name);

	for (int i = 0; i < TEST_SIZE; i++)
	{
		deque_push_front(main_deque, i, 1);
		deque_pop_front(main_deque);
	}

	timer_end_time (test_name, start_time);

	fprintf(stderr, "length %d\n", main_deque->length);

	if (main_deque->length == MOVING_SIZE)
	{
		fprintf(stderr, "%s: Passed!\n", test_name);
	}
	else fprintf(stderr, "%s: Failed\n", test_name);

	return 0;
}


int test_two (deque* main_deque) 
{
	char* test_name = "Deque Test Push_back Pop_Front";


	for (int i = 0; i < MOVING_SIZE; i++) 
	{ 
		deque_push_back(main_deque, i, 0);
	}

	clock_t start_time = timer_start_time(test_name);

	for (int i = 0; i < TEST_SIZE-3; i++)
	{
		deque_push_back(main_deque, i, 1);
		deque_pop_front(main_deque);
	}


	timer_end_time (test_name, start_time);

	if (main_deque->length == MOVING_SIZE) 
	{
		fprintf(stderr, "%s: Passed!\n", test_name);
	}
	else fprintf(stderr, "%s: Failed\n", test_name);

	return 0;
}


int test_three (deque* main_deque) 
{
	char* test_name = "Deque Test Push_front Pop_back";


	for (int i = 0; i < MOVING_SIZE; i++) 
	{ 
		deque_push_back(main_deque, i, 0);
	}

	clock_t start_time = timer_start_time(test_name);

	for (int i = 0; i < TEST_SIZE-3; i++)
	{
		deque_push_front(main_deque, i, 1);
		deque_pop_back(main_deque);
	}


	timer_end_time (test_name, start_time);

	if (main_deque->length == MOVING_SIZE) 
	{
		fprintf(stderr, "%s: Passed!\n", test_name);
	}
	else fprintf(stderr, "%s: Failed\n", test_name);

	return 0;
}


int test_four (deque* main_deque) 
{
	char* test_name = "Deque Test Push_back Pop_back";

	for (int i = 0; i < MOVING_SIZE; i++) 
	{ 
		deque_push_back(main_deque, i, 0);
	}

	clock_t start_time = timer_start_time(test_name);
	
	for (int i = 0; i < TEST_SIZE-3; i++)
	{
		deque_push_back(main_deque, i, 1);
		deque_pop_back(main_deque);
	}


	timer_end_time (test_name, start_time);

	if (main_deque->length == MOVING_SIZE) 
	{
		fprintf(stderr, "%s: Passed!\n", test_name);
	}
	else fprintf(stderr, "%s: Failed\n", test_name);

	return 0;
}

