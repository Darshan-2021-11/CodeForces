#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
  for(int i=2; i < sqrt(n); i++){
    if(!(n % i)) return false;
  }
  return true;
}

int solve() {
  int n, m, non_prime, product;
  cin >> n >> m;
  product = n * m;

  bool n_prime = isPrime(n), m_prime = isPrime(m);

  if(n_prime && m_prime) {
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m - 1; j++) {
	cout << 
  }
  if(!m_prime) {
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
	cout << product-- << ' ';
      }
      cout << '\n';
    }
  } else {
    int tmp;
    for(int i = 0; i < n; i++) {
      tmp = product;
      for(int j = 0; j < m; j++) {
	cout << tmp << ' ';
	tmp -= n;
      }
      product--;
      cout << '\n';
    }
  }
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
