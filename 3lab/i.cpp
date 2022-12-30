#include <iostream>

using namespace std;


int bs(int a[], int n, int x){
    int res = -1;
    int l = 0; 
    int r = n - 1;
    int m;

    while(l <= r){
        m = l + (r - l)/ 2;
        if(x < a[m]){
           r = m - 1;
        }else if(x == a[m]){
           break;
           return true;
        }else{
            l = m + 1;
        }
    }

    if(a[m] == x){
        return true;
    } else {
        return false;
    }

    return res;
}

int main(){
    int t; cin >> t;
    int a[t];
    int n = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < t; i++){
        cin >> a[i];
    }
    int x;
    cin >> x;

    if (bs(a, n, x)) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}