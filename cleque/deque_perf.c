#include "deque.h"

#define TEST_SIZE 10
#define MOVING_SIZE 10
#define PRINT 1
#define NO_PRINT 0

int pointer_bench();
int fragmented_bench();

int main ()
{
//	pointer_bench();
	fragmented_bench();
}


int pointer_bench () 
{
	deque* main_deque = init_deque();
	for (int i = 0; i < TEST_SIZE; i++) 
	{
		// push i onto the deque 10 times, 
		deque_push_back(main_deque, i, PRINT);
	}
	fprintf(stderr, "\n");
	for (int i = 0; i < MOVING_SIZE; i++)
	{
		//pop the front and push the back
		int popped_front = deque_pop_front(main_deque);
		deque_push_back(main_deque, popped_front, PRINT);
	}
	free_deque(main_deque);
	return 0;
}


int fragmented_bench() 
{
	deque* main_deque = init_deque();
	void** frag_arr [2 * TEST_SIZE];
	for (int i = 0; i < TEST_SIZE; i++)
	{
		deque_push_front(main_deque, i, PRINT);
		void* frag1 = malloc(100);
		frag_arr[2*i] = frag1;
		
		deque_push_back(main_deque, i, PRINT);
		void* frag2 = malloc(100);
		frag_arr[2*i+1] = frag2;
	}

	for (int i = 0; i < 2 * TEST_SIZE; i++) 
	{
		free(frag_arr[i]);
	}
	return 0;
}
