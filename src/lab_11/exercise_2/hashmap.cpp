#include "hashmap.hpp"

long unsigned sqr(long unsigned x) { return x * x; }

bool HashMap::rehash(void) {
    std::vector<HashTableEntry *> old_table = hash_table;
    hash_table.resize(hash_table.size() * 2);
    for (unsigned i = 0; i < hash_table.size(); i++) hash_table[i] = nullptr;

    for (HashTableEntry *entry : old_table) {
        if (!insert(entry->key, entry->val)) {
            hash_table.resize(0);
            hash_table = old_table;
            return false;
        }
    }

    old_table.resize(0);
    return true;
}

bool HashMap::insert(int key, int val) {
    // Ensure key not already in hashmap
    bool membership;
    search(key, &membership);
    if (membership) return false;
    long unsigned idx, i, i_sqr;
    idx = i = i_sqr = hash_function(key) % hash_table.size();

    do {
        if (hash_table[i_sqr] == nullptr) {
            hash_table[i_sqr] = new HashTableEntry { key, val };

            if (hash_table[i_sqr] == nullptr) return false;
            len++;
            if ((len * 10) / hash_table.size() > fill_ratio) rehash();
            return true;
        }
        i++;
    } while ((i_sqr = sqr(i) % hash_table.size()) != idx);

    return false;
}


int HashMap::del(int key, bool *success) {
    *success = true;
    int to_ret = 0;
    long unsigned idx, i, i_sqr;
    idx = i = i_sqr = hash_function(key) % hash_table.size();

    do {
        if (hash_table[i_sqr] != nullptr && hash_table[i_sqr]->key == key) {
            *success = true;
            to_ret = hash_table[i_sqr]->val;
            delete hash_table[i_sqr];
            hash_table[i_sqr] = nullptr;
            len--;
            return to_ret;
        }

        i++;
    } while ((i_sqr = sqr(i) % hash_table.size()) != idx);

    *success = false;
    return to_ret;
}

int HashMap::search(int key, bool *success) {
    *success = true;
    long unsigned idx, i, i_sqr;
    idx = i = i_sqr = hash_function(key) % hash_table.size();
    do {
        if (hash_table[i_sqr] != nullptr && hash_table[i_sqr]->key == key)
            return hash_table[i_sqr]->val;
        else
            i++;
    } while ((i_sqr = sqr(i) % hash_table.size()) != idx);

    return (*success = false);
}

void HashMap::display(void) {
    std::cout << '{';
    for (HashTableEntry *entry : hash_table) {
        if (entry == nullptr) continue;
        std::cout << ' ' << entry->key << ':' << ' ' << entry->val << ',';
    }
    std::cout << '}';
}