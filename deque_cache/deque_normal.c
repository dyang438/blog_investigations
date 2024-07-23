#include "../time_bench/test_timing.h"
#include "deque.h"

#define TEST_SIZE 100000
#define REP_SIZE 100
#define PRINT 1
#define NO_PRINT 0

int normal_bench();

int main() {
	normal_bench();	
}

int normal_bench() 
{
	deque* main_deque = init_deque();
	for (int i = 0; i < TEST_SIZE; i++)
	{
		deque_push_front(main_deque, i, NO_PRINT);
		deque_push_back(main_deque, i, NO_PRINT);
	}
	
	int x [TEST_SIZE];
	
	clock_t start_time = timer_start_time("Normal Bench Forwards");

	for (int i = 0; i < REP_SIZE; i++)
	{
		deque_node* front = main_deque->first;
		deque_node* iterfront = main_deque->first;
		while(iterfront->next != front) {
			iterfront = iterfront->next;
			x[i] = iterfront->payload;
		}
	}
	timer_end_time("Normal Bench Forwards", start_time);
	

	start_time = timer_start_time("Normal Bench Backwards");

	for (int i = 0; i < REP_SIZE; i++)
	{
		deque_node* back = main_deque->last;
		deque_node* iterback = main_deque->last;
		while(iterback->prev != back) {
			iterback = iterback->prev;
			x[i] = iterback->payload;
		}

	}

	timer_end_time("Normal Bench Backwards", start_time);

	deque* fight = init_deque();
	for (int i = 0; i < TEST_SIZE; i++)
	{
		deque_push_front(fight, x[i], NO_PRINT);
	}
	free_deque(main_deque);
	free_deque(fight);
	return 0;
}
