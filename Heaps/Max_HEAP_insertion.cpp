#include <iostream>
using namespace std;

class Heap{
    public:
    int arr[100];
    int size ;
    Heap(){
        arr[0]=-1;
        size=0;
    }
    void insert(int val){
        size=size+1;
        int index = size;
        arr[index]= val;
        while(index>1){
            int parent = index/2;
            if(arr[parent] <arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else {
                return;
            }
        }
    
    }
    void print(){
        for (int  i=1; i<size ;i++){
            
            cout<<arr[i]<< " ";

        }
        cout<<endl;
    }
};

int main(){
    Heap heap;
    heap.insert(12);
    heap.insert(1223);
    heap.insert(22);
    heap.insert(42);
    heap.insert(56);
    heap.insert(43);
    heap.insert(42);
    heap.insert(34);
    heap.print();
    
}









