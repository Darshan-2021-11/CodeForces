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

/* THIS ONLY WORKS WHEN THE CHARACTERS IN THE STRING ARE UNIQUE, BUT IT IS NOT
 * THE CASE, THEY CAN REPEAT
	int solve() {
		int n;
		cin >> n;
		if(n == 2){
			cout << "YES" << "\n";
			return 0;
		}
		map <char, int> isPallindrome;
		for (int i = 0; i < 2*n-2; i++) {
			string s;
			cin >> s;

			if((int)s.size() == n-1) {
				for (auto j: s) {
					//cout << j << " ";
					isPallindrome[j]++;
				}
			}
		}

		int val1=0, val2=0;
		for(auto& i: isPallindrome){
			//cout << "isPallindrome " << i.first << " " << i.second << " ";
			if(i.second % 4) val1++;
			else if(i.second == 2) val2++;
		}
		if((n&1 && val1==(n>>1)-1 && val2==2) || (!(n&1) && val1==(n>>1)-1 && val2==1)) cout << "YES";
		else cout << "NO";

		cout << "\n";
		return 0;
	}
 */

int solve() {
	int n;
	cin >> n;

	//	string given, rev;
	vector <string> given;
	// first two strings store parts of string, third the string itself and
	// then fourth string the reversed string
	for (int i = 0; i < 2*n-2; i++) {
		string s;
		cin >> s;
		if((int)s.size() == n-1){
			// if size is n-1, we get to know the maximum string in order, and
			// extract the remaining one character form the other n-1 length
			// string, since one would be suffix and other will be prefix of
			// pallindrome, this would do the job of constructing the full
			// string
			//	if((int)given.size() == 0)
			//		given.assign(s);
			//	// we use $var.at(n-2) since size of string $var is n-1 and we need
			//	// the last element which is (n-1)-1
			//	else given += s.at(n-2);
			//
			// NOTE: since the input gives it in any order, it is possible we
			// do not construct the string in right order, failing test cases
			//
			// NOTE: this created some undesirable consequence, instead should
			// check if the 2nd character of one is equal to 1st character of
			// the other and then develop the string.
			given.push_back(s);
		}
	}

	// the original string to be stored in the 3rd position of given vector
	string s;
	// this does not work if the length of the string is 1. So we add special
	// case for that.
	if(n==2){
		// not written the else condition for the above if condition and probably
		// got like 3 runtime errors
		if(given[0].compare(given[1])==0)
			cout << "YES";
		else cout << "NO";

		cout << "\n";
		return 0;
	}

	// this approach of recompleting the string is complete trash, you must
	// check each and every character before concluding if you're doing this
	// approach, even though its bad and less efficient.
	//
	// eg. str = "ccac", str1 = "cca", str2 = "cac"; 2nd character of one is 
	// same as that of the first character of other.
	// but if we match str2 as 1st string with str1; we get "cacc" which is not
	// the original string "ccac";
	//
	// Hence we check all of them.
	bool flag = true;
	for(int i=1; i < n-1; i++){
		if(given[0].at(i) != given[1].at(i-1))
			flag = false;
	}
	if(flag) {
		s.assign(given[0]);
		s += given[1].at(n-2);
		given.push_back(s);
	} else {
		s.assign(given[1]);
		s += given[0].at(n-2);
		given.push_back(s);
	}
	// reverse of the given string
	s = "";
	for (int j = n-1; j >= 0; j--)
		s += given[2].at(j);

	given.push_back(s);

	//	cout << given[2] << " " << given[3] << " ";

	if(given[2].compare(given[3]) == 0) cout << "YES";
	else cout << "NO";

	cout << "\n";
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
