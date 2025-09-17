/*Link : https://www.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1#using-manachers-algorithm
Longest Palindrome in a String
Difficulty: MediumAccuracy: 23.2%Submissions: 340K+Points: 4
Given a string s, your task is to find the longest palindromic substring within s.

A substring is a contiguous sequence of characters within a string, defined as s[i...j] where 0 ≤ i ≤ j < len(s).

A palindrome is a string that reads the same forward and backward. More formally, s is a palindrome if reverse(s) == s.

Note: If there are multiple palindromic substrings with the same length, return the first occurrence of the longest palindromic substring from left to right.

Examples :

Input: s = “forgeeksskeegfor” 
Output: “geeksskeeg”
Explanation: There are several possible palindromic substrings like “kssk”, “ss”, “eeksskee” etc. But the substring “geeksskeeg” is the longest among all.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    /*
    // Brute Force SOlution Naive method 
    bool palindromeCheck(string &s ,int i ,int j){
        if (i>=j)
            return true;
        if ( s[i]!=s[j] ){
        
            return false;
        }
        return palindromeCheck(s,i+1,j-1);
        
    }
    string longestPalindrome(string &s) {
        
        int maxlen = 0 ;
        int startpoint = -1;
        int n = s.size();
        // this loop creates substrings and checks them 
        for (int i  =0 ;i<n;i++){
            for  (int j = i ;j<n;j++){
                if ( palindromeCheck(s,i,j) ){
                    if (maxlen<j-i+1){
                        maxlen = j-i+1;
                        startpoint = i;
                    }
                
                }
            }
        }
        string ans = s.substr(startpoint,maxlen);
        return ans;
        
    }
    */

    // Optimal Method using memoizationbool palindromeCheck(string &s ,int i ,int j){
    bool palindromeCheck(string &s ,int i ,int j,vector<vector<int>> &dp){
        if (i>=j)
            return 1;
        if (dp[i][j]!=-1)
            return dp[i][j];
        if ( s[i]!=s[j] ){
            return dp[i][j] = 0;
        }
        return dp[i][j] = palindromeCheck(s,i+1,j-1,dp);
        
    }
    string longestPalindrome(string &s) {
        int maxlen  = 0 ;
        int startpoint = -1;
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for (int i=0 ;i<n;i++){
            for (int j = i ;j<n;j++){
                if (palindromeCheck(s,i,j,dp)){
                    if (maxlen<j-i+1){
                        maxlen = j-i+1;
                        startpoint = i ;
                        
                    }
                }
            }
        }
        return s.substr(startpoint,maxlen);
        
    }
};
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s1;
        cin>> s1;
        Solution obj;
        
        string ans = obj.longestPalindrome(s1);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}