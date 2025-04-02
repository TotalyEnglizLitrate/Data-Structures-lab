#include <iostream>
#include <unordered_set>
using namespace std;

/*
 * @brief Runs a single test case
 * @param len No. of elements
 * @return length of list with unique elements when deleting from the right
 */
unsigned run_testcase(unsigned len);


int main(void) {
    unsigned test_case_count, arr_len, final_len;
    cin >> test_case_count;
    for (unsigned i = 0; i < test_case_count; i++) {
        cin >> arr_len;
        final_len = run_testcase(arr_len);
        cout << final_len << endl;
    }
}


unsigned run_testcase(unsigned len) {
    unsigned arr[len];
    unordered_set<unsigned> membership;
    bool result;
    for (unsigned i = 0; i < len; i++) {
        cin >> arr[i];
    }
    for (unsigned i = 0; i < len; i++) {
        if (!membership.insert(arr[len - i - 1]).second) return len - i;
    }

    return 0;
}

