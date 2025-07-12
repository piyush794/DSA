/* Link : https://www.geeksforgeeks.org/problems/interleaved-strings/1#naive-approach-using-recursion-o2mn-time-and-omn-space
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
  bool solve(string& s1, string& s2, string& s3,int m,int n, int N,int i ,int j ,int k){
        
        if (i==m && j==n && k==N)return true ;
        if (k==N)return false ; // other string didnt finished all
        bool result =false  ;
        if (s1[i]==s3[k]){
            result  = solve(s1,s2,s3,m,n,N,i+1,j,k+1);
        }
        if (result == true)return result ;
        if (s2[j]==s3[k]){
            result  = solve(s1,s2,s3,m,n,N,i,j+1,k+1);
        }
        return result ;
  }
    bool isInterleave(string& s1, string& s2, string& s3) {
        /// Recursive Approach Not Optimal 
        int m= s1.size(),n=s2.size(),N = s3.size();
        if (m+n != N)return false ;
        int i =0 ,j=0,k=0;
        
        return solve(s1,s2,s3,m,n,N,i,j,k);
        
        // [Better Approach 1] Using Top-Down Memoization DP - O(m*n) Time and O(n*m) Space
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s1,s2,s3;
        cin >> s3;
        cin >> s2;
        cin >> s1;
        Solution obj;
        
        bool ans = obj.isInterleave(s1,s2,s3);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}