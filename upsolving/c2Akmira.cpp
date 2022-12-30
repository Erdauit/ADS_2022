#include <iostream>
#include <vector>

using namespace std;

struct MaxHeap{
    vector<int> heap;

    int parent(int i){
        return (i - 1)/2;
    }
    int left(int i){
        return 2 * i + 1;
    }
    int right(int i){
        return 2 * i + 2;
    }

    void insert(int val){
        heap.push_back(val);

        int i = heap.size() - 1;
        while(i != 0 && heap[parent(i)] < heap[i]){
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

    void print(){
        for(int i = 0; i < heap.size(); i++) cout << heap[i] << " ";
    }

    int increase(int i, int val){
        heap[i] += val;

        while(i != 0 && heap[parent(i)] < heap[i]){
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
        return i + 1;
    }

    void heapify(int i){
        int l = left(i), r = right(i);
        int smallest = i;

        if (l < heap.size() && heap[l] > heap[i]) smallest = l;
        if (r < heap.size() && heap[r] > heap[smallest]) smallest = r;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapify(smallest);
        }
    }
};

int main(){
    MaxHeap *maxHeap = new MaxHeap();
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        maxHeap->insert(x);
    }
    int m;
    cin >> m;
    while(m--){
        int ind, val;
        cin >> ind >> val;

        cout << maxHeap->increase(ind - 1, val) << endl;
    }

    maxHeap->print();
}