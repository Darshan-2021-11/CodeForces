#ifdef ONPC
	#define _GLIBCXX_DEBUG
#endif
// #include <bits/stdc++.h>
#include "bits/stdc++.h"
#define sz(a) ((int)((a).size()))
#define char unsigned char

using namespace std;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;

int solve() {
	int n, count = 1, maxCount = 0;
	cin >> n;
	char curr, prev;
	// We need minimum two numbers to compare with for one arrow, but the
	// subsequent requirement of numbers is only increased by one, if another
	// arrow is present since there is already one element in the left.
	//
	// Hence, count is always initialized to 1 whenever reset.
	for (int i = 0; i < n; i++) {
		// we first find the longest sequence of same characcter `<` or `>` and
		// then just add 1 to it to get the answer.

		cin >> curr;
		if(i != 0) {
			if(curr == prev) count++;
			else {
				if(count > maxCount) maxCount = count;
				count = 1;
			}
		}
		prev = curr;
	}
	// Checking if the last condition has the maximum count or not
	if(count > maxCount) maxCount = count;

	cout << maxCount + 1 << '\n';
	return 0;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int TET = 1e9;
	cin >> TET;
	for (int i = 1; i <= TET; i++) {
		if (solve()) {
			break;
		}
		#ifdef ONPC
			cout << "__________________________" << "\n";
		#endif
	}
	#ifdef ONPC
		cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC <<
		"second(s)" << "\n";
	#endif
}
