#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector <long long> v;

void toVector(long long decimal) {
    while(decimal > 0) {
        v.push_back(decimal % 2);
        decimal /= 2;
    } // vector with binary number [1,0,0]
}
bool proverka() {
    stack <long long> st;    
    for (long long i = 0; i < v.size(); i++) {
        if (st.empty()) {
            st.push(v[i]);
        }
        else if(v[i] == 1 && st.top() == 0) {
            st.pop();
        } 
        else {
            st.push(v[i]);
        }
    }
    v.clear();

    if (st.empty()) {  
        return true;
    }
    return false;    
}

int main() {
    long long n;
    cin >> n;
    while(n--) {
        long long x; cin >> x;
        toVector(x);
        if(proverka()) cout << "YES"<< endl;
        else cout << "NO" << endl;
    }
    // toVector(n);
    // for (int i = 0; i < v.size(); i++) {
    //     cout << v[i] <<" ";
    // }
}