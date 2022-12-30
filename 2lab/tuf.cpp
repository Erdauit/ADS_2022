#include <iostream> 
using namespace std; 
int main () { 
    int n; 
    cin >> n; 
    int arr[n]; 
    for (int i = 0; i < n ; i++) { 
        cin >> arr[i]; 
    } 
    int a = 0; 
    for (int i = 0; i < n; i++) { 
        if (arr[i] % 10 == 0) { 
            a = a + 1;    
    } 
        arr[i] /= 10; 
    } 
    cout << a << endl; 
     return 0; 
}