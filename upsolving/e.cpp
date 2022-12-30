#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack <int> st;
    stack <int> maxAll;
    int n; cin >> n;
    int max = -999999;
    for (int i = 0; i < n; i++){
        string input; cin >> input;

        if (input == "add") {
            int x; cin >> x;
            st.push(x);
            if(x >= max) {
                max = x;
                maxAll.push(max);
            }
        }
        if (input == "delete") {
            if(st.empty()) {
                continue;
            }
            else {
                if (max == st.top()) {
                    if(maxAll.size() > 1) {
                        maxAll.pop();
                        max = maxAll.top();
                        st.pop();
                    } else {
                        st.pop();
                    }
                } else {
                    st.pop();
                }
            }
        }

        if (input == "getcur") {
            if(st.empty()) {
                cout << "error" << endl;
            }
            else {
                cout << st.top() << endl;
            }
        }

        if (input == "getmax") {
            if (st.empty()) {
                cout << "error" <<'\n';
            } else {
                cout << max <<"\n";
            }
        }
    }
}