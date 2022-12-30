#include<iostream>
#include <vector>
using namespace std;

class MaxHeap {
    private:
        int size;
        vector<int> vect;
    public:
        void shiftUp(int i);
        void shiftDown(int i);
        void insert(int val);
        int extractMax();
        void print();
        void solve(int i, int data);
        int getIndex(int data);
        MaxHeap() {
            size = 0;
        }
};

void MaxHeap::shiftUp(int i) {
    if (i == 0) return;
    int p = (i - 1) / 2;
    if (vect[i] > vect[p]) {
        swap(vect[i], vect[p]);
        shiftUp(p);
        
    }
    
}

void MaxHeap::shiftDown(int i) {
    if (i < size) {
        int swapId = i;
        int l = (i * 2) + 1;
        int r = (i * 2) + 2;

        if (l < size && vect[l] > vect[swapId]) {
            swapId = l;
        }

        if (r < size && vect[r] > vect[swapId]) {
            swapId = r;
        }

        if (swapId != i) {
            swap(vect[i], vect[swapId]);
            shiftDown(swapId);
        }
    }
}

void MaxHeap::insert(int val) {
    size++;
    if (vect.size() < size) {
        vect.push_back(val);
    }
    vect[size - 1] = val;
    shiftUp(size - 1);
}

int MaxHeap::extractMax() {
    int maxNum = vect[0];
    swap(vect[0], vect[size - 1]);
    size--;
    shiftDown(0);
    return maxNum;
} 

void MaxHeap::print() {
    for (int i = 0; i < size; i++) {
        cout << vect[i] << " ";
    }
}


void MaxHeap::solve(int i, int data) {
    i = i - 1;
    vect[i] = vect[i] + data;
    int num = vect[i];
    shiftUp(i);
    
    int j = getIndex(num);
    cout << j << endl;
}


int MaxHeap::getIndex(int data) {
    for (int i = 0; i < size; i++) {
        if (vect[i] == data) {
            return i + 1;
        }
    }
    return -1;
}

int main() {
    MaxHeap* pq = new MaxHeap();
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        pq->insert(x);
    }

    int q; cin >> q;

    while(q != 0) {
        q--;
        int index; 
        int key;
        cin >> index >> key;
        pq->solve(index, key);
    }
   
//    pq->solve(5, 11);
   pq->print();
}