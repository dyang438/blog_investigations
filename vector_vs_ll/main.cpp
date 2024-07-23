#include <vector>
#include <list>
#include <random>
#include <ctime>
#include <string>
#include "../time_bench/cpp_test.h"

constexpr int TEST_SIZE = 100000;

typedef std::mt19937 rng_type;
std::uniform_int_distribution<rng_type::result_type> udist(0, 25);

rng_type rng;

void add_sorted_vec(std::vector<int>& sorted_vec, int val);
void add_sorted_list(std::list<int>& sorted_list, int val);

int main() {
	//seeding random number generator
	rng_type::result_type const seed_val = static_cast<rng_type::result_type>(std::time(0));

	rng.seed(seed_val);

	std::vector<int> sorted_vec;
	std::list<int> sorted_list;
	
	std::string vector_test = "Vector Test";

	clock_t start_time_vec = timer_start_time(vector_test);

	for (int i = 0; i < TEST_SIZE; i++) {
		rng_type::result_type rand_num = udist(rng);
		add_sorted_vec(sorted_vec, static_cast<int>(rand_num));
	}	

	timer_end_time(vector_test.data(), start_time_vec);

	std::string list_test = "List Test";

	clock_t start_time_list = timer_start_time(list_test.data());

	for (int i = 0; i < TEST_SIZE; i++) {
		rng_type::result_type rand_num = udist(rng);
		add_sorted_list(sorted_list, static_cast<int>(rand_num));
	}	

	timer_end_time(list_test.data(), start_time_list);

	return 2;
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
