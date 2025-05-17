/*
Link - https://www.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1
Sort 0s, 1s and 2s
Difficulty: Medium
Given an array arr[] containing only 0s, 1s, and 2s. Sort the array in ascending order.

You need to solve this problem without utilizing the built-in sort function.

Examples:

Input: arr[] = [0, 1, 2, 0, 1, 2]
Output: [0, 0, 1, 1, 2, 2]
Explanation: 0s 1s and 2s are segregated into ascending order.
*/
//{ Driver Code Starts
#include <queue>
#include<climits>
#include<sstream>
#include<iostream>
#include<vector>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
/* Brute Force APPROACH quick sort 
int partition(vector<int>& arr, int low, int high) {
  
    // Choose the pivot
    int pivot = arr[high];
  
    // Index of smaller element and indicates 
    // the right position of pivot found so far
    int i = low - 1;

    // Traverse arr[low..high] and move all smaller
    // elements on left side. Elements from low to 
    // i are smaller after every iteration
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    // Move pivot after smaller elements and
    // return its position
    swap(arr[i + 1], arr[high]);  
    return i + 1;
}

// The QuickSort function implementation
void quickSort(vector<int>& arr, int low, int high) {
  
    if (low < high) {
      
        // pi is the partition return index of pivot
        int pi = partition(arr, low, high);

        // Recursion calls for smaller elements
        // and greater or equals elements
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

    void sort012(vector<int>& arr) {
        // Using quick sort 
        int n = arr.size(); 
        quickSort(arr,0 ,n-1);
        
        
    }
    */
    
    /*Appoach 2 By making three counts */
    /*
    void sort012(vector<int> & arr){
        int count0=0, count1=0,count2=0;
        for (int i=0;i<arr.size();i++){
            if(arr[i]==0)count0++;
            
            if(arr[i]==1)count1++;
            if(arr[i]==2)count2++;
        }
        for(int i=0;i<count0;i++){
            arr[i]=0;
        }
        for(int i= count0;i<count0+count1;i++){
            arr[i]=1;
        }
        for(int i= count0+count1;i<count0+count1+count2;i++){
            arr[i]=2;
        }
        */
        
    void sort012(vector<int> & arr){
        int low =0,mid=0,high=arr.size()-1;
        while(mid<=high){
            if(arr[mid]==0){
                swap(arr[low],arr[mid]);
                mid++;
                low++;
            }
            else if(arr[mid]==1){
                mid++;
            }
            else{//arr[mid==2
                swap(arr[mid],arr[high]);
                high--;
            }
        }
    }
    
    
    
    
};





//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends