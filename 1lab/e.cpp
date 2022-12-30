#include <iostream>
#include <deque>
using namespace std;

int main () {
    int i = 0;
    int cnt = 0;
    int borka = 0;
    int nurs = 0;
    deque <int> boris, nursik;
    for (int i = 0; i < 5; i++) {
        int a;
        cin >> a;
        boris.push_back(a);
    }
    for (int i = 0; i < 5; i++) {
        int b;
        cin >> b;
        nursik.push_back(b);
    }

 while(!boris.empty() && !nursik.empty() && cnt != 1000000){
        int b = boris.front();
        int n = nursik.front();
        boris.pop_front();
        nursik.pop_front();
        
        cnt++;

        if (b == 9 and n == 0){
            nursik.push_back(b);
            nursik.push_back(n);
        }
        else if (b == 0 and n == 9){
            boris.push_back(b);
            boris.push_back(n);
        }
        else if (b > n){
            boris.push_back(b);
            boris.push_back(n);
        }
        else {
            nursik.push_back(b);
            nursik.push_back(n);
        }
    }


if (boris.empty()) cout << "second" << " " << cnt;
    else if (nursik.empty()) cout << "first" << " " << cnt;
    else cout << "blin nichya";
}