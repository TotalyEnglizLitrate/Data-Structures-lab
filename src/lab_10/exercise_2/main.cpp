#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

/*
 * @brief Returns x ** y
 * @param x
 * @param y
 */
unsigned exp(unsigned x, unsigned y);


/*
 * @brief Returns log y base x
 * @param x
 * @param y
 */
unsigned log(unsigned x, unsigned y);


/*
 * @brief Runs a single test case
 * @param len No. of words per player
 * @param arr Pointer to array of points per player
 */
void run_testcase(unsigned len, unsigned arr[]);


/*
 * @brief Calculates a players points based on the number of times a word occured
 * @param map Map for word and usage by players
 * @param arr Pointer to array of points per player
 */
void calculate_points(unordered_map<string, unsigned> &map, unsigned arr[]);


int main(void) {
    unsigned test_case_count, arr_len, score[3];
    cin >> test_case_count;
    for (unsigned i = 0; i < test_case_count; i++) {
        cin >> arr_len;
        run_testcase(arr_len, score);
        cout << score[0] << ' ' << score[1] << ' ' << score[2] << endl;
    }
}


void run_testcase(unsigned len, unsigned arr[]) {
    unordered_map<string, unsigned> mapping;
    string word;

    for (unsigned i = 0; i < 3; i++)
    for (unsigned j = 0; j < len; j++) {
        cin >> word;
        if (mapping.find(word) == mapping.end())
            mapping[word] = 0;
        mapping[word] ^= exp(2, i);
    }
    
    calculate_points(mapping, arr);
}


void calculate_points(unordered_map<string, unsigned> &map, unsigned arr[]) {
    string key;
    unsigned value;
    arr[0] = arr[1] = arr[2] = 0;
    for (auto pair: map) {
        key = pair.first;
        value = pair.second;
        switch (value) {
        case 1:
        case 2:
        case 4:
            arr[log(2, value)] += 3;
            break;
        case 3:
            arr[0] += 1;
            arr[1] += 1;
            break;
        case 5:
            arr[0] += 1;
            arr[2] += 1;
            break;
        case 6:
            arr[1] += 1;
            arr[2] += 1;
            break;
        default:
            break;
        }
    }
}


unsigned exp(unsigned x, unsigned y) {
    unsigned result = 1;
    for (;y != 0; y--) result *= x;
    return result;
}


unsigned log(unsigned x, unsigned y) {
    unsigned result = 0;
    for (;y != 1; y /= x) result += 1;
    return result;
}