/*Edit Distance
Difficulty: HardAccuracy: 35.14%Submissions: 245K+Points: 8
Given two strings s1 and s2. Return the minimum number of operations required to convert s1 to s2.
The possible operations are permitted:

Insert a character at any position of the string.
Remove any character from the string.
Replace any character from the string with any other character.
Examples:

Input: s1 = "geek", s2 = "gesek"
Output: 1
Explanation: One operation is required, inserting 's' between two 'e' in s1.*/
//https://www.geeksforgeeks.org/problems/edit-distance3702/1
#include<bits/stdc++.h>
using namespace std;
#include<iostream>
class Solution {
  public:
    // Brute Force Technique 
    
    int rec(string s1 , string s2  ,int i ,int j, vector<vector<int>> &dp){
        if (i== s1.length() ){
            return s2.length()-j ;
        }
        if (j == s2.length() ){
            return s1.length()-i;
        }
        if (dp[i][j]!= -1){
            return dp[i][j];
        }
        if (s1[i] == s2[j]){
            dp[i][j] = rec(s1,s2,i+1,j+1,dp);
            return dp[i][j] ; 
        }
        int insertop = 1+rec(s1,s2,i,j+1,dp);
        int removeop = 1+rec(s1,s2,i+1 ,j, dp) ;
        int replaceop = 1+rec(s1,s2,i+1,j+1,dp );
        dp[i][j] = min(insertop,min(removeop , replaceop));
        return dp[i][j];
        
    }
    // Optimal DP Technique Using Memoization 
    int editDistance(string& s1, string& s2) {
        // code here
        int n2 = s2.length();
        // return rec(s1,s2,s1.size(),s2.size());
        vector<vector<int>> dp(1004,vector<int>(1004, -1));
        
        return rec(s1,s2,0, 0,dp);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1;
        string s2;
        cin >> s1 >> s2;
        Solution sol;
        int result = sol.editDistance(s1, s2);
        cout << "Minimum operations = "<<  result;
        cout << "\n"<< "~";
    }
    return 0;
}