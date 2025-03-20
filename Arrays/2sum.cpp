/* Leetcode :https://leetcode.com/problems/two-sum/submissions/
 *** GFG :  https://www.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1 (Here answer is of this )
Two sum -Pairs with 0 Sum
Difficulty: EasyAccuracy: 31.49%Submissions: 475K+Points: 2Average Time: 20m
Given an integer array arr, return all the unique pairs [arr[i], arr[j]] such that i != j and arr[i] + arr[j] == 0.

Note: The pairs must be returned in sorted order, the solution array should also be sorted, and the answer must not contain any duplicate pairs.

Examples:

Input: arr = [-1, 0, 1, 2, -1, -4]
Output: [[-1, 1]]
Explanation: arr[0] + arr[2] = (-1)+ 1 = 0.
arr[2] + arr[4] = 1 + (-1) = 0.
The distinct pair are [-1,1].*/

//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
  /*// Brute Force Technique 
  vector<vector<int>> getPairs(vector<int>& arr) {
    vector<vector<int>>ans;
    for (int i =0 ;i<arr.size();i++){
        for (int j = i+1;j<arr.size();j++){
            if(arr[i]+arr[j]==0){
                int num1  = arr[i];
                int num2=arr[j];
                if(num1>num2)swap(num1,num2);
                ans.push_back({num1,num2});
            }
        }
    }
    return ans;
  }
*/
  // Two pointer Approach  Most optimal 
    vector<vector<int>> getPairs(vector<int>& arr) {
        set<vector<int>> ans;
        sort(arr.begin(),arr.end());
        
        vector<vector<int>>result;
        int j = arr.size()-1;
        int i =0;
        
        while(i<j){
            
            if(arr[i]+arr[j]==0){
                int num1  = arr[i];
                int num2=arr[j];
                if(num1>num2)swap(num1,num2);
                ans.insert({num1,num2});
                i++;
                j--;
            }
            else if (arr[i]+arr[j]<0){
                i++;
            }
            else j--;
        }
        for(auto i:ans){
            result.push_back(i);
        }
        return result;
    }

/*
    // Approach 2 : Not Optimal 
    vector<vector<int>> getPairs(vector<int>& arr) {
        set<vector<int>> ans;
        unordered_map<int,int>mpp;
        
        for (int i =0 ;i<arr.size();i++){
            int num = arr[i];
            int moreNeeded  = 0-num;
            if(mpp.find(moreNeeded)!=mpp.end()){
                int num1  = arr[i];
                int num2=arr[mpp[moreNeeded]];
                if(num1>num2)swap(num1,num2);
                ans.insert({num1,num2});
                
            }
            mpp[num] = i;
        }
        vector<vector<int>>result;
        for(auto i:ans){
            result.push_back(i);
        }
        return result;
    }
    */
};


//{ Driver Code Starts.
//Back-end complete function Template for C++

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        // char c;cin>>c;
        Solution obj;
        vector<vector<int>> res = obj.getPairs(arr);
        if (res.size() == 0) {
            cout << endl;
        } else
            Matrix::print(res);
        cout << "~" << endl;
    }
}

// } Driver Code Ends