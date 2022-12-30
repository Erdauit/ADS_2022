#include <iostream>
using namespace std;



int main() {
    long long n; cin >> n;
    int count = 0;
    bool* isPrime = new bool[n];
    for(long i = 2; i<n; i++){
            isPrime[i] = true;
    }

    for(long long i = 2; i * i <= n; i++){
            if(!isPrime[i]) continue;
            for(long long j = i * i; j <= n ; j+=i){
                    isPrime[j]= false;
            }
    }

    for(long long i =2; i <= n; i++){
        if(isPrime[i]) {
            if (n % i == 0) {
                count++;
            }
        };
    }
    cout << count << endl;
}