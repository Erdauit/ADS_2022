#include <iostream>
#include <deque>
#include <stack>
using namespace std;


int main () {
    deque <int> dq;
    stack <int> st;
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < a[i]; j++) {
            st.push(j);
        }
        dq.push_back(a[i]);
        while (!st.empty()) {
            dq.push_front(st.top());
            for (int i = 0; i < st.top(); i++) {
                int val = dq.back();
                dq.push_front(val);
                dq.pop_back();
            }
            st.pop();
        }
        while (!dq.empty()) {
            cout << dq.front() <<" ";
            dq.pop_front(); 
        }
        cout << "\n";
    }

}