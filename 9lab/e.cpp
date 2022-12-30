#include <iostream>
#include <string> 
#include <vector>
using namespace std;

vector<int> prefix_function(string s) { 
  vector<int> pr(s.length());
  for (int i = 1; i < s.length(); i++) {
    int j = pr[i - 1];
    while (j > 0 && s[i] != s[j]) j = pr[j - 1];
    if (s[i] == s[j]) j++;
    pr[i] = j;
  }
  return pr;
}

vector<int> kmp(string word, string patttern) { 
  vector<int> solve;
  string concat = patttern + '%' + word;
  vector<int> pr = prefix_function(concat);
  for (int i = patttern.size() + 1; i < concat.size(); i++) {
    if (pr[i] == patttern.size()) {
            solve.push_back(i - 2 * patttern.size()); 
            }
    }
        return solve;
}


int main() {
  
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        int k;
        cin >> s >> k;
        vector <int> pi = prefix_function(s);
        int last = pi[s.size() - 1];
        cout << (s.size() - last )* k + last << endl;
    }
}