#include <iostream>
#include <vector>

using namespace std;

long long MOD = 1e15 + 9;
long long X = 97;

long long getHash(string s) {
    long long hash = 0;
    long long curX = 1;
    for (int i = 0; i < s.size(); i++) {
        long long curHash = (s[i] - 'a' + 1) * curX % MOD;
        hash = (hash + curHash) % MOD;
        curX = (curX * X) % MOD;
    }
    return hash;
}

vector<long long> getPrefixHashes(string s) {
    vector<long long> hashes(s.size());
    long long curX = 1;
    for (int i = 0; i < s.size(); i++) {
        hashes[i] = (s[i] - 'a' + 1) * curX % MOD;
        if (i != 0) {
            hashes[i] = (hashes[i] + hashes[i - 1]) % MOD;
        }
        curX = (curX * X) % MOD;
    }
    return hashes;
}

long long rabinKarp(string s, vector<long long> &hashes, string sub) {

    long long smallHash = getHash(sub);

    long long cnt = 0;
    for (int i = 0; i < s.size() - sub.size() + 1; i++) {
        long long hashDif = hashes[i + sub.size() - 1];
        if (i != 0) hashDif -= hashes[i - 1];
        if (hashDif < 0) hashDif += MOD;
        if (i != 0) smallHash = (smallHash * X) % MOD;
        if (smallHash == hashDif) {
            cnt++;
        };
    }
    return cnt;
}



int main() {
    string s; cin >> s;
    long long q; cin >> q;
    vector <long long> hashes = getPrefixHashes(s);
    for (int i = 0; i < q; i++){
        long long l, r;
        cin >> l >> r;
        string sub = s.substr(l - 1, r - l + 1);

        long long ans = rabinKarp(s, hashes, sub);
        cout << ans << endl;

    }
}