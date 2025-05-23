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
        for (int  i=1; i<=size ;i++){
            
            cout<<arr[i]<< " ";

        }
        cout<<endl;
    }
    void deletion(){
        if(size == 0 ){
            cout<< " Nothing to delete ";
            return;

        }
        arr[1]= arr[size];
        size--;

        //taking root node to its correct position
        int i=1;
        while (i<size)
        {
            int leftIndex = 2*i ;
            int rightIndex = 2*i+1;
            if (leftIndex<size&& arr[i]<arr[leftIndex]){
                swap(arr[i],arr[leftIndex]);
                i=leftIndex;

            }
            else if (rightIndex < size && arr[i]<arr[rightIndex]){
                swap(arr[i],arr[rightIndex]);
                i=rightIndex;
            }
            else 
                return ;
        }
        
    }
};

int main(){
    Heap heap;
    
    heap.insert(1223);
    heap.insert(22);
    heap.insert(42);
    heap.insert(56);
    heap.insert(43);
    heap.insert(42);
    heap.insert(34);
    heap.print();
    heap.deletion();
    heap.print();
    
}









