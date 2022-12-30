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




void computeLPSArray(string pat, int M, int* lps);
 
vector<int> KMPSearch(string pat, string txt)
{
    vector<int> ans;
    int M = pat.size();
    int N = txt.size();
 
    int lps[M];

    computeLPSArray(pat, M, lps);
 
    int i = 0; 
    int j = 0; 
    while ((N - i) >= (M - j)) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
 
        if (j == M) {
            ans.push_back(i - j + 1);
            j = lps[j - 1];
        }
 

        else if (i < N && pat[j] != txt[i]) {

            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return ans;
}
 
void computeLPSArray(string pat, int M, int* lps)
{

    int len = 0;
 
    lps[0] = 0; 

    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else 
        {
            
            if (len != 0) {
                len = lps[len - 1];

            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
 

int main()
{
    string text;
    string pat;
    getline(cin, text);
    getline(cin, pat); 
    vector <int> ans = prefix_function(text);
    // cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }

    return 0;
}