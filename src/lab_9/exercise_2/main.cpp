#include <iostream>

using namespace std;

/**
 * @brief Runs a single test case, reading player strengths, and calculating
 * least advantage/highest disadvantage for each player
 * @param player_count no of players.
 */
void run_testcase(unsigned player_count);

/**
 * @brief The main function, which reads the number of test cases and processes
 * each one.
 * @return 0 on successful execution.
 */
int main() {
  unsigned test_case_count, player_count;
  cin >> test_case_count;

  for (unsigned i = 0; i < test_case_count; i++) {
    cin >> player_count;
    run_testcase(player_count);
  }

  return 0;
}

void run_testcase(unsigned player_count) {
    unsigned max_idx = 0, second_max_idx = 0;
    int player_strengths[player_count];
    for (unsigned i = 0; i < player_count; i++) {
        cin >> player_strengths[i];
        if (player_strengths[i] >= player_strengths[max_idx]) {
            second_max_idx = max_idx;
            max_idx = i;
        } else if (player_strengths[i] > player_strengths[second_max_idx]) {
            second_max_idx = i;
        }
    }

    for (unsigned i = 0; i < player_count; i++) {
      cout << player_strengths[i] - player_strengths[max_idx != i ? max_idx : second_max_idx] << " ";
    }
    cout << endl;
    return;  
}