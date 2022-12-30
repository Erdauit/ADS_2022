#include <cmath>
#include <iostream>
using namespace std;
  
int partition(int arr[], int low, int high)
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
  
void quickSort(int arr[], int low, int high)
{
    if (low < high) {

        int pi = partition(arr, low, high);
  

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
  
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
  
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    quickSort(arr, 0, n - 1);

    int diff = 999999;

    for (int i = 0; i < n - 1; i++) {
       if (arr[i + 1] - arr[i] < diff) diff = abs(arr[i + 1] - arr[i]);
    }

    for (int i = 0; i < n - 1; i++) {
       if (arr[i + 1] - arr[i] == diff) cout << arr[i] <<" "<<arr[i + 1]<<" ";
    }

    return 0;
}