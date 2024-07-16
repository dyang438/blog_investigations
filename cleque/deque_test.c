#include <stdio.h>
#include "deque.h"
#include "test_timing.h"

#define TEST_SIZE 1000000


int test_one (deque* main_deque);

int test_two (deque* main_deque);

int test_three (deque* main_deque);

int test_four (deque* main_deque);

int main () 
{
	int input [TEST_SIZE];
	for (int i = 0; i < TEST_SIZE; i++) 
	{
		input[i] = i;
	}

	deque* deque_1 = init_deque(input, TEST_SIZE);

	test_one(deque_1);

	for (int i = 0; i < TEST_SIZE; i++) 
	{
		input[i] = i;
	}

	deque* deque_2 = init_deque(input, TEST_SIZE);

	test_two(deque_2);

	for (int i = 0; i < TEST_SIZE; i++) 
	{
		input[i] = i;
	}

	deque* deque_3 = init_deque(input, TEST_SIZE);

	test_three(deque_3);

	for (int i = 0; i < TEST_SIZE; i++) 
	{
		input[i] = i;
	}

	deque* deque_4 = init_deque(input, TEST_SIZE);

	test_four(deque_4);

}


int test_one (deque* main_deque) 
{
	char* test_name = "Deque Test Pop_Front";

	clock_t start_time = timer_start_time(test_name);

	for (int i = TEST_SIZE-1; i >= 3; i--) 
	{ 
		deque_pop_front(main_deque);
	}	

	timer_end_time (test_name, start_time);

	if (main_deque->length == 3) 
	{
		fprintf(stderr, "%s: Passed!\n", test_name);
	}
	else fprintf(stderr, "%s: Failed\n", test_name);

	return 0;
}


int test_two (deque* main_deque) 
{
	char* test_name = "Deque Test Pop_Back";

	clock_t start_time = timer_start_time(test_name);

	for (int i = TEST_SIZE-1; i >= 3; i--) 
	{ 
		deque_pop_back(main_deque);
	}	

	timer_end_time (test_name, start_time);

	if (main_deque->length == 3) 
	{
		fprintf(stderr, "%s: Passed!\n", test_name);
	}
	else fprintf(stderr, "%s: Failed\n", test_name);

	return 0;
}


int test_three (deque* main_deque) 
{
	char* test_name = "Deque Test push_front";


	for (int i = TEST_SIZE-1; i >= 3; i--) 
	{ 
		deque_pop_front(main_deque);
	}	

	clock_t start_time = timer_start_time(test_name);

	for (int i = 0; i <= TEST_SIZE-3; i++)
	{
		deque_push_front(main_deque, i);
	}

	timer_end_time (test_name, start_time);

	if (main_deque->length == TEST_SIZE + 1) 
	{
		fprintf(stderr, "%s: Passed!\n", test_name);
	}
	else fprintf(stderr, "%s: Failed\n", test_name);

	return 0;
}


int test_four (deque* main_deque) 
{
	char* test_name = "Deque Test push_back";


	for (int i = TEST_SIZE-1; i >= 3; i--) 
	{ 
		deque_pop_back(main_deque);
	}	

	clock_t start_time = timer_start_time(test_name);

	for (int i = 0; i <= TEST_SIZE-3; i++)
	{
		deque_push_back(main_deque, i);
	}

	timer_end_time (test_name, start_time);

	if (main_deque->length == TEST_SIZE + 1) 
	{
		fprintf(stderr, "%s: Passed!\n", test_name);
	}
	else fprintf(stderr, "%s: Failed\n", test_name);

	return 0;
}


