#include <iostream>
#include <map>
#include <vector>
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

int main(){
    map<string,string> m;
    map<string, string>:: iterator it;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        string newName; string oldName;
        cin >> newName; cin >> oldName;

        if (m.empty()) {
            m[newName] = oldName;
        }

        if(!m.empty()){
            for(it = m.begin(); it != m.end(); it++){
                if(newName == it->second){
                    m[it->first] = oldName;
                    m.erase(newName);
                    break;
                }
                else{
                    m[newName] = oldName;
                }
            }
        }
    }
    
    cout << m.size() << endl;
 
    for(it = m.begin(); it != m.end(); it++){
        cout << it->first << " " << it->second << endl;
    }
}