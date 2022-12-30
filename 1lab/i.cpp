#include <iostream>
#include <deque>
#include <map>
using namespace std;


int main () {
    int a; cin >> a;
    string s; cin >> s;
    deque <char> q;
    map <char, int> m, delet;

    for (int i = 0; i < s.size(); i++) {
        q.push_back(s[i]);
        m[s[i]]++;
    }
    while (m['S'] > 0 && m['K'] > 0) {

        if (delet[q.front()] > 0) {
            delet[q.front()]--;
            m[q.front()]--;
            q.pop_front();
        }
        else{
            if (q.front() == 'S') {
                delet['K']++;
            } else {
                delet['S']++;
            }
            q.push_back(q.front()); 
            q.pop_front();
        }


    }

    if (m['S'] != 0) {
        cout << "SAKAYANAGI";
    } else cout << "KATSURAGI";

}