/*Link : https://www.geeksforgeeks.org/problems/three-way-partitioning/1

Three way partitioning

Given an array and a range a, b. The task is to partition the array around the range such that the array is divided into three parts.
1) All elements smaller than a come first.
2) All elements in range a to b come next.
3) All elements greater than b appear in the end.
The individual elements of three sets can appear in any order. You are required to return the modified array.

Note: The generated output is true if you modify the given array successfully. Otherwise false.

Geeky Challenge: Solve this problem in O(n) time complexity.

Examples:

Input: arr[] = [1, 2, 3, 3, 4], a = 1, b = 2
Output: true
Explanation: One possible arrangement is: {1, 2, 3, 3, 4}. If you return a valid arrangement, output will be true.
*/
#include <bits/stdc++.h>
using namespace std;



// User function template for C++

class Solution {
  public:
    // Function to partition the array around the range such
    // that array is divided into three parts.
    void threeWayPartition(vector<int>& arr, int a, int b) {
        // Brute Force Approach Apply Sorting 
        //sort(arr.begin(),arr.end());
        
        // Optimal Approach USing 3 pointers 
        int left  =0 ;
        int mid =0 ;
        int right =arr.size()-1;
        
        while (mid <=right){
            if (arr[mid]<a){
                swap(arr[left],arr[mid]);
                mid++;
                left++;
            }
            else if (arr[mid]>=a && arr[mid]<=b){
                mid++;
                // swap(arr[right],arr[mid]);
                }
            else {
                swap(arr[mid],arr[right]);
                right--;
            }
            
        }
        
        
        
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string as;
        getline(cin, as);
        int a = stoi(as);
        string bs;
        getline(cin, bs);
        int b = stoi(bs);
        Solution obj;
        obj.threeWayPartition(arr, a, b);
        int ia = 0;
        int ib = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] >= a) {
                ia = i;
                break;
            }
        }
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > b) {
                ib = i;
                break;
            }
        }
        int f = 0;
        for (int i = 0; i < ia; i++) {
            if (arr[i] >= a) {
                f = 1;
                break;
            }
        }

        for (int i = ia; i < ib; i++) {
            if (arr[i] > b || arr[i] < a) {
                f = 1;
                break;
            }
        }

        for (int i = ib; i < arr.size(); i++) {
            if (arr[i] < b) {
                f = 1;
                break;
            }
        }

        if (f) {
            cout << "false" << endl;
        } else {
            cout << "true" << endl;
        }
        // cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends