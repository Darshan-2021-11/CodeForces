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
	ll n, k;
	cin >> n >> k;
	ll a[n], cold[k], hot[k];
	for (int i = 0; i < n; i++) {
		ll tmp;
		cin >> tmp;
		a[i] = tmp;
	}
	for (int i = 0; i < k; i++) {
		ll tmp;
		cin >> tmp;
		cold[i] = tmp;
	}
	for (int i = 0; i < k; i++) {
		ll tmp;
		cin >> tmp;
		hot[i] = tmp;
	}
	map<ll,ll> reps;
	for (int i = 0; i < n; i++) {
		reps[a[i]]++;
	}

	ll time = 0;
	for (int i = 0; i < n; i++) {
		ll curr_val = a[i] - 1;
		time += cold[curr_val];
		reps[curr_val]--;
		time += reps[curr_val]*hot[curr_val];
	}

	cout << time << "\n";
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
