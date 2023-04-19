#ifdef ONPC
	#define _GLIBCXX_DEBUG
#endif
#include <iostream>
#define sz(a) ((int)((a).size()))
#define char unsigned char

using namespace std;
// mt19937 rnd(239);
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;

/* This method multiplies the digits to get that if the multiplication is
 * giving the same output as that of the other counterpart... 
 * BUT THE CAVEAT IS THAT THE TOTAL NUMBER OF INPUTS CAN BE 1000, AND THE
 * LARGEST VALUE THAT CAN BE NEEDED TO STORE IN EACH MULTIPLICATION TERMS IS
 * 2^(500) EACH.
 *
 *	int solve() {
 *		int n;
 *		cin >> n;
 *		int a[n], temp1, temp2, k;
 *		for (int i = 0; i < n; i++) {
 *			cin >> a[i];
 *		}
 *		for (int i = 0; i < n; i++) {
 *			temp1 = 3; temp2 = 1;
 *			for (k = 0; k < i; k++) {
 *				if(temp1 == 3) temp1 = 1;
 *				temp1 *= a[k];
 *			}
 *			for (int j = i; j < n; j++) {
 *				temp2 *= a[j];
 *			}
 *			if(temp1 == temp2){
 *				cout << k << "\n";
 *				return 0;
 *			}
 *	
 *		}
 *		cout << -1 << "\n";
 *		return 0;
 *	}
 */

// INSTEAD OF THE PREVIOUS METHOD, WHAT WE DO IS STORE THE NUMBER OF 2's INPUT
// WE ARE GIVEN AND COMPARE THE TOTAL NUMBER OF 2's INSTEAD, WHICH WOULD REDUCE
// THE OPERATION FROM O(N^2) TO O(N), AND THE VARIABLE WOULD INFACT WOULD BE
// ABLE TO STORE THIS VALUE TOO
int solve() {
	int n;
	cin >> n;
	int a[n], twos = 0, k, l = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if(a[i] == 2) twos++;
	}
	if(twos&1) {
		cout << -1 << "\n";
		return 0;
	} else {
		if(!twos){
			cout << 1 << "\n";
			return 0;
		} else {
			for (k = 0; l < twos/2 ; k++) {
				if(a[k] == 2) l++;
			}
			cout << k << "\n";
			return 0;
		}
	}
	return 1;
}

int32_t main() {
	// not giving new line character caused all my test cases to fail ;(
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
		//cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
	#endif
}
