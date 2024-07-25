#include "IContainer.h"
#include <list>
#include <algorithm>
#include <string>

template <typename T>
class ListContainer : public IContainer<T> {
public:
	void insert_sorted (int value) override {
		add_sorted_list(data, value);
	}
	void remove (int index) override {
		remove_at_index(data, index);
	}
	std::string container_name () override {
		return "List ";
	}
	int size () override {
		return data.size();
	}
private:
	std::list<int>data;
	void add_sorted_list(std::list<int>& sorted_list, int val) {
		for (auto it = sorted_list.begin(); it != sorted_list.end(); ++it) {
			if (*it >= val) {
				sorted_list.insert(it, val);
				return;
			}
		}
		sorted_list.push_back(val);
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
};
