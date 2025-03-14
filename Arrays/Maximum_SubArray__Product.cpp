/* Link : https://www.geeksforgeeks.org/problems/maximum-product-subarray3604/1
Maximum Product Subarray
Difficulty: MediumAccuracy: 18.09%Submissions: 432K+Points: 4
Given an array arr[] that contains positive and negative integers (may contain 0 as well). Find the maximum product that we can get in a subarray of arr[].

Note: It is guaranteed that the output fits in a 32-bit integer.

Examples

Input: arr[] = [-2, 6, -3, -10, 0, 2]
Output: 180
Explanation: The subarray with maximum product is {6, -3, -10} with product = 6 * (-3) * (-10) = 180.*/

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        // Brute Force 
        /*
        int realMult=INT_MIN;
        for(int i=0 ;i<arr.size();i++){
            int mult=1;
            for(int j=i;j<arr.size();j++){
                mult=mult*arr[j];
                realMult=max(realMult,mult);
            }
        }
        return realMult;
    */
    // Kadane's Variation Technique
    /*
          int ans = arr[0];
          int minimum = arr[0], maximum = arr[0];
        int n = arr.size();  // Size of the array

        // Iterate through the array starting from the second element
        for (int i = 1; i < n; ++i) {
            // If the current element is negative, swap min and max
            // This ensures the current negative can turn the min into max when multiplied
            if (arr[i] < 0) swap(minimum, maximum);

            // Update the minimum product by considering the current element or extending the subarray
            minimum = min(arr[i], arr[i] * minimum);

            // Update the maximum product similarly
            maximum = max(arr[i], arr[i] * maximum);

            // Update the overall maximum product
            ans = max(ans, maximum);
        }

        // Return the maximum product of any subarray
        return ans;
        */
        // MOST INTIUTIVE UsE THIS we use 0 to divide arrays in different parts and -ve for suffix and prefix 
        int prefix = 1;
        int suffix  = 1;
        int ans = INT_MIN;
        int n= arr.size()-1;
        for(int i=0 ;i<arr.size();i++){
            if(prefix==0)prefix=1;
            if (suffix==0)suffix=1;
            prefix*=arr[i];
            suffix*=arr[n-i];
            ans = max(ans,max(prefix,suffix));
        }
        return ans;
    
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends