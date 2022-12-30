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

int main() {
    string s;
    cin >> s; 

    vector <int> pr = prefix_function(s);
    int cnt = 0;
    for (int i = 1; i < pr.size(); i++) {
        if(i % 2 == 0) {
            int k = i - pr[i - 1];
            if((i / k) % 2 == 0) {
                cnt++;
            }
        }
    }
    cout << cnt;
}