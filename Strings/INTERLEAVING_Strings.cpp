/* Link : https://www.geeksforgeeks.org/problems/interleaved-strings/1#expected-approach-spaceoptimized-dp-on-m-time-and-om-space
Interleaved Strings
Difficulty: MediumAccuracy: 24.33%Submissions: 101K+Points: 4Average Time: 30m
Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.
Interleaving of two strings s1 and s2 is a way to mix their characters to form a new string s3, while maintaining the relative order of characters from s1 and s2. Conditions for interleaving:

Characters from s1 must appear in the same order in s3 as they are in s1.
Characters from s2 must appear in the same order in s3 as they are in s2.
The length of s3 must be equal to the combined length of s1 and s2.
Examples :

Input: s1 = "AAB", s2 = "AAC", s3 = "AAAABC", 
Output: true
Explanation: The string "AAAABC" has all characters of the other two strings and in the same order.
Input: s1 = "AB", s2 = "C", s3 = "ACB", 
Output: true
Explanation: s3 has all characters of s1 and s2 and retains order of characters of s1.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
  bool memo_solve(string& s1, string& s2, string& s3,int m,int n, int N,int i ,int j,vector<vector<int>>&dp){
        
        int k = i+j;
        if (i==m && j==n && k==N)return true ;
         // other string didnt finished all
        if(dp[i][j]!=-1){
            return dp[i][j];
            
        } 
        bool a  = (i<m && s1[i]==s3[k] && memo_solve(s1,s2,s3,m,n,N,i+1,j,dp));
        bool b =  (j<n && s2[j]==s3[k] && memo_solve(s1,s2,s3,m,n,N,i,j+1,dp));
        return dp[i][j] = a || b; 
    }
    bool tabu_solve(string& s1, string& s2, string& s3,vector<vector<bool>>& dp){
        int m= s1.size(),n=s2.size(),N = s3.size();
        
        dp[0][0] = true ;
        // if s1 is empyty then s2 will match with s3 
        for (int i =1;i<=n;i++){
            dp[0][i] = dp[0][i-1]&&(s2[i-1]==s3[i-1]);
        }
        // if s2 is empyty then s1 will match with s3 
        for (int i =1;i<=m;i++){
            dp[i][0] = dp[i-1][0]&&(s1[i-1]==s3[i-1]);
        }
        // filling rest of dp table 
        for (int i =1;i<=m;i++){
            for (int j = 1;j<=n;j++){
                dp[i][j] = (dp[i-1][j]&&s1[i-1]==s3[i+j-1])|| (dp[i][j-1]&&s2[j-1]==s3[i+j-1]);
            }
        }
        return dp[m][n];
    }
    
    /// Optimal  space optimized 
    
    bool optimized(string s1,string s2,string s3){
        int m = s1.size();
        int n = s2.size();
        if (m + n != s3.size()) return false;
        vector<bool>prev(n+1);
        vector<bool>curr(n+1);

        prev[0] = true ;

        for (int j = 1 ; j<=n; j++){
            prev[j] = (s2[j - 1] == s3[j - 1]) && prev[j - 1];

        }

        for (int i =1 ;i<=m;i++){
            
            curr[0] = (s1[i-1]==s3[i-1]) && prev[0];
        
            for (int j =1;j<=n;j++){
                curr[j] =
                    (prev[j] && s1[i - 1] == s3[i + j - 1]) ||
                    (curr[j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
            prev = curr;
        }
        return prev[n];
    }
    bool isInterleave(string& s1, string& s2, string& s3) {
        /// Recursive Approach Not Optimal 
        int m= s1.size(),n=s2.size(),N = s3.size();
        if (m+n != N)return false ;
        int i =0 ,j=0,k=0;
        
        // [Better Approach 1] Using Top-Down Memoization DP - O(m*n) Time and O(n*m) Space
    
        vector<vector<bool>>dp(m+1,vector<bool>(n+1,-1));
        // return memo_solve(s1,s2,s3,m,n,N,i,j,dp);
        return optimized(s1,s2,s3);
    }
};
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s1,s2,s3;
        cin>> s1>>s2>>s3;
        Solution obj;
        
        bool ans = obj.isInterleave(s1,s2,s3);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}