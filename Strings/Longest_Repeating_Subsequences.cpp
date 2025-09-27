/* Link : https://www.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1
Longest Repeating Subsequence
Difficulty: MediumAccuracy: 48.54%Submissions: 142K+Points: 4Average Time: 20m
Given string str, find the length of the longest repeating subsequence such that it can be found twice in the given string.

The two identified subsequences A and B can use the same ith character from string s if and only if that ith character has different indices in A and B. For example, A = "xax" and B = "xax" then the index of the first "x" must be different in the original string for A and B.

Examples :

Input: s = "axxzxy"
Output: 2
Explanation: The given array with indexes looks like
a x x z x y 
0 1 2 3 4 5
The longest subsequence is "xx". It appears twice as explained below.
subsequence A
x x
0 1  <-- index of subsequence A
------
1 2  <-- index of s
subsequence B
x x
0 1  <-- index of subsequence B
------
2 4  <-- index of s
We are able to use character 'x' (at index 2 in s) in both subsequences as it appears on index 1 in subsequence A and index 0 in subsequence B. */

// !! Hint !! : solve as similar to Longest common subsequences just indexes of common element should not be same.
class Solution {
  public:
    // Optimal approach using dp 
    int LongestRepeatingSubsequence(string &s) {
        int n = s.size();
    
        // Code here
        int dp[n+1][n+1];
        for (int i = n;i>=0 ;i-- ){
            for (int j = n ;j>=0 ;j-- ){
                if (i == n || j == n){
                    dp[i][j] = 0 ;
                }
                else {
                    if (s[i] == s[j] && i !=j){
                        dp[i][j] = 1+ dp[i+1][j+1];
                    }
                    else {
                        dp[i][j] = max(dp[i+1][j] , dp[i][j+1]);
                    }
                }
            }
        }
        return dp[0][0];
    }
};
