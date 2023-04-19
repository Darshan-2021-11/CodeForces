#ifdef ONPC
	#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
#define char unsigned char

using namespace std;
// mt19937 rnd(239);
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;

int solve() {
	int l, m, n;
	cin >> n;
	if(n%2 == 0){
		cout << "No" << "\n";
		return 0;
	}
	cout << "Yes" << "\n";
	if(n == 1){
		cout << n << " " << 2*n << "\n";
		return 0;
	}
	l = 2*n;
	for (int i = 0; i < n; i++) {
		m = 2*i+1;
		if(m <= n){
			cout << m << " " << l-- << "\n";
		} else {
			break;
		}
	}
	m = n - 1;
	for (int i = n+1; i <= l; i++) {
		cout << i << " " << m << "\n";
		m -= 2;
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
			cout << "__________________________" << endl;
		#endif
	}
	#ifdef ONPC
		cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
	#endif
}
