#include "stdio.h"

#define TEST_SIZE 100

int sieve_of_eratosthenes () {
	int all [TEST_SIZE] = {0};
	all[0] = 1;
	all[1] = 1;
	int ret = 0;
	for (int i = 2; i < TEST_SIZE; i++) {
		if (!all[i]) { //if i is prime
			int it = 2i;
			while (it < TEST_SIZE) {
				all[it] = 1;
				it += i;
			}
		}
	}
	for (int i = 0; i < TEST_SIZE; i++) {
		if (all[i] == 0) {
			ret++;
		}
	}
	fprintf(stderr, "%d", ret);
	return ret;
}


int main() {
	fprintf(stderr, "this %d\n", sieve_of_eratosthenes());
}
