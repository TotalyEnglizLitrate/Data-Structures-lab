#include "hashmap.hpp"


void HashMap::rehash(void) {
    std::vector<HashTableEntry *> old_table = hash_table;
    hash_table.resize(hash_table.size() * 2);
    for (unsigned i = 0; i < hash_table.size(); i++) hash_table[i] = nullptr;

    for (HashTableEntry *entry : old_table) {
        if (!insert(entry->key, entry->val)) {
            hash_table.resize(0);
            hash_table = old_table;
            return;
        }
    }

    old_table.resize(0);
    return;
}

void HashMap::clear(HashMap::HashTableEntry *entry) {
    if (entry == nullptr)
        return;
    if (entry->next != nullptr)
        clear(entry);
    delete entry;
}

bool HashMap::insert(int key, int val) {
    // Ensure key not already in hashmap
    bool membership;
    search(key, &membership);
    if (membership) return false;

    long unsigned idx = hash_function(key) % hash_table.size();
    HashTableEntry *cur_entry = hash_table[idx];
    hash_table[idx] = new HashTableEntry { key, val, cur_entry };
    if (hash_table[idx] == nullptr) {
        hash_table[idx] = cur_entry;
        return false;
    }
    len++;
    return true;


    return true;
}


int HashMap::del(int key, bool *success) {
    *success = true;
    int to_ret = 0;
    long unsigned idx = hash_function(key) % hash_table.size();
    HashTableEntry *traversal = hash_table[idx];
    HashTableEntry *stitch;
    if (traversal == nullptr) {
        *success = false;
        return to_ret;
    } else if (traversal->key == key) {
        hash_table[idx] = traversal->next;
        to_ret = traversal->val;
        delete traversal;
        len--;
        return to_ret;
    }



    while (traversal->next != nullptr) {
        if (traversal->next->key == key) {
            stitch = traversal->next->next;
            to_ret = traversal->next->val;
            delete traversal->next;
            len--;
            traversal->next = stitch;
            return to_ret;
        }
        traversal = traversal->next;
    }

    *success = false;
    return to_ret;
}

int HashMap::search(int key, bool *success) {
    *success = true;
    long unsigned idx = hash_function(key) % hash_table.size();
    HashTableEntry *traversal = hash_table[idx];

    while (traversal != nullptr) {
        if (traversal->key == key)
            return traversal->val;
        traversal = traversal->next;
    }

    return (*success = false);
}

void HashMap::display(void) {
    std::cout << '{';
    HashTableEntry *traversal;
    for (HashTableEntry *entry : hash_table) {
        if (entry == nullptr) continue;
        traversal = entry;
        while (traversal != nullptr) {
            std::cout << ' ' << traversal->key << ':' << ' ' << traversal->val << ',';
            traversal = traversal->next;
        }
    }
    std::cout << '}';
}