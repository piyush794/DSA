/* Link : https://www.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1
Chocolate Distribution Problem
Difficulty: EasyAccuracy: 49.91%Submissions: 250K+Points: 2Average Time: 15m
Given an array arr[] of positive integers, where each value represents the number of chocolates in a packet.
Each packet can have a variable number of chocolates. 
There are m students, the task is to distribute chocolate packets among m students such that -
    (i). Each student gets exactly one packet.
    (ii). The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is minimum and return that minimum possible difference.

Examples:

Input: arr = [3, 4, 1, 9, 56, 7, 9, 12], m = 5
Output: 6
Explanation: The minimum difference between maximum chocolates and minimum chocolates is 9 - 3 = 6 by choosing following m packets :[3, 4, 9, 7, 9].
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
        int n =a.size();
        sort(a.begin(),a.end());
        int diff = INT_MAX;
        for (int  i = 0;i<n-m+1;i++){
            int j = i+m-1;
            if (a[j]-a[i]<diff){
                diff = a[j]-a[i];
            }
            
        }
        return diff;
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

        int m;
        cin >> m;
        cin.ignore();
        Solution ob;
        cout << ob.findMinDiff(arr, m) << endl;
        cout << "~" << endl;
    }
    return 0;
}