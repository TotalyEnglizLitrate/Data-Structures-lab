#include <iostream>

using namespace std;

/**
 * @brief Runs a single test case, reading indices to remove, player count for
 * each game and calculating the number of winners.
 * @param to_rem_count no. of indices to remove.
 * @param games_count no. of games.
 */
void run_testcase(unsigned to_rem_count, unsigned games_count);

/**
 * @brief The main function, which reads the number of test cases and processes
 * each one.
 * @return 0 on successful execution.
 */
int main() {
  unsigned test_case_count, to_rem_count, games_count;
  cin >> test_case_count;

  for (unsigned i = 0; i < test_case_count; i++) {
    cin >> to_rem_count;
    cin >> games_count;
    run_testcase(to_rem_count, games_count);
  }

  return 0;
}

void run_testcase(unsigned to_rem_count, unsigned games_count) {
  unsigned min_idx = 0, player_count;
  for (unsigned i = 0, tmp; i < to_rem_count; i++) {
    cin >> tmp;
    if (min_idx == 0)
      min_idx = tmp;
    if (tmp < min_idx)
      min_idx = tmp;
  }

  for (unsigned i = 0; i < games_count; i++) {
    cin >> player_count;
    cout << (player_count >= min_idx ? min_idx - 1 : player_count) << " ";
  }
  cout << endl;
  return;
}
