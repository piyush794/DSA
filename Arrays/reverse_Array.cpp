/*
 Reverse The Array
Easy
Problem statement
Given an array/list 'ARR' of integers and a position M. You have to reverse the array after that position.

Example:

We have an array ARR = {1, 2, 3, 4, 5, 6} and M = 3 , considering 0 
based indexing so the subarray {5, 6} will be reversed and our 
output array will be {1, 2, 3, 4, 6, 5}.

Link to question : <a>https://www.codingninjas.com/studio/problems/reverse-the-array_1262298?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTab=0</a>

*/

#include<iostream>
#include<vector>
using namespace std;
void reverseArray(vector<int>  &arr , int m){
    /* Approach 1
    int brr[arr.size()];
    int index=0;
    for(int i=0 ;i<=m;i++){
        brr[index++]=arr[i];
    }
    for (int i=arr.size()-1;i>m;i--){
        brr[index++]=arr[i];
    }
    for(int i=0;i<arr.size();i++){
        arr[i]=brr[i];
    }  
    */
    
    
    // Approach 2 optimal Two Pointer one 
    int i=m+1;int j=arr.size()-1;
    while(i<j){
        swap(arr[i++],arr[j--]);
    }
}

int main()
{
    int n;
    cout<<"Enter the number of elements you want to add : ";
    cin>>n;
    cout << "Enter the elements you want to add : ";
    vector<int>arr;
    for (int i=0;i<n;i++){
        int element;
        cin>>element;
        arr.push_back(element);
    }
    int m;
    cout<<"Enter the value of m:";
    cin>>m;

    reverseArray(arr,m);
    cout<<"Reversed Array from m is : ";
    for(auto i:arr){
        cout<<i<<" ";
        
    }



    return 0;
}