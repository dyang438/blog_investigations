#include <alloca.h>
#include <cstddef>
#include <iostream>
#include <vector>

using HashFunc = int (*)(int, std::size_t);
using ProbingFunc = int (*)(int, int, std::size_t);

struct HashEntry {
    int key;
    bool present;
    void* value;
};

class std_pointer_hasher {
private:
    HashFunc hash_func;
    ProbingFunc probe_func;
    std::size_t size;
    double load_factor;
    HashEntry* table;
    long len;
    int probe_jump;
public:
    std_pointer_hasher()
        : hash_func(nullptr), probe_func(nullptr), size(16),
          load_factor(0.75), table(nullptr), len(0), probe_jump(3) {}
    ~std_pointer_hasher() {
        if (table) {
            free(table); // Since using malloc
        }
    }
    void setup(HashFunc input_hash_func, ProbingFunc input_probe_func,
               double input_load_factor = 0.75, std::size_t input_size = 31,
               int input_probe_jump = 3) {
        hash_func = input_hash_func;
        probe_func = input_probe_func;
        load_factor = input_load_factor;
        size = input_size;
        probe_jump = input_probe_jump;

        // Allocate memory for the table and initialize entries
        table = (HashEntry*)malloc(size * sizeof(HashEntry));
        if (!table) {
            std::cerr << "Memory allocation failed.\n";
            exit(EXIT_FAILURE);
        }
        len = 0;
    }
    void hash_in (int K, void* V) {
        // Dependent on both probe_jump and size being set properly.
        int hash_idx = hash_func(K, size);
        while (table[hash_idx].present) {
            hash_idx = probe_func(hash_idx, probe_jump, size);
        }
        table[hash_idx].key = K;
        table[hash_idx].value = V;
        table[hash_idx].present = true;
    }
    void resize () {
        HashEntry* table_old = table;
        int old_size = size;
        size = size << 1;
        std::cout<<"size_old: "<<old_size;
        std::cout<<"size_new: "<<size;
        std::cout<<"_______________";
        table = (HashEntry*) malloc(size * sizeof(HashEntry));

        for (int i = 0; i < old_size; i++) {
            HashEntry kv_store = table_old[i];
            if (kv_store.present) {
                int K = kv_store.key;
                void* V = kv_store.value;
                hash_in(K, V);
            }
        }
    }
    void add (long K, void* V) {
        // Possible loss of precision due to integer division, might need to debug
        if ((len + 1 / (long) size) > load_factor) {
            resize();
        }
        hash_in(K, V);
        len ++;
    }
    std::pair<int, void*> peek(int idx) {
        return std::make_pair (table[idx].key, table[idx].value);
    }
};

int hash (int K, std::size_t table_size) {
    return K % table_size;
}

int probe (int hash, int probe_jump, std::size_t table_size) {
    return (hash + probe_jump) % table_size;
}

int main() {
    std_pointer_hasher hash_table;
    hash_table.setup(hash, probe);
    std::vector x (2, 5);
    hash_table.add(60, &x);
    std::cout<<hash_table.peek(29).first;
    std::cout<<hash_table.peek(29).second;
    
    return 0;
}
