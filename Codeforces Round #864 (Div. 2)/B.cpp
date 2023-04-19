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
	int n, k, t, nsq, diff = 0; // difference of elements if blue(0) or red(1)
	cin >> n >> k;
	nsq = n*n;

	vector <int> m;

	for(int i = 0; i < nsq; i++){
		cin >> t;
		m.push_back(t);
	}
	// int iterations = 0;

/*
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n-i-1; j++) {
//			// The reason why I am not getting right elements in the mirror
//			// image, we want 180deg vertical and 180deg horizontal at once
//			// rotation, What this formula does is the transpose of matrix,
//			// that does not reverse the coordinates as given in the
//			// question...
//			// LOGIC CORRECT, CODE WRONG!
//			// if(m[i*n +j] != m[n*(n-j)-i-1]) diff++;
//			//
//	
//			if(m[i*n + j] != m[n*(n-i)-j-1]) diff++;
//			// if(m[i*n + j] != m[n*(n-i)-j-1]) cout << i+1 << " " << j+1 << " value = " <<m[i*n+j] << " mirror val=" << m[n*(n-i)-j-1] << " iter = " << ++iterations << "\n";
//			cout << i+1 << " " << j+1 << " value = " <<m[i*n+j] << ", mirror: " << n-i << " " << n-j << " mirror val=" << m[n*(n-i)-j-1] << " iter = " << ++iterations << "\n";
//		}
//	}
// */


// THE CONCEPT OF THE FOR LOOP IS WRONG, WE NEED TO RUN THE ITERATION FROM
// 1 TO N^2/2 FOR GETTING ALL THE ACTUAL MIRROR ELEMENT	*/
for (int i = 0; i < (nsq>>1); i++) {
	if(m[i] != m[nsq-i-1]) diff++;
}

	int res = k - diff;
	// cout << "\n res = " << res << "\n";
	// If the resulting number after seeing different squares is 0 or multiple
	// of 2, it is completely possible for the squares to be rotated 180deg
	// IF N IS EVEN
	if((!(n&1)) && !(res&1) && (res >= 0)) cout << "YES\n";

	// Also missed the cases where `n` is odd and the colour of the middle
	// element can be changed any number of times and would not affect the
	// result
	// IF N IS ODD
	else if((n&1) && res >=0) cout << "YES\n";
	// Missed the limiting case where n=1, any element will pass the test
	else if(n==1) cout << "YES\n";
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
