#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
vector<int> primes;

bool isPrime[100];
void f(int x) { 
 int n = x * x;
 for (int i = 2; i <= n; i++) {
        isPrime[i] = true ;
    }
    isPrime[0] = isPrime[1] = false ;

    for (int i = 2; i <= n/2; i++) {
        if (isPrime[i] == true) {
            int j = i + i;
            while (j <= n) {
                isPrime[j] = false ;
                j = j + i ;
            }
        }
    }

    for (int i = 2; i < n; i++) {
        if(isPrime[i] == true) {
        primes.push_back(i);
            
    }
}
}

int main () {

    int a;
    cin >> a;
    f(a);
    cout << primes[a-1];

    
}