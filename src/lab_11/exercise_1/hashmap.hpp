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

    /*
     * @brief Helper function to grow table when the fill ratio is exceeded
     */
    bool rehash(void);
public:
    HashMap() : fill_ratio(4), len(0) {
        hash_table.resize(10000);
        for (unsigned i = 0; i < hash_table.size(); i++) hash_table[i] = nullptr;
    }
    ~HashMap(void) {
        for (HashTableEntry *entry : hash_table)
            delete entry;
        hash_table.resize(0);
    }

    /*
     * @brief Insert a key-value pair into the hash table
     * @param key The key to insert
     * @param val The value to insert
     * @return true if the insertion was successful, false otherwise
     * @note If the fill ratio is exceeded, the table will be rehashed
     */
    bool insert(int key, int val);

    /*
     * @brief Delete a key-value pair from the hash table
     * @param key The key to delete
     * @param success Pointer to a boolean that will be set to true if the
     * deletion was successful, false otherwise
     * @return The value associated with the key if it was found. Undefined
     * behavior if key is not found
    */
    int del(int key, bool *success);

    /*
     * @brief Search for a key in the hash table
     * @param key The key to search for
     * @param success Pointer to a boolean that will be set to true if the key
     * is present in the hash table, false otherwise
     * @return The value associated with the key if it was found. Undefined
     * behavior if key is not found
     */
    int search(int key, bool *success);

    /*
     * @brief Display the hash table
     */
    void display(void);
};