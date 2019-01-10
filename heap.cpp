#include<iostream>
#include<string>
#include<cstring>
#include<string>

using namespace std;

class Heap {
private:
    int num[1000];
    int n;
    
    void max_heapify(int i);

public:
    Heap(int *a, int n);
    
    Heap();
    
    void Insert(int a);
    
    int Minimun();
    
    void ExtractMin();
    
    void Union(Heap b);
    
    void print();
};

void Heap::max_heapify(int i) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest;
    if (this->num[l] != -1 && this->num[l] < this->num[i]) largest = l;
    else largest = i;
    if (this->num[r] != -1 && this->num[r] < this->num[largest]) largest = r;
    if (largest != i) {
        swap(this->num[i], this->num[largest]);
        max_heapify(largest);
    }
}

Heap::Heap(int *a, int n) {
    memset(this->num, -1, sizeof(this->num));
    this->n = n;
    for (int i = 0; i < n; i++) this->num[i] = a[i];
    for (int i = n / 2; i >= 0; i--) max_heapify(i);
}

Heap::Heap() {
    memset(this->num, -1, sizeof(this->num));
    this->n = 0;
}


void Heap::Insert(int a) {
    this->num[this->n]=a;
    this->n++;
    for(int i=this->n-1;i>=0;i=(i-1)/2){
        if(this->num[i]<this->num[(i-1)/2]) swap(this->num[i],this->num[(i-1)/2]);
        else break;
    }
}

int Heap::Minimun() {
    return this->num[0];
}

void Heap::ExtractMin() {
    this->num[0]=this->num[this->n-1];
    this->n--;
    max_heapify(0);
}

void Heap::Union(Heap b) {
    for(int i=0;i<b.n;i++){
        this->num[this->n++]=b.num[i];
    }
    for(int i=n/2;i>=0;i--) max_heapify(i);
}

void Heap::print() {
    for(int i=0;i<this->n;i++) cout<<this->num[i]<<" ";
}
