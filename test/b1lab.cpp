#include <iostream>
#include <stack>
using namespace std;

int main () {
    stack <int> st;
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        
        if (st.top() > a[i]) {
            while (!st.empty()) {
                st.pop();
            }
        }
        if (st.empty()) {
            cout << -1 << " ";
            st.push(a[i]);
        }

        else if (st.top() <= a[i]) {
            cout << a[i] << " ";
        }
        st.push(a[i]);
    }
}