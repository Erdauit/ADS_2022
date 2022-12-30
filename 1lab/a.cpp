#include <iostream>
#include <stack>
#include <deque>
#include <vector>

using namespace std;

int main () {
    deque <int> dq;
    stack <int> st;
    vector <int> v;
    int c; cin >> c;
    for (int i = 0; i < c; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    for (int i = 0; i < v.size(); i++) {
        for (int j = 1; j < v[i]; j++) {
            st.push(j);
        }
        dq.push_back(v[i]);
        while (!st.empty()) {
            dq.push_front(st.top());
            // int prev = st.top();
            // st.pop();
            for (int j = 0; j < st.top(); j++) {
                int val = dq.back();
                dq.push_front(val);
                dq.pop_back();
            }
            st.pop();

        }
        while (!dq.empty()) {
            cout << dq.front() << " ";
            dq.pop_front();
        }
        cout << endl;
    
    }
    return 0;
}