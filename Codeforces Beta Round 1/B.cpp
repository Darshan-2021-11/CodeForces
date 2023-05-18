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

vector<string> countBP(string s){
	// we check how many times its alphabet or not changes, based on which we
	// calculate the breakpoints and store them in vector of strings
	int type = isalpha(s[0]), temp;
	vector<string> bp;
	string ts;
	ts = s[0];
	for (int i = 1; i < (int)s.size(); i++) {
		temp = isalpha(s[i]);
		if(temp != type){
			//	cout << ts << ' ';
			bp.push_back(ts);
			type = temp;
			ts = s[i];
		} else ts += s[i];
	}

	bp.push_back(ts);

	return bp;
}

int solve() {
	string s, t;
	cin >> s;
	vector<string> bp = countBP(s);

	if(bp.size() == 2) {
		int column = 0;
		for (char c: bp[0]) {
			// adding 1 so that if the character is `A`, it is also counted as
			// 1, other wise will give wrong answer
			// in other words, its inclusive when considered `A`, we are
			// getting numbers.
			column = column * 26 + (c - 'A' + 1);
		}
		cout << 'R' << bp[1] << 'C' << column << '\n';
	} else {
		int column = stoi(bp[3]);
		while(column){
			// similar to the case of alphabets to digits, since `A` is
			// needed to be made exclusive when converting to digits.
			column--;
			t += column % 26 + 'A';
			column /= 26;
		}
		reverse(t.begin(), t.end());
		cout << t << bp[1] << '\n';
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
