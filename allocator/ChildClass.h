#ifndef CHILD_CLASS_H
#define CHILD_CLASS_H

#include <string>
#include <unordered_map>
#include <memory>

using NameMap = std::unordered_map<int, std::string>; 
class ChildClass {
    private:
    std::string name;
    int val;
    std::shared_ptr<NameMap> this_ref;

    public:
        ChildClass(std::string name, int val, ParentClass& my_parent) {
            this->name = name;
            this->val = val;
            this_ref = my_parent.get_ptr();
        }

        void name_map_insert() {
            (*this_ref)[val] = name;
        }

        ~ChildClass() {}
};

#endif //CHILD_CLASS_H