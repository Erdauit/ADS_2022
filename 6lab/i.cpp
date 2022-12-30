#include <iostream> 
using namespace std;

int partition(string &str, int low, int high)
{
    int pivot = str[high];
    int i = (low - 1);
  
    for (int j = low; j <= high - 1; j++) {

        if (str[j] < pivot) {
            i++; 
            swap(str[i], str[j]);
        }
    }
    swap(str[i + 1], str[high]);
    return (i + 1);
}
  
void quickSort(string &str, int low, int high)
{
    if (low < high) {

        int pi = partition(str, low, high);
  
        quickSort(str, low, pi - 1);
        quickSort(str, pi + 1, high);
    }
}
  

// Driver Code
int main()
{
    string str;
    cin >> str;

    quickSort(str, 0, str.size() - 1);
    cout << str;
    return 0;
}