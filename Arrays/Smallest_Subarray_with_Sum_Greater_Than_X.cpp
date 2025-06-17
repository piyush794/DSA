/* Link : https://www.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
Smallest subarray with sum greater than x
Difficulty: EasyAccuracy: 37.07%Submissions: 140K+Points: 2Average Time: 20m

Given a number x and an array of integers arr, find the smallest subarray with sum greater than the given value. If such a subarray do not exist return 0 in that case.

Examples:

Input: x = 51, arr[] = [1, 4, 45, 6, 0, 19]
Output: 3
Explanation: Minimum length subarray is [4, 45, 6]
*/


#include <bits/stdc++.h>
using namespace std;



class Solution {
  public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        // Brute Force Method
    /*    int sum;
        int ans= INT_MAX;
        if (accumulate(arr.begin(), arr.end(), 0)<x){
            return 0 ;
        }
        if (arr[0]>x){
            return 1;
        }
        for (int i =0 ;i<arr.size();i++){
            sum = 0;
            for (int j = i;j<arr.size();j++){
                sum+= arr[j];
                if (sum>x){
                    ans= min(ans,j-i+1);  
                    break;
                }
            }
        }
       
        return ans;
    */
    /// Optimal Method using Two Pointer Approach Sliding Window 
        int i =0 ;//Start of window 
        int j = 0; //end of window
        int sum = 0 ;
        int n = arr.size();
        int minLength = INT_MAX;
        while (j<n){
            sum +=arr[j];
            while (sum>x){
                minLength = min(minLength , j-i+1);    
                sum = sum-arr[i];
                i++;        
            }
            j++;
        }
        if (minLength > n) // If no valid subarray is found, return 0
            return 0;
        return minLength ;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        vector<int> arr;
        int x;

        cin >> x;
        cin.ignore(); // Ignore the newline character after x

        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        cout << obj.smallestSubWithSum(x, arr) << "\n~\n";
    }

    return 0;
}
// } Driver Code Ends