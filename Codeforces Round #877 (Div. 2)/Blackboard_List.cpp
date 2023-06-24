#include <bits/stdc++.h>
using namespace std;

int solve() {
  // If there is a negative number, then it is surely
  // one of the original numbers, since the later pr-
  // cess only generated positive numbers.

  // Otherwise sort the array and get the largest nu-
  // mber since subtracting with a positive number
  // can never yield a larger number.
   int n;
   cin >> n;
   long long tmp, negative = 0, max = LLONG_MIN;

   for(int i = 0; i < n; i++) {
     cin >> tmp;
     if(negative == 0) {
       if(tmp < 0) negative = tmp;
       else if(tmp > max) max = tmp;
     }
   }
   if(negative != 0) {
     cout << negative;
   } else {
     cout << max;
   }
   cout << '\n';
   return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t;
  cin >> t;
  
  while(t--) solve();
  
  return 0;
}
