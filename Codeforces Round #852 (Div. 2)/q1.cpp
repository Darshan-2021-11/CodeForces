#ifdef ONPC
	#define _GLIBCXX_DEBUG
#endif
//#include <bits/stdc++.h>
#include <iostream>
#define sz(a) ((int)((a).size()))
#define char unsigned char

using namespace std;
// mt19937 rnd(239);
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;

int solve() {
	ll p1, p2, n, m, tp1;
	ll price;
	cin >> p1 >> p2;
	cin >> n >> m;

	tp1 = (n*m)/(m+1);

	if(p1 < p2){
		if(n < m){
			cout << n*p1 << "\n";
		} else {
			price = (tp1+(n-(tp1/m+tp1)))*p1;
			cout << price << "\n";
		}
	} else {
		if((n < m) || (m*p1 > (m+1)*p2)){
			cout << n*p2 << "\n";

		} else {
			if(m*p1 < (m+1)*p2)
			price = tp1*p1 + (n-(tp1+tp1/m))*p2;
			cout << price << "\n";
		}
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
		// cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
	#endif
}
