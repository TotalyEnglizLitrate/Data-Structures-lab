#include "hashmap.hpp"

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
    long unsigned idx, i;
    idx = i = hash_function(key) % hash_table.size();
    while (i != idx) {
        if (hash_table[i] == nullptr) {
            hash_table[i] = new HashTableEntry { key, val };

            if (hash_table[i] == nullptr) return false;
            len++;
            if ((len * 10) / hash_table.size() > fill_ratio) rehash();
            else return true;
        }
        i++;
        if (i >= hash_table.size())
            i %= hash_table.size();
    }

    return false;
}


int HashMap::del(int key, bool *success) {
    *success = true;
    int to_ret = 0;
    long unsigned idx, i;
    idx = i = hash_function(key) % hash_table.size();

    while (i != idx) {
        if (hash_table[i] != nullptr && hash_table[i]->key == key) {
            *success = true;
            to_ret = hash_table[i]->val;
            delete hash_table[i];
            hash_table[i] = nullptr;
            len--;
            return to_ret;
        }

        i++;
        if (i >= hash_table.size())
            i %= hash_table.size();
    }

    *success = false;
    return to_ret;
}

int HashMap::search(int key, bool *success) {
    *success = true;
    long unsigned idx, i;
    idx = i = hash_function(key) % hash_table.size();

    while (i < hash_table.size()) {
        if (hash_table[i] != nullptr && hash_table[i]->key == key)
            return hash_table[i]->val;
        i++;
        if (i >= hash_table.size())
            i %= hash_table.size();
    }

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