/*LInk : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/next-permutation5226
Next Permutation
Difficulty: MediumAccuracy: 40.66%Submissions: 209K+Points: 4Average Time: 20m
Given an array of integers arr[] representing a permutation, implement the next permutation that rearranges the numbers into the lexicographically next greater permutation. If no such permutation exists, rearrange the numbers into the lowest possible order (i.e., sorted in ascending order).

Note - A permutation of an array of integers refers to a specific arrangement of its elements in a sequence or linear order.

Examples:

Input: arr = [2, 4, 1, 7, 5, 0]
Output: [2, 4, 5, 0, 1, 7]
Explanation: The next permutation of the given array is {2, 4, 5, 0, 1, 7}.*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /// Recursive Approach Brute Force
    void getPermutation(vector<vector<int>> &res, vector<int> &arr, int idx)
    {
        // base case
        if (idx == arr.size() - 1)
        {
            res.push_back(arr);
            return;
        }
        for (int i = idx; i < arr.size(); i++)
        {
            swap(arr[idx], arr[i]);

            getPermutation(res, arr, idx + 1);
            // backtracking
            swap(arr[idx], arr[i]);
        }
    }

    void nextPermutation(vector<int> &arr)
    {
        // code here Recursion Brute Force
        vector<vector<int>> res;
        int idx = 0;
        getPermutation(res, arr, idx);
        sort(res.begin(), res.end());

        for (int i = 0; i < res.size(); i++)
        {
            if (res[i] == arr)
            {
                if (i < res.size() - 1)
                {
                    arr = res[i + 1];
                }
                else
                {
                    arr = res[0];
                }
                break;
            }
        }

        /* Optimal Approach
        int pivot  = -1;
        int n =arr.size();

        for (int i = n-2;i>=0;i--){
            if (arr[i]<arr[i+1]){
                pivot = i ;
                break;
            }
        }
        if (pivot == -1){
            reverse(arr.begin(),arr.end());
            return ;
        }
        for(int i = n-1;i>pivot ;i--){
            if (arr[i]>arr[pivot]){
                swap(arr[i],arr[pivot]);

                break;
            }

        }
        reverse(arr.begin()+pivot+1 , arr.end());
        */
        // Using C++ Library Function
        // next_permutation (arr.begin(),arr.end());
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
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        Solution ob;
        int n = arr.size();
        ob.nextPermutation(arr);
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends