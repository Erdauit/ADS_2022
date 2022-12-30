#include <iostream>
#include <stack>
using namespace std;

int main () {
    stack<char> bubu;
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (!bubu.empty()) {
            if (bubu.top() == s[i]) {
                bubu.pop();
            }
            else {
                bubu.push(s[i]);
            }
        }
        else {bubu.push(s[i]);
        }
    }

    if (bubu.empty()) {
        cout << "YES";
    } else {
        cout <<"NO";
    }
}