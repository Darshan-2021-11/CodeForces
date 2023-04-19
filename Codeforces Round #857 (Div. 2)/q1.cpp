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
	int n, tmp;
	cin >> n;

	vector<char> likes;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if(tmp > 0) likes.push_back(1);
		else likes.push_back(0);
	}

	tmp = count(likes.begin(), likes.end(), 1);

	for (int i = 1; i <= n; i++) {
		if(i <= tmp) cout << i << " ";
		else cout << --tmp << " ";
	}
	cout << "\n";

	tmp = count(likes.begin(), likes.end(), 0);

	for (int i = 1; i <= n; i++) {
		if(i <= 2*tmp) {
			if(i&1) cout << "1 ";
			else cout << "0 ";
		}
		else cout << i - 2*tmp << " ";
	}
	cout << "\n";
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
