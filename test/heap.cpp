#include <iostream>
#include <vector>
using namespace std;

struct maxHeap {
    vector <int> heap;
    int parent(int i) {
        return (i - 1) / 2;
    }
    int left (int i) {
        return i * 2 + 1;
    }
    int right (int i) {
        return i * 2 + 2; 
    }
    void insert(int val) {
        heap.push_back(val);
        int i = heap.size() - 1;
        while(i > 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }
    int extractMax() {
        if (heap.size() == 0) return 0;
        if (heap.size() == 1) {
            int root = heap[0];
            heap.pop_back();
            return root;
        }
        int root = heap[0];
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        heapify(0);
        return root;
    }
    void heapify(int i) {
        int l = left(i);
        int r = right(i);
        int largest = i;
        if (l < heap.size() && heap[l] > heap[i]) {
            largest = l;
        }
        if (r < heap.size() && heap[r] > heap[largest]) {
            largest = r;
        }
        if (largest != i) {
            swap (heap[i], heap[largest]);
            heapify(largest);
        }
    }
};


int main() {
    maxHeap heap;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        heap.insert(x);
    }
}

