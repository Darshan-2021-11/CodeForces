#include <iostream>
#define isEven isWaterMelonEvenlyDivisible
using namespace std;

int main(){
    int isEven;
    cin >> isEven;
    if(isEven & 1) cout << "NO";
    else if(isEven == 2) cout << "NO";
    else cout << "YES";
    
    return 0;
    
}
