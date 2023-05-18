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
	const int modulo = 1e9+7;
	int n, index = 0;
	cin >> n;
	const int nminusone = n-1;

	ll a[n], b[n], rearrangements = 1;
	int indices[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	sort(a, a+n);
	sort(b, b+n);

	for (int i = 0; i < n; i++) {
		if(a[i] > b[i]) continue;
		else {
			cout << 0 << '\n';
			return 0;
		}
	}

	for (int i = 0; i < n; i++) {
		while(a[index] <= b[i] && index < n) index++;
		indices[i] = n - index;
		//	cout << indices[i] << ' ';
	}
	//	cout << '\n';

	for (int i = n-1; i >= 0; i--) {
		rearrangements *= indices[i] - (nminusone - i);
		//	cout << rearrangements << ' ';
		rearrangements %= modulo;
	}
	//	cout << '\n';

	cout << rearrangements << '\n';
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
