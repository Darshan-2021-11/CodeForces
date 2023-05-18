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

	int liars[n];
	set <int> l;
	for (int i = 0; i < n; i++) {
		cin >> liars[i];
		l.insert(liars[i]);
	}
/*
	for (auto i: m){
		if(m.size() == 1) {
			if(i.first != 0)
				cout << -1 << "\n";
			else cout << 0 << "\n";
			return 0;
		}
		else break;
	}

	for (auto it = m.begin(); it != m.end(); it++) {
		tmp = 0;
		for (auto it2 = it; it2 != m.end(); it2++) {
			if(it2->first > it->first) tmp += it2->second;
		}
		it->second = tmp;
	}

	for (auto it = m.begin(); it != m.end(); it++) {
		auto it2 = it;
		it2++;
		if(it2 != m.end())
			if(it->second > it2->first){
				cout << it->second << "\n";
				return 0;
			}
	}
*/
	// base case
	if(l.size() == 1){
		auto it = l.begin();
		if(*it != 0) cout << -1;
		else cout << 0;
		cout << "\n";
		return 0;
	}

	// sorting the array
	sort(liars, liars+n);
	tmp = liars[0];
	for (int i = 1; i < n; i++) {
		if(liars[i] != tmp){
			if(n-i < liars[i]){
				if(liars[n-i] >= liars[i]) cout << -1;
				else cout << n-i;
				cout << "\n";
				return 0;
			}
			tmp = liars[i];
		}
		else continue;
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
