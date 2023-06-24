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
	int n, tmp = 0;
	string result;
	cin >> n;

	map<int, int> count;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		count[-1 * tmp]++;
	}

//	for (auto i: count) cout << i.first << " " << i.second << " ";
//	cout << "| ";

	if (n == 1) {
		if (tmp == 0) result = "YES\n";
		else result = "NO\n";
		cout << result;
		return 0;
	}

	auto last = count.begin();
	auto second_last = count.begin();
	++second_last;
	// now this keeps track of total robots
	tmp = (last->second) * (last->first * -1 + 1);
//	cout << tmp << " ";

	while (second_last != count.end()) {
		// this `if` condition is necessary since if the numbers are carefully
		// chosen, tmp == n would still not be the correct measure to count the
		// number of robots
		if (second_last->second - last->second < 0) {
			cout << "NO\n";
			return 0;
		}
		tmp += (second_last->second - last->second) * (second_last->first * -1 + 1);
//		cout << tmp << " ";
		last = second_last++;
	}

	if (tmp == n) result = "YES\n";
	else result = "NO\n";
	cout << result;

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

