#include<iostream>
#include <map>
#include <iomanip>

using namespace std;

map <string, double> grades {
    {"A+", 4.00},
    {"A", 3.75},
    {"B+", 3.50},
    {"B", 3.00},
    {"C+", 2.50},
    {"C", 2.00},
    {"D+", 1.50},
    {"D", 1.00},
    {"F", 0}
};

void swap(pair<pair<string, string>, double> arr[], int i, int j) {
    pair<pair<string, string>, double> temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

bool comparator(pair<pair <string, string>, double> a, pair<pair <string, string>, double> b) {
    if (a.second == b.second) {
        if (a.first.first == b.first.first) {
            return a.first.second < b.first.second;
        }
        else
            return a.first.first < b.first.first;
    }
    else
        return a.second < b.second;
}

int partition(pair<pair <string, string>, double> arr[], int l, int r) {
    int pivot = r;
    int i = l - 1;
     
    for (int j = l; j < r; j++) {
        if (comparator(arr[j], arr[pivot])) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, r);
    return i + 1;
}

void quickSort(pair<pair<string, string>, double> arr[], int l, int r) {
    if (l < r) {
        int pi = partition(arr, l, r);
        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, r);
    }
}

void merge(pair<pair<string, string>, double> a[], int l1, int r1, int l2, int r2){
    int n1 = r1 - l1 + 1;
    pair<pair<string, string>, double> L[n1];
    for(int i = 0; i < n1; ++i){
        L[i] = a[l1 + i];
    }

    int n2 = r2 - l2 + 1;
    pair<pair<string, string>, double> R[n2];
    for(int i = 0; i < n2; ++i){
        R[i] = a[l2 + i];
    }

    int i = l1;
    int i1 = 0;
    int i2 = 0;

    while(i1 < n1 && i2 < n2){
        if(comparator(L[i1],R[i2])){
            a[i++] = L[i1++];
        }else {
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

void msort(pair<pair<string, string>, double> a[], int l, int r){
    if(l < r){
        int m = l + (r - l) / 2;
        msort(a, l, m);
        msort(a, m + 1, r);
        merge(a, l, m , m + 1, r);
    }
}

double gpa(pair <string, int> arr[], int size) {
    double sum = 0;
    double credits = 0;
    for (int i = 0; i < size; i++) {
        double g = grades[arr[i].first];
        sum += g * arr[i].second;
        credits += arr[i].second;
    }

    return sum / credits;
    
}


int main() {
    int n; cin >> n;
    pair<pair <string, string>, double> journal[n];
    for (int i = 0; i < n; i++) {
        string name, surname;
        cin >> surname >> name;
        int numD; cin >> numD;
        pair <string, int> arr[numD];
        for (int j = 0; j < numD; j++) {
            cin >> arr[j].first >> arr[j].second;
        }
        double gpaG = gpa(arr, numD);
        journal[i].first.first = surname;
        journal[i].first.second = name;
        journal[i].second = gpaG;
    }
    
    quickSort(journal, 0, n - 1);   

    for (int i = 0; i < n; i++) {
        cout << journal[i].first.first << " " <<  journal[i].first.second << " " << setprecision(3) << fixed << journal[i].second << endl;
    }
    

}
