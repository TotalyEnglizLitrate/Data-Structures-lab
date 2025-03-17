/*
 * Solve the following codeforces question -
 * https://codeforces.com/problemset/problem/1767/B
 */

#include <iostream>

using namespace std;

unsigned filtered_min(unsigned[], unsigned);
void find_max_blocks(unsigned[], unsigned);
void run_testcase(unsigned);

int main() {
  unsigned test_case_count, length;
  cin >> test_case_count;

  while (test_case_count--) {
    cin >> length;
    run_testcase(length);
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

void run_testcase(unsigned length) {
  unsigned towers[length];
  for (unsigned idx = 0; idx < length; idx++)
    cin >> towers[idx];

  find_max_blocks(towers, length);

  cout << towers[0] << endl;
}
