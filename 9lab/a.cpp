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

bool kmp(string word, string patttern) { 
  vector<int> solve;
  string concat = patttern + '%' + word;
  vector<int> pr = prefix_function(concat);
  for (int i = patttern.size() + 1; i < concat.size(); i++) {
    if (pr[i] == patttern.size()) {
            solve.push_back(i - 2 * patttern.size()); 
            return true;
        }
    }
        return false;
}

void computeLPSArray(string pat, int M, int* lps);
 
void KMPSearch(string pat, string txt,string a)
{
    vector<int> ans;
    int M = pat.size();
    int N = txt.size();
    int ss = a.size();
 
    // int lps[M];

    // computeLPSArray(pat, M, lps);
 
    int i = 0; 
    int j = 0; 
    int rec=0;
    while (i<txt.size() && j<M) {
        
        if(rec==0 && j==0 && txt[i]==pat[0]){
            rec++;
            j++;
            if(rec==M){
                cout<<1;
                return;
            }
        }
        else if(rec!=0 && txt[i]==pat[j]){
            
            j++;
            rec++;
            if(rec==M){
                int ans=0;
                if((i+1)%ss!=0) ans=1;

                cout<<((i+1)/ss)+ans;
                return;
            }
        }
        else if(rec!=0 && txt[i]!=pat[j]){
            rec=0;
            j=0;
            
        }
        if(txt.size()>M*2000)break;
        
        i++;
        if(i+1==txt.size()) txt+=a;
    }
    cout<<-1;
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
            else 
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}


int main() {
    string a;
    cin >> a;
    string b;
    cin >> b;
    string text = "";
    int cnt = 0;

    /*if(KMPSearch(b, a)) {
        cout << 1;
        return 0;
    }
    if(KMPSearch(b, text)) {
        cout << cnt << endl;
    }
*/    
    if(a.size() < b.size()) {
        while(text.size() < b.size()) {
            text += a;
            cnt++;
        }
        if(kmp(text, b)) {
            cout << cnt << endl;
            return 0;
        }
        else {
            cnt++;
            text += a;
            if(kmp(text, b)) {
                cout << cnt << endl; return 0;
            }
            else cout << -1 << endl; return 0;
        }
    }
    else {
        if(kmp(a, b)) {
            cout << 1;
            return 0;
        }
        else cout << -1 << endl; return 0;
    }
    return 0;
}