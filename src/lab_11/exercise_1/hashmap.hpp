#include <vector>
#include <bits/stdc++.h>

class HashMap {
private:
    struct HashTableEntry {
        int key;
        int val;
    };

    std::vector<HashTableEntry *> hash_table;
    long unsigned fill_ratio;
    long unsigned len;
    std::hash<int> hash_function;

    bool rehash(void);
public:
    HashMap() : fill_ratio(4), len(0) {
        hash_table.resize(10000);
        for (unsigned i = 0; i < hash_table.size(); i++) hash_table[i] = nullptr;
    }
    ~HashMap(void) {
        for (HashTableEntry *entry: hash_table)
            delete entry;
        hash_table.resize(0);
    }
    bool insert(int key, int val);
    int del(int key, bool *success);
    int search(int key, bool *success);
    void display(void);
};