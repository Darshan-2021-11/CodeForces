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

int helperRecursion(int n, const int m){
	if(m > n){
		// cout << "NO\n";
		return 0;
	}
	else if(n == m){
		// cout << "YES\n";
		return 1;
	}

	if(n > m && !(n%3)){
		n = n/3;
		int a1 = helperRecursion(n, m) , a2 = helperRecursion(2*n, m);
		return a1 | a2;
	}

	return 0;
}

int solve() {
	int n, m;
	cin >> n >> m;
	if(helperRecursion(n,m)) cout << "YES\n";
	else cout << "NO\n";
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
