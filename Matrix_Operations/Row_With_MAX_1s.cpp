/*Link : https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1
Row with max 1s
Difficulty: MediumAccuracy: 33.09%Submissions: 347K+Points: 4
You are given a 2D binary array arr[][] consisting of only 1s and 0s. Each row of the array is sorted in non-decreasing order. Your task is to find and return the index of the first row that contains the maximum number of 1s. If no such row exists, return -1.

Note:

The array follows 0-based indexing.
The number of rows and columns in the array are denoted by n and m respectively.
Examples:

Input: arr[][] = [[0,1,1,1], [0,0,1,1], [1,1,1,1], [0,0,0,0]]
Output: 2
Explanation: Row 2 contains the most number of 1s (4 1s). Hence, the output is 2.
Input: arr[][] = [[0,0], [1,1]]
Output: 1
Explanation: Row 1 contains the most number of 1s (2 1s). Hence, the output is 1.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int upperBound(vector<int>arr,int target){
        int low = 0;
        int n = arr.size();
        int high =n-1; 
        int ans = n;
        while(low<=high){
            int mid = (low+high)/2;
            if (arr[mid]>target){
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return ans;
    }
    int rowWithMax1s(vector<vector<int>> &arr) {
        // Naive Way
        int n  = arr[0].size();
        int m = arr.size();
        int maxOnes = INT_MIN;
        int index  =0 ;
        for(int i = 0 ;i<m;i++){
            int numOnes = 0;
            for (int j = 0 ; j<n;j++){
                if (arr[i][j]==1){
                    numOnes = n-j;
                    break;
                }
            }
            if (numOnes > maxOnes ){
                index= i;
                maxOnes = numOnes;
            }
        }
        
        // Optimal SOlution using Upper Bound 
        // You can use lower_bound or firstOccurence too as we are just finding the index where first occurence of 1 happens
        /*
        
        int index =0;
        int maxone = INT_MIN;
        for (int i =0 ;i<m;i++){
            int tempcount = upperBound(arr[i],0);/// First occurence of 1's index 
            int tempOne = n-tempcount;
            if (tempOne >maxone){
                maxone = tempOne;
                index = i;
            }
            
            
        }
        
        */
        return index;
    }
};