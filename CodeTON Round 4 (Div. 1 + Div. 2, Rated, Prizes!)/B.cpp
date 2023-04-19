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
	ll n, m;
	cin >> n;
	if(!(n&1)) cout << "-1\n";
	else{
		vector <int> spells;
		while(n != 1){
			m = ((n+1)>>1);
			if(m & 1){
				n = m;
				spells.push_back(1);
			} else {
				n = ((n-1)>>1);
				spells.push_back(2);
			}
		}

		cout << spells.size() << "\n";
		for (auto i = spells.rbegin(); i != spells.rend(); i++) {
			cout << *i << " ";
		}
		cout << "\n";
	}
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
