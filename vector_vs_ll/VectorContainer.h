#include "IContainer.h"
#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
class VectorContainer : public IContainer<T> {
public:
	void insert_sorted (int value) override {
		add_sorted_vec(data, value);
	}
	void remove (int index) override {
		if (index >= 0 && index < static_cast<int>(data.size())){
			data.erase(data.begin() + index);
		}
		else std::cerr<<"wtf"<<index;
	}
	std::string container_name () override {
		return "Vector ";
	}
	int size () override {
		return data.size();
	}

private:
	std::vector<int> data;
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
};
