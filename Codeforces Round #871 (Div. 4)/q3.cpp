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
	int n;
	cin >> n;
	map<int, vector<string>> ts;
	int m; string st;

	for (int i = 0; i < n; i++) {
		cin >> m >> st;
		ts[m].emplace_back(st);
	}

	int s1 = 0, s2 = 0, s12 = 0; //stores time required for skills
	for(auto i:ts){
		for (int s = 0;  s < (int)i.second.size(); s++) {
			if(i.second[s] == "10"){if(!s1) s1 = i.first;}
			else if(i.second[s] == "01") {if(!s2) s2 = i.first;}
			else if(i.second[s] == "11") {if(!s12) s12 = i.first;}
			
			else continue; // never occurs
		}
	}

	if((s1 && s2) || ((!s1 && !s2) || s12)){
		if(s1 && s2 && s12) {
			if(s12 < s1+s2) cout << s12;
			else cout << s1+s2;
		} else if(s1 && s2) cout << s1+s2;
		else if(s12) cout << s12;
		else cout << -1;

		cout << '\n';
	}
	else cout << -1 << '\n';
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
