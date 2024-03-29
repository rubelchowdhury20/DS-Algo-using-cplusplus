/**
 * January 2013 Long Challenge at Codechef
 *
 * Problem:     SALARY - The Minimum Number Of Moves
 * Author:      Anton Lunyov (Tester and Editorialist)
 * Complexity:  O(N * maxW) per test
 * Timing:      0.46 out of 1
 *
 * Description:
 * At each step we at first check whether all salaries are equal
 * and if no, decrease by 1 all maximum salaries
 * increasing by 1 the answer for each decreased salary
 */
#include <iostream>
#include <vector>
using namespace std;

int main() {
	// input number of tests
	int T;
	cin >> T;

	// loop over tests
	for (int t = 0; t < T; ++t) {

		// input number of workers
		int N;
		cin >> N;

		// input their salaries
		vector<int> W(N);
		for (int i = 0; i < N; ++i) {
			cin >> W[i];
		}

		int moves = 0;

		while (true) {
			// checking whether all salaries are equal
			bool equal = true;
			for (int i = 1; i < N && equal; ++i) {
				if (W[i] != W[0]) {
					equal = false;
				}
			}
			// and stop the process in this case
			if(equal) {
				break;
			}

			// otherwise we find maximum salary
			int maxW = 0;
			for (int i = 0; i < N; ++i) {
				maxW = max(maxW, W[i]);
			}

			// and decrease by 1 all maximum salaries
			// increasing by 1 the answer after each decreased salary
			for (int i = 0; i < N; ++i) {
				if (W[i] == maxW) {
					W[i]--;
					moves++;
				}
			}
		}

		cout << moves << endl;
	}
}
