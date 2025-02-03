/*
Link https://www.geeksforgeeks.org/problems/find-minimum-and-maximum-element-in-an-array4428/1
Min and Max in Array
Difficulty: Basic
Given an array arr. Your task is to find the minimum and maximum elements in the array.

Note: Return a Pair that contains two elements the first one will be a minimum element and the second will be a maximum.

Examples:

Input: arr[] = [3, 2, 1, 56, 10000, 167]
Output: 1 10000
Explanation: minimum and maximum elements of array are 1 and 10000.*/
//{ Driver Code Starts
// Initial Template for C++

#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<climits>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    pair<int, int> getMinMax(vector<int> arr) {
        // code here
        /* THis Approach Gives TC of O(nlogn)
        sort(arr.begin(),arr.end());
        pair<int,int>pairs;
        pairs.first = arr[0];
        pairs.second = arr[arr.size()-1];
        return  pairs;
    */
        
        // Approach 2 Linear Search TC of this is O(n)
        
        int mini = INT_MAX;
        int max = INT_MIN;
        for (int i =0 ;i<arr.size();i++){
            if(arr[i]<mini){
                mini = arr[i];
            }
            if (arr[i]>max){
                max = arr[i];
            }
        }
        pair<int,int>pairs ;
        pairs.first = mini;
        pairs.second = max;
        return pairs;

    }
};

//{ Driver Code Starts.

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
        Solution ob;
        pair<int, int> pp = ob.getMinMax(arr);
        cout << pp.first << " " << pp.second << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends