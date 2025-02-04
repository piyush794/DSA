/* Link - https://www.naukri.com/code360/problems/kth-smallest-and-largest-element-of-array_1115488?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTabValue=PROBLEM&count=25&page=16&search=&sort_entity=order&sort_order=ASC
Kth Smallest and Largest Element of Array
Easy

Problem statement
You are given an array ‘Arr’ consisting of ‘N’ distinct integers and a positive integer ‘K’. Find out Kth smallest and Kth largest element of the array. It is guaranteed that K is not greater than the size of the array.

Example:

Let ‘N’ = 4,  ‘Arr’ be [1, 2, 5, 4] and ‘K’ = 3.  
then the elements of this array in ascending order is [1, 2, 4, 5].  Clearly, the 3rd smallest and largest element of this array is 4 and 2 respectively.*/

// #include<bits/stdc++.h>
#include <queue>
#include<climits>
#include<sstream>
#include<iostream>
#include<vector>
using namespace std;

vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
    

	
	// Approach 1 Sorting 
	/*

	sort(arr.begin(),arr.end());
	vector<int>ans;
	ans.push_back(arr[k-1]); // for kth smallest number 
	ans.push_back(arr[n-k]); // for kth largest number
	return ans;
	*/

	//Approach 2
    vector<int> result(2);

    // Build Min-Heap from the given array.
    priority_queue<int, vector<int>, greater<int>> minHeap(arr.begin(), arr.end());

    // Pop from Min-Heap exactly K-1 times
    priority_queue<int> maxHeap(arr.begin(), arr.end());
	for(int i = 0; i < k-1; i++) 
    {
        minHeap.pop();
		maxHeap.pop();
    }

    // Kth smallest element.
    result[0] = minHeap.top();

    // Build Max-Heap from the given array.
    

    // Pop from Max-Heap exactly K-1 time

    //Kth largest element.
    result[1] = maxHeap.top();

    return result;

    // Approach 3 

}
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int k;
        cout<<"\nEnter k: ";
        cin>>k;
        int n = arr.size();
        vector<int>result= kthSmallLarge(arr,n,k);
        cout << result[0] << " " << result[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}