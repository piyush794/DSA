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
Resources :
youtube video link : https://www.youtube.com/watch?v=06QIlUBLTz4
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

    // Better Method using memoizationbool palindromeCheck(string &s ,int i ,int j){
    /*
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
    */
    // Optimal Approach using Manacher's Algorithm 
    string longestPalindrome(string &s){
        
        string st = "@#";
        for (char c : s) {
            st += c;
            st += '#';
        }
        st+="$";
        int n = st.length();
        vector<int>lps(n,0);
        int center = 0;
        int right_end = 0 ;
        for (int i =1 ;i<n-1;i++){
            int mirror = center - (i - center);
            if (i<right_end){
                lps[i] = min(lps[mirror], right_end - i);
            }
            while (st[i + lps[i] + 1] == st[i - lps[i] - 1]){
                lps[i]++;
            }
            if (i + lps[i] > right_end){
                center = i ;
                right_end = i+lps[i];
            }
        }
       
        int max_idx = max_element(lps.begin(),lps.end()) - lps.begin();
        int maxlen = lps[max_idx];
        int start = ( max_idx-maxlen-1)/2;
        return s.substr(start,maxlen);
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