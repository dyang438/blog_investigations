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
std::uniform_int_distribution<rng_type::result_type> udist(0, 1000000);

rng_type rng;

std::vector<double> test_vec (std::vector<int> test_sizes);
std::vector<double> test_list (std::vector<int> test_sizes);
std::vector<double> test_deque (std::vector<int> test_sizes);

void add_sorted_vec(std::vector<int>& sorted_vec, int val);
void add_sorted_list(std::list<int>& sorted_list, int val);
void add_sorted_c_deque(deque* input, int val);


int main() {
	//seeding random number generator
	rng_type::result_type const seed_val = static_cast<rng_type::result_type>(std::time(0));
	rng.seed(seed_val);

	std::vector<std::vector<double>> times;
	std::vector<int> test_sizes = {5000, 10000};

	times.push_back(test_vec(test_sizes));
	times.push_back(test_list(test_sizes));

	for (auto& test : times) {
		for (auto& time: test) {
			std::cout<<time<<"\t";
		}
		std::cout<<"\n";
	}
}


std::vector<double> test_vec (std::vector<int> test_sizes) {
	std::vector<double> insert_results;
	std::vector<double> remove_results;

	for (int i = 0; i < (int)test_sizes.size(); i++) {
		std::vector<int> sorted_vec;
		std::string test_name_insert = "Vector Insert Test " + std::to_string(test_sizes[i]);
		clock_t start_time = timer_start_time(test_name_insert);
		for (int j = 0; j < test_sizes[i]; j++) {
			int rand_num = static_cast<int>(udist(rng));
			add_sorted_vec(sorted_vec, rand_num);
		}	
		double time = timer_end_time(test_name_insert, start_time);
		insert_results.push_back(time);


		std::string test_name_remove = "Vector Remove Test " + std::to_string(test_sizes[i]);
		start_time = timer_start_time(test_name_remove);
		for (int j = 0; j < test_sizes[i]; j++) {
			std::uniform_int_distribution<rng_type::result_type> change (0, test_sizes[i]-j-1);
			int rand_num = static_cast<int>(change(rng));
			sorted_vec.erase(sorted_vec.begin()+rand_num);
		}
		time = timer_end_time(test_name_remove, start_time);
		if (sorted_vec.size() == 0) std::cout<<"Passed " + test_name_remove;
		remove_results.push_back(time);
	}
	
	insert_results.insert(insert_results.end(), remove_results.begin(), remove_results.end());
	return insert_results;
}

void remove_at_index(std::list<int>& sorted_list, int index) {
	if (index < 0 || index >= static_cast<int>(sorted_list.size())) {
		return;
	}

	//try profiling without using std::advance
	auto it = sorted_list.begin();
	std::advance(it, index);
	sorted_list.erase(it);
}

std::vector<double> test_list (std::vector<int> test_sizes) {
	std::vector<double> insert_results;
	std::vector<double> remove_results;

	for (int i = 0; i < (int)test_sizes.size(); i++) {
		std::list<int> sorted_list;
		std::string test_name = "List Test " + std::to_string(test_sizes[i]);
		for (int j = 0; j < test_sizes[i]; j++) {
			rng_type::result_type rand_num = udist(rng);
			add_sorted_list(sorted_list, static_cast<int>(rand_num));
		}	
		clock_t start_time = timer_start_time(test_name);
			
		double time = timer_end_time(test_name, start_time);
		insert_results.push_back(time);

		std::string test_name_remove = "List Remove Test " + std::to_string(test_sizes[i]);
		start_time = timer_start_time(test_name_remove);
		for (int j = 0; j < test_sizes[i]; j++) {
			std::uniform_int_distribution<rng_type::result_type> change (0, test_sizes[i]-j-1);
			int rand_num = static_cast<int>(change(rng));
			remove_at_index(sorted_list, rand_num);
		}
		time = timer_end_time(test_name_remove, start_time);
		if (sorted_list.size() == 0) std::cout<<"Passed " + test_name_remove;
		remove_results.push_back(time);
	}

	insert_results.insert(insert_results.end(), remove_results.begin(), remove_results.end());
	return insert_results;
}


std::vector<double> test_deque (std::vector<int> test_sizes) {
	std::vector<double> results;

	for (int i = 0; i < (int)test_sizes.size(); i++) {
		deque* sorted_deque = init_deque();
		std::string test_name = "Deque Test " + std::to_string(test_sizes[i]);
		clock_t start_time = timer_start_time(test_name);
		for (int j = 0; j < test_sizes[i]; j++) {
			rng_type::result_type rand_num = udist(rng);
			add_sorted_c_deque(sorted_deque, static_cast<int>(rand_num));
		}	
		double time = timer_end_time(test_name, start_time);
		results.push_back(time);
		free_deque(sorted_deque);
	}
	


	return results;
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
	if (!sorted_deque->last || sorted_deque->last->payload < val) {
		deque_push_back(sorted_deque, val, 0);
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

	deque_push_back(sorted_deque, val, 0);
}


