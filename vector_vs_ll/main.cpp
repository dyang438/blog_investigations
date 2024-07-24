#include <vector>
#include <iostream>
#include <list>
#include <random>
#include <ctime>
#include <string>
#include "../time_bench/cpp_test.h"
#include "../deque_cache/deque.h"

constexpr int TEST_SIZE = 100000;

typedef std::mt19937 rng_type;
std::uniform_int_distribution<rng_type::result_type> udist(0, 25);

rng_type rng;

void test_vec(double* times);
void test_list(double* times);
void test_deque(double* times);

void add_sorted_vec(std::vector<int>& sorted_vec, int val);
void add_sorted_list(std::list<int>& sorted_list, int val);
void add_sorted_c_deque(deque* input, int val);


int main() {
	//seeding random number generator
	rng_type::result_type const seed_val = static_cast<rng_type::result_type>(std::time(0));
	rng.seed(seed_val);

	double times [3] = {0, 0, 0};

	test_vec(times);
	test_list(times);
	
	/* If you would like to see how fast the deque from that post runs compared to STL containers, it's here. It's basically implemented how std::list is */
	//test_deque(times);


	std::cout<<times[0]<<"\t"<<times[1]<<"\t"<<times[2]<<"\t";

	return 2;
}


void test_vec (double* times) {
	std::vector<int> sorted_vec;
	std::string vector_test = "Vector Test";

	clock_t start_time = timer_start_time(vector_test);

	for (int i = 0; i < TEST_SIZE; i++) {
		rng_type::result_type rand_num = udist(rng);
		add_sorted_vec(sorted_vec, static_cast<int>(rand_num));
	}	

	double time = timer_end_time(vector_test, start_time);

	/*for (int i = 0; i < TEST_SIZE; i++) {*/
	/*	std::cout<<sorted_vec[i]<<",";*/
	/*}*/

	times[0] = time;
}


void test_list (double* times) {
	std::list<int> sorted_list;
	std::string list_test = "List Test";

	clock_t start_time = timer_start_time(list_test);

	for (int i = 0; i < TEST_SIZE; i++) {
		rng_type::result_type rand_num = udist(rng);
		add_sorted_list(sorted_list, static_cast<int>(rand_num));
	}	

	double time = timer_end_time(list_test, start_time);

	/*for (auto& ele : sorted_list) {*/
	/*	std::cout<<ele<<",";*/
	/*}*/

	times[1] = time;

}


void test_deque (double* times) {
	deque* sorted_deque = init_deque();
	std::string deque_test = "Deque Test";

	clock_t start_time = timer_start_time(deque_test);

	for (int i = 0; i < TEST_SIZE; i++) {
		rng_type::result_type rand_num = udist(rng);
		add_sorted_c_deque(sorted_deque, static_cast<int>(rand_num));
	}	

	double time = timer_end_time(deque_test, start_time);
	times[2] = time;

	/*print_deque(sorted_deque);*/

	free_deque(sorted_deque);
}


void add_sorted_vec(std::vector<int>& sorted_vec, int val) {
	int i;
	for (i = 0; i < (int)sorted_vec.size(); i++) {
		if (sorted_vec.at(i) >= val) {
			break;
		} 
	}
	sorted_vec.push_back(0); // add dummy value at the end.
	for (int j = sorted_vec.size()-1; j > i; --j) {
		sorted_vec[j] = sorted_vec[j-1];
	}
	sorted_vec[i] = val;
}


void add_sorted_list(std::list<int>& sorted_list, int val) {
	for (auto it = sorted_list.begin(); it != sorted_list.end(); ++it) {
		if (*it >= val) {
			sorted_list.insert(it, val);
			return;
		}
	}
	sorted_list.push_back(val);
}	


void add_sorted_c_deque(deque* sorted_deque, int val) {
	if (!sorted_deque->first) {
		deque_push_front(sorted_deque, val, 0);
		return;
	}

	deque_node* iter = sorted_deque->first;

	if (iter->payload > val) {
		deque_push_front(sorted_deque, val, 0);
		return;
	} 

	while (iter->next != sorted_deque->first) {
		if (iter->payload > val) {
			deque_node* pushed = (deque_node*)malloc(sizeof(deque_node));
			pushed->next = iter;
			pushed->prev = iter->prev;
			pushed->prev->next = pushed;
			iter->prev = pushed;
			pushed->payload = val;
			return;
		}
		iter = iter->next;
	}
	if (iter->payload > val) {
		deque_node* pushed = (deque_node*)malloc(sizeof(deque_node));
		pushed->next = iter;
		pushed->prev = iter->prev;
		pushed->prev->next = pushed;
		iter->prev = pushed;
		pushed->payload = val;
		return;
	}
	deque_push_back(sorted_deque, val, 0);
}


