#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
vector<int> primes;

bool b(int b) {
    if (b == 1)  return false;

    for (int i = 2; i <= sqrt(b); ++i) {
        if (b % i == 0) {
            return false;
        }

    }
        return true;
}

void isPrime(int x) {
    vector<int> primes(x, 0);
    int it = 0;
    int cur = 2;
    bool prime = true;
    while (it != x) {

        if (b(cur)) {
            it += 1; 
            primes[it] = cur;     
 
        }
        cur += 1;
    }
    cout << primes[x];
    return;
}


int main () {

    int a;
    cin >> a;
    isPrime(a);


    
}