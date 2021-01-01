/**
 * January 2013 Long Challenge at Codechef
 *
 * Problem:     SALARY - The Minimum Number Of Moves
 * Author:      Anton Lunyov (Tester and Editorialist)
 * Complexity:  O(N) per test
 * Timing:      0.00 out of 1
 *
 * Description:
 * The asnwer is sumW - N * minW,
 * where sumW is the sum of all salaries
 * and minW is the minimal salary
 */
#include <iostream>
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

		// init sum and minimum
		// since each salary is <= 10000
		// minimum could be init by 10000
		int sumW = 0, minW = 10000;

		for (int i = 0; i < N; ++i) {

			// input salary of i-th worker
			int Wi;
			cin >> Wi;

			// update sum and minimum
			sumW += Wi;
			minW = min(minW, Wi);
		}

		// output the result
		int res = sumW - N * minW;
		cout << res << endl;
	}
}
