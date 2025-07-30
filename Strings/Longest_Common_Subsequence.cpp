/*
https://leetcode.com/problems/longest-common-subsequence/description/
Given two strings s1 and s2, return the length of their longest common subsequence (LCS). If there is no common subsequence, return 0.

A subsequence is a sequence that can be derived from the given string by deleting some or no elements without changing the order of the remaining elements. For example, "ABE" is a subsequence of "ABCDE".

Examples:

Input: s1 = "ABCDGH", s2 = "AEDFHR"
Output: 3
Explanation: The longest common subsequence of "ABCDGH" and "AEDFHR" is "ADH", which has a length of 3.
Input: s1 = "ABC", s2 = "AC"
Output: 2
Explanation: The longest common subsequence of "ABC" and "AC" is "AC", which has a length of 2.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int memo_solve(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
    {
        if (i < 0 || j < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i] == s2[j])
        {
            dp[i][j] = 1 + memo_solve(s1, s2, i - 1, j - 1, dp);
        }
        else
        {
            dp[i][j] = max(memo_solve(s1, s2, i - 1, j, dp), memo_solve(s1, s2, i, j - 1, dp));
        }
        return dp[i][j];
    }
    int tabula_solve(string &s1, string &s2, int m, int n, vector<vector<int>> &dp)
    {
        /// m-> s1 , n -> s2
        for (int i = 0; i <= m; i++)
        {
            dp[i][0] = 0;
        }
        for (int j = 0; j <= n; j++)
        {
            dp[0][j] = 0;
        }
        ////Base ended above
        // Bottom Up starts from here
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {

                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }

    int optimized(string s1, string s2)
    {
        int m = s1.size();
        int n = s2.size();
        vector<int> prev(n + 1, 0), curr(n + 1, 0);

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            prev = curr;
        }
        return prev[n];
    }
    int lcs(string &s1, string &s2)
    {
        // code here
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        // return memo_solve(s1,s2,m-1,n-1,dp); // Memoization Top Down Approach
        // return tabula_solve(s1,s2,m,n,dp); // Bottom Up Approach Tabulation
        return optimized(s1, s2);
    }
};
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s1,s2;
        cin>> s1>>s2;
        Solution obj;
        
        int ans = obj.lcs(s1,s2);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}