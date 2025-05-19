/* Link : https://www.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1
Minimum swaps and K together
Difficulty: MediumAccuracy: 26.0%Submissions: 136K+Points: 4
Given an array arr and a number k. One can apply a swap operation on the array any number of times, i.e choose any two index i and j (i < j) and swap arr[i] , arr[j] . Find the minimum number of swaps required to bring all the numbers less than or equal to k together, i.e. make them a contiguous subarray.

Examples :

Input: arr[] = [2, 1, 5, 6, 3], k = 3
Output: 1
Explanation: To bring elements 2, 1, 3 together, swap index 2 with 4 (0-based indexing), i.e. element arr[2] = 5 with arr[4] = 3 such that final array will be- arr[] = [2, 1, 3, 6, 5]
*/
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Final function implementation
class Solution
{
public:
    int minSwap(vector<int> &arr, int k)
    {

        // Optimal Approach Using SLiding Window
        int n = arr.size();
        int nonFav = 0;

        int fav = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] <= k)
                fav++;
        }
        int s = 0;
        while (s < fav)
        {
            if (arr[s] > k)
            {
                nonFav++;
            }
            s++;
        }
        int l = 0;
        int r = fav - 1;
        int res = INT_MAX;

        while (r < n)
        {
            if (nonFav < res)
            {
                res = nonFav;
            }

            r++; // Window one step forward
            if (r < n && arr[r] > k)
                nonFav++;
            if (l < n && arr[l] > k)
                nonFav--;
            l++;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--)
    {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number)
        {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.minSwap(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends