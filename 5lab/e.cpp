#include <iostream>

using namespace std;

struct Heap {
    int* arr;
    int capacity;
    int length;

    void _add(int val) {
        arr[length] = val;
        length++;
        heap_up(length - 1);
    }

    void heap_up(int i) {
        if(i > 0) {
            int p_pos = (i - 1) / 2;
            if(arr[p_pos] > arr[i]) {
                swap(arr[p_pos], arr[i]);
                heap_up(p_pos);
            }
        }
    }

    void heap_down(int i) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int min_pos = i;
        if(l < length and arr[l] < arr[min_pos]) min_pos = l;
        if(r < length and arr[r] < arr[min_pos]) min_pos = r;
        if(min_pos != i) {
            swap(arr[min_pos], arr[i]);
            heap_down(min_pos);
        }
    }
    
    Heap(int capacity) {
        arr = new int[capacity];
        this->capacity = capacity;
        length = 0;
    }

    void insert(int val, int k) {
        if(length < k) _add(val);
        else if(length == k and arr[0] < val) {
            arr[0] = val;
            heap_down(0);
        }
    }

    long long print(int k) {
        long long sum = 0;
        if(length < k) k = length;
        for(int i = 0; i < k; i++) {
            sum += arr[i];
        }
        return sum;
    }
};


int main() {
    int q, k;
    cin >> q >> k;

    Heap heap(100001);

    while(q--) {
        string s;
        int val;
        cin >> s;
        if(s == "print") cout << heap.print(k) << endl;
        else if(s == "insert") {
            cin >> val;
            heap.insert(val, k);
        }
    }
}