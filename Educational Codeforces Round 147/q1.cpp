#include <bits/stdc++.h>
using namespace std;

int main(){
	int t, i;
	cin >> t;
	while(t--){
		string s;
		cin >> s;

		int ans = 1;
		for(i=0; i<(int)s.length(); i++){
			if(i==0) switch(s[i]){
				case '0': cout << "0\n"; break;
				case '?': ans *= 9;
				}
			else if(s[i] == '?') ans *= 10;
		}
		if(s[0]=='0') continue;

		cout << ans << "\n";

	}
	return 0;
}
