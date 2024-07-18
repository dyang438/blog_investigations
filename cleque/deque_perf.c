#include "deque.h"

#define TEST_SIZE 10
#define MOVING_SIZE 10

int main ()
{
	deque* main_deque = init_deque();
	for (int i = 0; i < TEST_SIZE; i++) 
	{
		// push i onto the deque 1000 times
		deque_push_back(main_deque, i, 0);
	}
	for (int i = 0; i < MOVING_SIZE; i++)
	{
		//pop the front and push the back
		int popped = deque_pop_front(main_deque);
		deque_push_back(main_deque, popped, 1);
	}
	free_deque(main_deque);
}

