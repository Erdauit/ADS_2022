#include <iostream>

using namespace std;

struct date {
    string day;
    string month;
    string year;  //01-12-2000 - size(10)

    void insert(string date) {
        for(int i = 0; i < date.size(); i++) {
            if(i == 0 || i == 1) day += date[i];
            else if(i == 3 || i == 4) month += date[i];
            else if(i > 5) year += date[i];
        }
    }

    bool comparator(date *other) {
        if(this->year > other->year) return true;
        if(this->year == other->year and this->month > other->month) return true;
        if(this->year == other->year and this->month == other->month and this->day > other->day) return true;
        return false;
    }

    void toString() {
        cout << day <<"-"<<month <<"-"<<year <<endl;
    }
};


bool compare(date *first, date *second) {
    if(first->year > second->year) return true;
    if(first->year == second->year) 
        if (first->month > second->month) return true;
    if(first->year == second->year)
        if (first->month == second->month)
            if (first->day > second->day) return true;
    return false;
}

int partition(date* arr, int low, int high) {
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(compare( &arr[high], &arr[j] )) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quicksort(date* arr, int low, int high) {
    if(low < high) {
        int pivot = partition(arr, low, high);

        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}


int main() {
    int n;
    cin >> n;

    date dates[n];

    for(int i = 0; i < n; i++) {
        string date;
        cin >> date;
        dates[i].insert(date);
    }

    quicksort(dates, 0, n - 1);

    for (int i = 0; i < n; i++) {
        dates[i].toString();
    }

}


