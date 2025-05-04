/*Link : https://www.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1
Trapping Rain Water
Difficulty: HardAccuracy: 33.14%Submissions: 469K+Points: 8Average Time: 20m
Given an array arr[] with non-negative integers representing the height of blocks. 
If the width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 

Examples:

Input: arr[] = [3, 0, 1, 0, 4, 0 2]
Output: 10
Explanation: Total water trapped = 0 + 3 + 2 + 3 + 0 + 2 + 0 = 10 units.
*/
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // Optimal Solution
        int left_max=0,right_max=0,left=0,total=0;
        int right= arr.size()-1;
        while(left<right){
            if(arr[left]<=arr[right]){
                if(left_max>arr[left])
                total+=left_max-arr[left];
                else
                left_max=arr[left];
                left=left+1;
            }
            else
            {
                if(right_max>arr[right])
                total+=right_max-arr[right];
                else
                right_max=arr[right];
                right=right-1;
            }
        }
        return total;
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

