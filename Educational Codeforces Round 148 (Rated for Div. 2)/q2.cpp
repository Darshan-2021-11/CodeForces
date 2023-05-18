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
	int n, k;
	cin >> n >> k;
	ll arr[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr+n);

	int i = 0, j = n-1, f = 0;
	for (int m = 0; m < k-1; m++) {
		if((arr[i] + arr[i+1]) > arr[j]){
			// handles the last value of `k` too
			j -= k-m;
			f = 1;
			break;
		} else {
			i += 2;
		}
	}

	if(!f){
		if((arr[i] + arr[i+1]) > arr[j]){
			// if k = 1
			if(i == 0) j--;
			else if(j-1 != i+1){
				if(arr[i-2] + arr[i-1] + arr[i] + arr[i+1] > arr[j] + arr[j-1]){
					i -= 2;
					j -= 2;
				} else {
					i += 2;
				}
			} else j--;
		} else {
			i += 2;
		}
	}

	ll m_sum = 0;
	for (int m = i; m <= j; m++) {
		m_sum += arr[m];
	}

	cout << m_sum << '\n';
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
