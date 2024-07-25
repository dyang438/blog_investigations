#ifndef ICONTAINER_H
#define ICONTAINER_H

#include <string>
template <typename T>
class IContainer {
public:
	virtual ~IContainer() = default;

	virtual void insert_sorted(T value) = 0;
	virtual void remove(T index) = 0;
	virtual std::string container_name() = 0;
	virtual int size() = 0;
};

#endif //ICONTAINER_H
