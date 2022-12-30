#include <iostream>
#include <stack>

using namespace std;

int main () {
    int a; cin  >> a;
    int b[a];
    stack <int> st;
    for (int i = 0; i < a; ++i) {
        cin >> b[i];

        while ((!st.empty()) && (st.top() > b[i])) {
            st.pop();
        }
        if (st.empty()) {
            cout << -1 << " ";
        }
        else {
            cout << st.top() << " ";
        }
            st.push(b[i]);
    }
    return 0;
}