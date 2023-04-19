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
	int n, m;
	cin >> n >> m;
	// 4 <= n, m < 1e9
	// Noticed why my test cases failed... 
	// 1. Because I have not checked for same
	// value or difference of y1 and y2 by 1
	//
	// 2. Also note that x1 < x2 and y1 < y2, so m > 1 for this to happen.
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	bool flag11 = false, flag12 = false; // for x1 and y1 since they both are always smaller
						 // than the other coordinates
	bool flag21 = false, flag22 = false; // for x1 and y1 since they both are always larger
						 // than the other coordcoordinates
	bool flag21 = false, flag22nates

	int ans = 4;
	// Submitted 4-5 wrong answers because of this, I thought x1 & x2 or y1 and
	// y2 cannot be same, but the condition says not what's written in note 2,
	// but says x1 <= x2 and y1 <= y2.
	//
	// Added 1 more condition in each of them, let's see how this works out!
	if(x1 == 1 || x1 == n) flag11 = true;
	if(y1 == 1 || y1 == m) flag12 = true;
	if(x2 == 1 || x2 == n) flag21 = true;
	if(y2 == 1 || y2 == m) flag22 = true;

	if((flag11 && flag12) || (flag21 && flag22)) ans = ans - 2;
	else if(flag11 || flag12 || flag21 || flag22) ans--;

	cout << ans << "\n";
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
