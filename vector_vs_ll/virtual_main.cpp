#include <utility>
#include <vector>
#include <iostream>
#include <random>
#include <ctime>
#include <string>
#include "../time_bench/cpp_test.h"
#include "VectorContainer.h"
#include "ListContainer.h"

typedef std::mt19937 rng_type;
std::uniform_int_distribution<rng_type::result_type> udist(0, 1000000);

rng_type rng;

template <typename Container>
std::pair<double, double> test_container (Container& container, int test_size);

std::vector<int> test_sizes = {50000, 100000, 200000, 300000, 400000, 500000};

int main() {
	//seeding random number generator
	rng_type::result_type const seed_val = static_cast<rng_type::result_type>(std::time(0));
	rng.seed(seed_val);

	std::vector<std::vector<double>> times;
	
	std::vector<double> insert_results_vec;
	std::vector<double> remove_results_vec;
	for (int test_size : test_sizes) {
		VectorContainer<int> sorted_vec;
		std::pair<double,double> times = test_container(sorted_vec, test_size);
		insert_results_vec.push_back(times.first);
		remove_results_vec.push_back(times.second);
	}
	times.push_back(insert_results_vec);
	times.push_back(remove_results_vec);

	std::vector<double> insert_results_list;
	std::vector<double> remove_results_list;
	for (int test_size : test_sizes) {
		ListContainer<int> sorted_list;
		std::pair<double,double> times = test_container(sorted_list, test_size);
		insert_results_list.push_back(times.first);
		remove_results_list.push_back(times.second);
	}
	times.push_back(insert_results_list);
	times.push_back(remove_results_list);

	for (int i = 0; i < (int)times.size(); i++) {
		for (int j = 0; j < (int)times[i].size(); j++) {
			std::cout<<times[i][j]<<"\t";
		}
		std::cout<<"\n";
	}
}

template <typename Container>
std::pair<double, double> test_container (Container& container, int test_size) {
	std::pair<double, double>ret_double;
	std::string test_name_insert = container.container_name() + "Insert Test " + std::to_string(test_size);

	clock_t start_time = timer_start_time(test_name_insert);

	for (int j = 0; j < test_size; j++) {
		int rand_num = static_cast<int>(udist(rng));
		container.insert_sorted(rand_num);
	}	

	ret_double.first = timer_end_time(test_name_insert, start_time);

	if (container.size() == test_size) std::cout<<"Passed " + test_name_insert;

	std::string test_name_remove = container.container_name() + "Remove Test " + std::to_string(test_size);
	start_time = timer_start_time(test_name_remove);
	for (int j = 0; j < test_size; j++) {
		std::uniform_int_distribution<rng_type::result_type> change (0, test_size-j-1);
		int rand_num = static_cast<int>(change(rng));
		container.remove(rand_num);
	}
	ret_double.second = timer_end_time(test_name_remove, start_time);
	if (container.size() == 0) std::cout<<"Passed " + test_name_remove;
	else std::cerr<<"error" <<container.size();
	return ret_double;
}
