/**
 * @file main.cpp
 * @brief Solves the Codeforces problem 1767/B: Block Towers.
 * @details This program reads a sequence of tower heights and calculates the
 * maximum height of the first tower after repeatedly merging towers.
 * @see https://codeforces.com/problemset/problem/1767/B
 */

#include <iostream>

using namespace std;

/**
 * @brief Finds the index of the minimum element in an array, excluding the
 * first element and considering only elements greater than the first.
 * @param arr The array to search.
 * @param length The length of the array.
 * @return The index of the minimum element, or the length of the array if no
 * such element exists.
 */
unsigned filtered_min(unsigned arr[], unsigned length);

/**
 * @brief Modifies the array by repeatedly merging the first element with the
 * minimum element greater than it.
 * @param arr The array of tower heights.
 * @param length The length of the array.
 */
void find_max_blocks(unsigned arr[], unsigned length);

/**
 * @brief Runs a single test case, reading tower heights and calculating the
 * final height of the first tower.
 * @param length The number of towers in the test case.
 * @return The final height of the first tower.
 */
unsigned run_testcase(unsigned length);

/**
 * @brief The main function, which reads the number of test cases and processes
 * each one.
 * @return 0 on successful execution.
 */
int main() {
  unsigned test_case_count, length;
  cin >> test_case_count;
  unsigned results[test_case_count];

  for (unsigned i = 0; i < test_case_count; i++) {
    cin >> length;
    results[i] = run_testcase(length);
  }

  for (unsigned i = 0; i < test_case_count; i++) {
    cout << results[i] << endl;
  }
  return 0;
}

unsigned filtered_min(unsigned arr[], unsigned length) {
  unsigned min = length;
  for (unsigned idx = 1; idx < length; idx++) {
    if (arr[0] >= arr[idx])
      continue;
    if (min == length || arr[min] > arr[idx])
      min = idx;
  }
  return min;
}

void find_max_blocks(unsigned arr[], unsigned length) {
  unsigned to_take;
  while ((to_take = filtered_min(arr, length)) != length) {
    arr[0] = ((arr[0] + arr[to_take] + 1) >> 1);
    swap(arr[to_take], arr[length - 1]);
    length--;
  }
}

unsigned run_testcase(unsigned length) {
  unsigned towers[length];
  for (unsigned idx = 0; idx < length; idx++)
    cin >> towers[idx];

  find_max_blocks(towers, length);

  return towers[0];
}
