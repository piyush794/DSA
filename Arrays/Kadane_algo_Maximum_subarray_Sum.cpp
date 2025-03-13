
// Link - https://www.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
/*Kadane's Algorithm

Difficulty: Medium
Given an integer array arr[]. You need to find the maximum sum of a subarray.

Examples:

Input: arr[] = [2, 3, -8, 7, -1, 2, 3]
Output: 11
Explanation: The subarray {7, -1, 2, 3} has the largest sum 11.*/



// Initial Template for C++

#include<climits>
#include<sstream>
#include<iostream>
#include<vector>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
    // Brute Force Approach 
    /*
        int maxy = INT_MIN;
        for (int i=0;i<arr.size();i++){
            int sum =0 ;
            for(int j=i ;j<arr.size();j++){
                sum+=arr[j];
                
                maxy= max(maxy,sum);
                
            }
        }
        
       */ 
        // Optimal Approach Using Kadane's Algo
        
    int maxy =INT_MIN;
    int sum =0 ;
    int start =0;
    int end  =0 ;
    for (int i =0 ;i<arr.size();i++){
        if (sum==0)start=i;
        sum +=arr[i];
        if (sum>maxy){
            maxy=sum;
            end=i;
        }
        if(sum<0){
            sum=0;
        }
    }
    while(start<=end){
        cout<<arr[start]<<" ";
        start++;
    }
    
    return maxy;
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout <<"\nMaximum : " <<ob.maxSubarraySum(arr) << endl << "~" << endl;
    }
}
// } Driver Code Ends