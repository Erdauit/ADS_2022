#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque<int> dq;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {

        int c; cin >> c;
        dq.push_back(c);

        while (dq.size() > 0) {  
            if(dq.size() == 1) {
                cout << dq.size() <<" ";
                break;
            }

            if(dq.back() - dq.front() <= 3000) {
                cout << dq.size() << " ";
                break;
            } else {
                dq.pop_front();
            }
        }
    }
}