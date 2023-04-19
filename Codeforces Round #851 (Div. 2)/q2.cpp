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

/*
 * // O(n) method to solve the question
 * int SOD(int x){
 * 	// SOD: sum of digits
 * 	int sum = 0;
 * 	while(x){
 * 		sum += x % 10;
 * 		x /= 10;
 * 	}
 * 	return sum;
 * }
 * 
 * int solve() {
 * 	int n;
 * 	cin >> n;
 * 	int j, k;
 * 	for (int i = 0; i < n; i++) {
 * 		j = n-i;
 * 		k = SOD(i) - SOD(j);
 * 		if(k == 1 || k == -1 || k == 0){
 * 			cout << i << " " << j << "\n";
 * 			break;
 * 		}
 * 	}
 * 	return 0;
 * }
 */

// Note: (I) This fails if the value of "n" is ${1:odd}9, e.g. 19/2 = 9, and 9+1 is
// 10, so the difference of the sum of digits is not different by at most 1.
//
// (II) Again the test cases fail when there comes three digit numbers, e.g.
// 999, by our logic, 999 = 495 + 504, but the SOD of both the numbers are not
// different by 1 or 0.
/*
 *	int solve() {
 *		int n, m;
 *		cin >> n;
 *		m = n/2;
 *		if(n&1) {
 *			int k = n%100;
 *			if(k == 19 || k == 39 || k == 59 || k == 79)
 *				cout << m-4 << " " << m+5 << "\n";
 *			else cout << m << " " << m+1 << "\n";
 *		}
 *		else
 *			cout << m << " " << m << "\n";
 *	
 *		return 0;
 *	}
 */

// this logic is taken by me from a youtube video
// this tells that if the number is even, just print the number divided by 2
// but in other case, divide each individual digit by 2, and substitute in 
// the answer if even, or keep a track of which digit is larger if it is odd
// and substitute the next odd number in other number.
int solve() {
	int n, p = 0, q, flag = 0, r, s;
	cin >> n;
	q = n;
	if(!(n&1)){
		p = n/2;
		cout << p << " " << p << "\n";
		return 0;
	} else {
		// this returns reverse version of the answer
		// note: this method breaks if the flag is zero and we are not adding 1
		// to p
		// because, let's say n = 161. When it takes the very last digit that
		// is 1, it does not add 0 to the number since zero is taken as
		// nothing, but when we subtract the value of p from n, the zero is not
		// reflected in the answer, as we reverse the number. It goes like
		// p = 031 = 31(converted and removed the zero, 1st while)
		// p = 13(2nd while)
		// q = 161-13 = 149
		// but SOD of p=4 and q=14, whose difference is definitely greater than
		// 1;
		//
		// OR 
		//
		// WITHOUT DOING ALL THIS, WE COULD DO ALL THE PROCESSES IN A STRING
		// AND NEVER WOULD HAVE TO DEAL WITH THE ZERO PROBLEM AND NEVER NEED TO
		// REVERSE THE NUMBER
		while(q){
			r = q%10;
			q /= 10;
			s = r/2;
			if(r&1){
				if(flag){
					p = p*10 + s;
					flag--;
				} else {
					p = p*10 + s + 1;
					flag++;
				}
			} else {
				p = p*10 + s;
			}
		}
		// reverse to get the actual answer
		q = p;
		r = 0;
		while(q){
			r = r*10 + q%10;
			q = q/10;
		}
		// putting reverse value of p in p
		p = r;
		q = n-p;
		cout << p << " " << q << "\n";
		return 0;
	}
	return 1;
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
//		cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
	#endif
}
