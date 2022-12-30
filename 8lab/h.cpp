#include <iostream>
#include <vector>

using namespace std;

long long p = 31;

long long MOD = 1e9 + 7;
long long X = 31;

long long getHash(string s) {
    long long h = 0;
    for (int i = 0; i < s.size(); i++) {
        h = (h * p + (s[i] - 'a' + 1));
    }
    return h;
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

bool rabinKarp(string s, string t) {
    int n = s.length(), m = t.length();
    int hs = getHash(s.substr(0, m));
    int ht = getHash(t);
    int pm = 1;
    for (int i = 0; i < m - 1; i++) {
        pm *= p;
    }
    for (int i = 0; i + m <= n; i++) {
        if (hs == ht)
            return true;
        if (i + m < n)
            hs = (hs - pm * (s[i] - 'a' + 1)) * p + (s[i + m] - 'a' + 1);
    }
    return false;
}


int main() {
    int n; cin >> n;
    string a[n];
    int min_size = 999999999;
    string min_string;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        if (min_size > s.size()) {
            min_size = s.size();
            min_string = s;
        }
        a[i] = s;
    }
    int max_size = 0;
    string res = "";
    for (int i = 0; i < min_size; i++) {
        for (int j = i; j < min_size; j++) {
            string sub = min_string.substr(i, min_size - j);
            bool ok = true;
            for (int k = 0; k < n; k++) {
                if (!rabinKarp(a[k], sub)) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                if (max_size < sub.size()) {
                    max_size = sub.size();
                    res = sub;
                }
            }
        }
    }
    cout << res;
}