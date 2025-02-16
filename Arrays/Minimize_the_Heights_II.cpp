/* Link :https://www.geeksforgeeks.org/problems/minimize-the-heights3351/1
Minimize the Heights II
Difficulty: Medium
Given an array arr[] denoting heights of N towers and a positive integer K.

For each tower, you must perform exactly one of the following operations exactly once.

Increase the height of the tower by K
Decrease the height of the tower by K
Find out the minimum possible difference between the height of the shortest and tallest towers after you have modified each tower.

You can find a slight modification of the problem here.
Note: It is compulsory to increase or decrease the height by K for each tower. After the operation, the resultant array should not contain any negative integers.

Examples :

Input: k = 2, arr[] = {1, 5, 8, 10}
Output: 5
Explanation: The array can be modified as {1+k, 5-k, 8-k, 10-k} = {3, 3, 6, 8}.The difference between the largest and the smallest is 8-3 = 5.
*/
#include <climits>
#include <sstream>
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    /*
  int minimizeHeight(vector<int>& arr, int k, int index) {
      if (index == arr.size()) {  // Base case: all towers processed
          int maxH = INT_MIN, minH = INT_MAX;
          for (int h : arr) {
              maxH = max(maxH, h);
              minH = min(minH, h);
          }
          return maxH - minH;
      }

      // Try increasing the current tower by K
      arr[index] += k;
      int increase = minimizeHeight(arr, k, index + 1);
      arr[index] -= k;  // Backtrack

      // Try decreasing the current tower by K (only if non-negative)
      arr[index] -= k;
      int decrease = INT_MAX;
      if (arr[index] >= 0) {
          decrease = minimizeHeight(arr, k, index + 1);
      }
      arr[index] += k;  // Backtrack

      // Return the minimum difference found
      return min(increase, decrease);
  }
      */
    int getMinDiff(vector<int> &arr, int k)
    {

        // Approach 1 Brute Force
        // return minimizeHeight(arr,k,0);

        // Optimal Approach
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int ans = arr[n - 1] - arr[0];
        int smallest = arr[0] + k;
        int largest = arr[n - 1] - k;
        int maxi = 0, mini = 0;
        for (int i = 0; i < n - 1; i++)
        {

            maxi = max(largest, arr[i] + k);
            mini = min(smallest, arr[i + 1] - k);
            if (mini < 0)
            {
                continue;
            }

            ans = min(ans, (maxi - mini));
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        int n, k;
        cin >> k;
        cin.ignore();
        vector<int> a,b,c,d;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution ob;
        auto ans = ob.getMinDiff(a, k);
        cout << ans << "\n";
        cout << '~' << endl;
    }
    return 0;
}
// } Driver Code Ends


/*Variation of the same question when we can have negative values 
since there allow the appearence of negative value, there is no need to check if the value is greater than 0. 

in the for loop, we seperate the length into two parts: index [0, i -1] paired with + k,
 while index [i, n - 1] paired with - k. and each time we calculate the min and max value, we cross the boundary, which ensures that we won't miss any possible one
  int getMinDiff(vector<int> &arr, int k) {
        // code here
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int ans = arr[n-1]-arr[0];
        int small = arr[0]+k;
        // cout<<small<<" ";
        int large  = arr[arr.size()-1]-k;
        // cout<<"large"<<large;
        int mini,maxi;
        for(int i=0;i<n-1;i++){
            mini=min(small,arr[i+1]-k);
            maxi=max(large,arr[i]+k);
            
            ans=min(ans,maxi-mini);
        }
        return ans;
    }
*/