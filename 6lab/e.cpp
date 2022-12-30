#include <cmath>
#include <iostream>
using namespace std;
  
int partition(int a[], int low, int high){
    int i = low - 1;
    int pivot = high;
    for(int j=low; j<high; j++){
        if(a[j] > a[pivot]){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[pivot]);

    return i+1;
}

void qsort(int a[], int low, int high){
    if(low < high){
        int pivot = partition(a, low, high);
    
        qsort(a, low, pivot - 1);
        qsort(a, pivot+1, high);
    }
}


  
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}


int main () {
    int row; cin >> row; 
    int column; cin >> column;
    int arr[row][column];
    int trans[column][row];

    for (int i = 0; i < row; i++) {
        for (int j = 0 ; j < column; j++){
            cin >> arr[i][j];
            trans[j][i] = arr[i][j];
        }
    }
    for (int i = 0; i < column; i++) {
        qsort(trans[i], 0, row - 1);
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << trans[j][i] << " ";
        }
        cout << endl;
    }



}