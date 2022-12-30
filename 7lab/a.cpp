#include <iostream>
#include <vector>
#include <string>
using namespace std;


void merge(vector<string> &a, int l1, int r1, int l2, int r2){
    int n1 = r1 - l1 + 1;
    string L[n1];
    for(int i = 0; i < n1; i++){
        L[i] = a[l1 + i];
    }

    int n2 = r2 - l2 + 1;
    string R[n2];
    for(int i = 0; i < n2; i++){
        R[i] = a[l2 + i];
    }


    int i = l1;
    int i1 = 0;
    int i2 = 0;

    while(i1 < n1 && i2 < n2){
        if(L[i1].size() <= R[i2].size()){
            a[i++] = L[i1++];
        }else{
            a[i++] = R[i2++];
        }
    }

    while(i1 < n1){
        a[i++] = L[i1++];
    }
    while(i2 < n2){
        a[i++] = R[i2++];
    }

}

void msort(vector<string> &a, int l, int r){
    if(l < r){
        int mid = l + (r - l)/2;
        msort(a, l, mid);
        msort(a, mid + 1, r);
        merge(a, l, mid, mid + 1, r);
    }
}


int main () {
    int n; cin >> n;

    vector <vector <string> > result(n);

    for(int i = 0; i < n; i++){
        while (true) {
            string x; cin >> x;
            result[i].push_back(x);
            if(cin.peek() == '\n'){
                break;
            }
        }
    }

    for (int i = 0; i < n; i++){
        msort(result[i], 0, result[i].size() - 1);        
    }

    for(int i = 0; i < result.size(); i++){
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    } 
}
