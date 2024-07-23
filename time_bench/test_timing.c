#include <stdio.h>
#include <time.h>
#include "test_timing.h"


clock_t timer_start_time (char* test_name)
{
	fprintf(stderr, "\n_________________\n%s\n", test_name);
	return clock();
}


double timer_end_time (char* test_name, clock_t start_time)
{
	clock_t end_time = clock();
	double time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	fprintf(stderr, "Time spent in %s: %f seconds\n_________\n", test_name, time_spent);
	fprintf(stdout, "%f\t", time_spent);
	return time_spent;
}
