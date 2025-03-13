/* Link :https://www.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1 
Subarray with 0 sum
Difficulty: MediumAccuracy: 39.79%Submissions: 290K+Points: 4Average Time: 20m
Given an array of integers, arr[]. Find if there is a subarray (of size at least one) with 0 sum. Return true/false depending upon whether there is a subarray present with 0-sum or not. 

Examples:

Input: arr[] = [4, 2, -3, 1, 6]
Output: true
Explanation: 2, -3, 1 is the subarray with a sum of 0.*/
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Complete this function
    // Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(vector<int>& arr) {
        /*// Brute Force 
        for (int i=0 ;i<arr.size();i++){
            int sum=0 ;
            for(int j=i;j<arr.size();j++){
                sum+=arr[j];
                if(sum==0)return true;
            }
        }
        return false;
        */
        // Most Optimal Prefix Sum Technique
        int sum=0;
        unordered_map<int ,int > mpp;
        mpp[0]++;
        for(int i =0 ;i<arr.size();i++){
            sum+=arr[i];
            if(mpp.find(sum-0)!=mpp.end()){
                return true ; 
                
            }
            mpp[sum]++;
        }
        return false ;
        
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

        Solution obj;
        if (obj.subArrayExists(arr))
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends