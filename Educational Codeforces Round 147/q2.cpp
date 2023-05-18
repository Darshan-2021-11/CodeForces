#include <bits/stdc++.h>
using namespace std;

int main(){
	int t, n, tmp, l, r;
	cin >> t;

	while(t--){
		cin >> n;
		// let `l` start from 0 `r` end at n-1
		// we will later add 1 to both of them when printing
		l=0; r=n-1;
		vector<int> v1, v2;
		for(int i=0; i<n; i++){
			cin >> tmp;
			v1.push_back(tmp);
		}
		for(int i=0; i<n; i++){
			cin >> tmp;
			v2.push_back(tmp);
		}
		// tmp will help us to assign l and r
		tmp = 0;
		for(int i=0; i<n; i++){
			if(v1[i]!=v2[i]){
				if(!tmp){
					l = i;
					tmp++;
				}
				else r = i;
			}
		}
		// checking for similar elements in either side of 
		// the sorted subarray
		while(l>0 && v1[l-1] == v2[l-1] && v2[l-1] <= v2[l]) l--;
		while(r<n-1 && v1[r+1] == v2[r+1] && v2[r] <= v2[r+1]) r++;

		cout << l+1 << " " << r+1 << "\n";
	}
	return 0;
}
