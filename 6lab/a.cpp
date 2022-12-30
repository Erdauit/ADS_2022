#include <iostream> 
#include <string>
#include <vector>
using namespace std;

int partition(vector<char> &str, int low, int high)
{
    int pivot = high;
    int i = (low - 1);
  
    for (int j = low; j <= high - 1; j++) {

        if (str[j] < str[pivot]) {
            i++; 
            swap(str[i], str[j]);
        }
    }
    swap(str[i + 1], str[pivot]);
    return (i + 1);
}
  
void quickSort(vector<char> &str, int low, int high)
{
    if (low < high) {

        int pi = partition(str, low, high);
  
        quickSort(str, low, pi - 1);
        quickSort(str, pi + 1, high);
    }
}
  

int main() {
    int n; cin >> n;
    string str; cin >> str;
    vector <char> vowels;
    vector <char> consonants; 
    for (int i = 0; i < str.size(); i++) {
        
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
            vowels.push_back(str[i]);
        } else {
            consonants.push_back(str[i]);
        }
    }

    quickSort(vowels, 0, vowels.size() - 1);
    quickSort(consonants, 0, consonants.size() - 1);

    for (int i = 0; i < vowels.size(); i++) {
        cout << vowels[i];
    }
    for (int i = 0; i < consonants.size(); i++) {
        cout << consonants[i];
    }
}