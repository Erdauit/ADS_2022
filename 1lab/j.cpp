#include <iostream>
#include <cmath>
#include <deque>
using namespace std;

int main () {

    char s;
    int x;
    bool b = true;
    deque<int> erda;
    while (b) {
        cin >> s;

        if (s == '+') {
            cin >> x;
            erda.push_front(x);
        }
        if (s == '-') {
            cin >> x;
            erda.push_back(x);
        }
        if (s == '*') {
            if (erda.empty()) {
                cout << "error" <<endl;
            }
            else {
            cout << erda.front() + erda.back() << endl;
            if (!erda.empty()) erda.pop_front();
            if (!erda.empty()) erda.pop_back();
        }

        }
        if (s == '!') {
            b = false;
        }
    }
}
