#ifndef PARENT_CLASS_H
#define PARENT_CLASS_H

#include <string>
#include <unordered_map>
#include <memory>

using NameMap = std::unordered_map<int, std::string>;

class ParentClass {
    private:
    std::string name;
    NameMap class_names;
    std::shared_ptr<NameMap> names_ref;

    public:
        ParentClass(std::string name) {
            this->name = name;
            names_ref = std::make_shared<NameMap>();
        }

        std::shared_ptr<NameMap> get_ptr() {
            std::shared_ptr<NameMap> new_ptr = names_ref;
            return new_ptr;
        }

        ~ParentClass() {}
};

#endif //PARENT_CLASS_H