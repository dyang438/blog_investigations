#include <stdio.h>
#include <string.h>

#include "cleque_ptr.h"
#include "test_timing.h"

#define TEST_SIZE 1000000

int test_one(cleque* main_cleque);

int test_two(cleque* main_cleque);

int test_three(cleque* main_cleque);

int test_four(cleque* main_cleque);


int main () 
{
	static int input [TEST_SIZE];
	srand(time(NULL));
	for (int i = 0; i < TEST_SIZE; i++) input[i] = i;
	int size = sizeof(input)/sizeof(int);

	cleque cleque_1 = {NULL, 0, 0, 0};
	populate_cleque (&cleque_1, input, size);

	test_one(&cleque_1);

	// reset the main_cleque
	for (int i = 0; i < TEST_SIZE; i++) input[i] = i;

	cleque cleque_2 = {NULL, 0, 0, 0};
	populate_cleque (&cleque_2, input, size);

	test_two(&cleque_2);

	// reset the main_cleque
	for (int i = 0; i < TEST_SIZE; i++) input[i] = i;

	cleque cleque_3 = {NULL, 0, 0, 0};
	populate_cleque (&cleque_3, input, size);

	test_three(&cleque_3);

	// reset the main_cleque
	for (int i = 0; i < TEST_SIZE; i++) input[i] = i;

	cleque cleque_4 = {NULL, 0, 0, 0};
	populate_cleque (&cleque_4, input, size);

	test_four(&cleque_4);
}


int test_one (cleque* main_cleque) 
{
	char* test_name = "Cleque test pop_back";
	clock_t start_time = timer_start_time(test_name);
	for (int i = TEST_SIZE-1; i >= 3; i--) 
	{ 
		cleque_pop_back(main_cleque);
	}	

	timer_end_time (test_name, start_time);

	if (main_cleque->adjusted_len == 3) 
	{
		fprintf(stderr, "%s: Passed!\n", test_name);
	}
	else fprintf(stderr, "%s: Failed\n", test_name);

	return 0;
}


int test_two (cleque* main_cleque) 
{
	char* test_name = "Cleque test pop_front";
	clock_t start_time = timer_start_time(test_name);
	for (int i = TEST_SIZE-1; i >= 3; i--) 
	{ 
		cleque_pop_front(main_cleque);
	}

	timer_end_time (test_name, start_time);

	if (main_cleque->adjusted_len == 3) 
	{
		fprintf(stderr, "%s: Passed!\n", test_name);
	}
	else fprintf(stderr, "%s: Failed\n", test_name);

	return 0;
}


int test_three (cleque* main_cleque)
{
	char* test_name = "Cleque test push_front";

	for (int i = TEST_SIZE-1; i >= 3; i--) 
	{ 
		cleque_pop_front(main_cleque);
	}
	
	clock_t start_time = timer_start_time(test_name);

	for (int i = 0; i <= TEST_SIZE-3; i++)
	{
		cleque_push_front(main_cleque, i);
	}
 
	timer_end_time (test_name, start_time);

	if (main_cleque->adjusted_len == TEST_SIZE) {
		fprintf(stderr, "%s: Passed!\n", test_name);
	}
	else fprintf(stderr, "%s: Failed\n", test_name);

	return 0;
}


int test_four (cleque* main_cleque)
{
	char* test_name = "Cleque test push_back";

	for (int i = TEST_SIZE-1; i >= 3; i--) 
	{ 
		cleque_pop_back(main_cleque);
	}

	clock_t start_time = timer_start_time(test_name);

	for (int i = 0; i <= TEST_SIZE-3; i++)
	{
		cleque_push_back(main_cleque, i);
	}
	
	timer_end_time (test_name, start_time);

	if (main_cleque->adjusted_len == TEST_SIZE) {
		fprintf(stderr, "%s: Passed!\n", test_name);
	}
	else fprintf(stderr, "%s: Failed\n", test_name);

	return 0;
}
