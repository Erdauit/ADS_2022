#include <iostream>
#include <string>
using namespace std;

int partition(char arr[], int low, int high)
{
    int pivot = arr[high]; 
    int i= (low - 1);
  
    for (int j = low; j <= high - 1; j++) {

        if (arr[j] < pivot) {
            i++; 
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
  
void quickSort(char arr[], int low, int high)
{
    if (low < high) {

        int pi = partition(arr, low, high);
  

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
  
void printArray(char arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n; cin >> n;
    char a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    char target; cin >> target;

    quickSort(a, 0, n - 1);
    int cnt = 0;
    for (int i = 0; i < n; i++){
        if (a[i] > target) {
            cout << a[i];
            cnt++;
            return 0;
        }
    }
    if (cnt == 0) {
        cout << a[0];
    }
}