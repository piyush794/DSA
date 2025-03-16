/* Link : https://www.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1
Longest Consecutive Subsequence
Difficulty: MediumAccuracy: 33.0%Submissions: 347K+Points: 4Average Time: 25m
Given an array arr[] of non-negative integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.

Examples:

Input: arr[] = [2, 6, 1, 9, 4, 5, 3]
Output: 6
Explanation: The consecutive numbers here are 1, 2, 3, 4, 5, 6. These 6 numbers form the longest consecutive subsquence.*/
//{ Driver Code Starts
#include <unordered_set>
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Your code here
    int longestConsecutive(vector<int> &arr)
    {

        /*
        // Brute Force Time
        bool linearsearch(vector<int>a ,int n, int num ){
        for(int i = 0;i<n;i++){
            if(a[i]==num)return true;

        }
        return false;
    }

        int n =a.size();
        // Brute Force
        int longest =1;
        int cnt;
        for(int i = 0;i<n;i++){
            cnt=1;
            int x = a[i];

            while(linearsearch(a,n,x+1)==true){
                cnt++;
                x=x+1;
            }
            longest = max(cnt,longest);
        }
        return longest;

        // Better approach
            sort(arr.begin(), arr.end());
            int res=0;
            int cnt=1;

            for(int i=1; i<arr.size(); i++){
                if(arr[i]==arr[i-1]+1){
                    cnt++;

                }else if(arr[i]==arr[i-1]){
                    continue;
                }else{
                    cnt=1;
                }
                res=max(res,cnt);
            }
            */

        // Optimal Approach but with some constraints

        unordered_set<int> s;
        int res = 1;
        s.insert(arr.begin(), arr.end());
        int count = 1;
        for (auto i : s)
        {
            if (s.find(i - 1) == s.end())
            {
                count = 1;
                int x = i;
                while (s.find(x + 1) != s.end())
                {
                    x = x + 1;
                    count++;
                }
            }
            res = max(res, count);
        }

        return res;
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.longestConsecutive(arr);

        cout << res << endl
             << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends