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
	string s, t;
	int n;
	cin >> n;

	cin >> s;

	// We need to find the number of unique musical nodes consisting of two
	// notes. This can be donw by seeing exactly how many of individual two
	// strings can be extracted from the given string.
	//
	// For this we use map or set to only store the unique elements.
	
	set <string> notes;

	for (int i = 0; i < n-1; i++) {
		t = s[i];
		t += s[i+1];
		// We can also use the assign function of string class, for e.g.
		// ` t.assign(s, i, 2);`
		// where 't' is the original string, `s` is the source string, `i` is
		// the primary location to start the string from, and `2` here is the
		// length of the string to splice from.

		notes.insert(t);
	}
	cout << notes.size() << '\n';
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
