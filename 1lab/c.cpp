#include <iostream>
#include <stack>
using namespace std;


bool removeBack(string s, string s1) {
    stack<char> on;
    stack<char> tw;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '#' && !on.empty()) {
            on.pop();
        } else if (s[i] != '#') {
            on.push(s[i]);
        }
    }    
    for (int j = 0; j < s1.size(); j++) {
        if (s1[j] == '#' && !tw.empty()) {
            tw.pop();
        } else if (s1[j] != '#') {
            tw.push(s1[j]);
        }
    }
    if (on.size() != tw.size()) {
        return false;
    } 
    if (on == tw) {return true;} else {
        return false;
    }
}


int main () {
    string a, b;
    cin >> a >> b;
    if (removeBack(a, b)) {
        cout <<"Yes";
    } else {
        cout <<"No";
    }
}