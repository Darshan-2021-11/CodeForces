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
	long long n, m, a, ans;
	cin >> n >> m >> a;

	/* USELESS CODE
	if(n <= a && m <= a) ans = 1;
	else if(n <= a){
		if(m % a) ans = m/a + 1;
		else ans = m/a;
	}
	else if(m <= a){
		if(n % a) ans = n/a + 1;
		else ans = n/a;
	}
	else{
		ans = n*m/(a*a);
		// for ensuring the plot is completely filled
		if(n % a) {
			ans += n/a + 1;
		}
		if(m % a) {
			ans += m/a + 1;
	}
	}
	*/
	n = n%a? (n/a + 1): n/a;
	m = m%a? (m/a + 1): m/a;

	ans = n*m;

	cout << ans << '\n';
	return 0;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int TET = 1;
	// cin >> TET;
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
