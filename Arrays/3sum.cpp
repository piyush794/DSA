/*https://www.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1
Triplet Sum in Array
Difficulty: MediumAccuracy: 35.0%Submissions: 323K+Points: 4Average Time: 15m
Given an array arr[] and an integer target, determine if there exists a triplet in the array whose sum equals the given target.

Return true if such a triplet exists, otherwise, return false.

Examples

Input: arr[] = [1, 4, 45, 6, 10, 8], target = 13 
Output: true 
Explanation: The triplet {1, 4, 8} sums up to 13
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool hasTripletSum(vector<int> &arr, int target) {
        /*Brute Force  
        int sum = 0;
        for (int i = 0;i<arr.size();i++){
            for (int j=i+1;j<arr.size();j++){
                for (int k = j+1;k<arr.size();k++){
                    if (arr[i]+arr[j]+arr[j]==target){
                        return true;
                    }
                }
            }
            
        }
        return false;
        */
    /* Better Approach using hash set
        
        for (int i=0;i<arr.size();i++){
            set<int>hashset;
            for (int j = i+1;j<arr.size();j++){
                int sum = arr[i]+arr[j];
                int required = target-sum;
                if (hashset.find(required)!=hashset.end()){
                    return true;
                }
                hashset.insert(arr[j]);
            }
        } 
        return false;
    */ 
    // Optimal Approach Two Pointer Approach
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int i =0 ;
        int j ;
        int k;
        while(i<n){
            
            j=i+1;
            k = arr.size()-1;
            while (j<k){
                int sum = arr[i]+arr[j]+arr[k];
                if (sum==target){
                    return true;
                }
                else if (sum<target){
                    j++;
                }
                else {
                    k--;
                }
                
            }
            i++;
        }
        return false ;  
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int target;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> target;
        cin.ignore(); // Ignore newline character after target input

        Solution solution;
        bool result = solution.hasTripletSum(arr, target);
        cout << (result ? "true" : "false") << "\n";
    }

    return 0;
}
// } Driver Code Ends