#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

long long MOD = 1e15 + 9;
long long X = 31;

// long long getHash(string s) {
//     long long hash = 0;
//     long long curX = 1;
//     for (int i = 0; i < s.size(); i++) {
//         long long curHash = (s[i] - 'a' + 1) * curX % MOD;
//         hash = (hash + curHash) % MOD;
//         curX = (curX * X) % MOD;
//     }
//     return hash;
// }

long long otvet(string str){
    unordered_map <long long, bool> hashes;
    for (long long i = 0; i < str.size(); i++) {
        long long d = 0;
        for (long long j = i; j < str.size(); j++) {
            d = (X * d + str[j]) % MOD;

            if (hashes.find(d) == hashes.end()) {
                hashes[d] = true;
            }
        }
    }
    return hashes.size();
}


int main() {
    string s;
    cin >> s;
    cout << otvet(s);
}