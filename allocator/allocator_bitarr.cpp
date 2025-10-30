#include "benchmark.h"

template <class T>
struct T_Store {
    bool present;
    T val;
};

template <class T>
class Allocator {
    private:
        int capacity;
        int items;
        size_t t_size;
        <T>* alloc_store;
        

    public:
        Allocator(int capacity) {
            t_size = sizeof(T);
            this->capacity = capacity;
            alloc_store = static_cast<T_Store<T>*>( malloc(sizeof(T_Store<T>) * capacity) );
            for (int i = 0; i < capacity; i++) {
                alloc_store[i].present = false;
            }
        }
        
        T* allocate() {
            for (int i = 0; i < capacity; i++) {
                if (!alloc_store[i].present) {
                    alloc_store[i].present = true;
                    items ++;
                    return &alloc_store[i].val;
                }
            }
            return nullptr;
        }

        ~Allocator() {
            for (int i = 0; i < capacity; i++) {
                
                if (alloc_store[i].present) alloc_store[i].val.~T();
            }
            free(alloc_store);
        }

};

int main() {
    run_benchmark<Allocator<ChildClass>>("BitArray Allocator");
    return 0;
}