/*
Link : https://www.geeksforgeeks.org/problems/check-if-strings-are-rotations-of-each-other-or-not-1587115620/1#alternate-approach-using-builtin-method-on-time-and-on-space
Strings Rotations of Each Other
Difficulty: EasyAccuracy: 43.83%Submissions: 289K+Points: 2Average Time: 15m
You are given two strings of equal lengths, s1 and s2. The task is to check if s2 is a rotated version of the string s1.

Note: The characters in the strings are in lowercase.

Examples :

Input: s1 = "abcd", s2 = "cdab"
Output: true
Explanation: After 2 right rotations, s1 will become equal to s2.
Input: s1 = "aab", s2 = "aba"
Output: true
Explanation: After 1 left rotation, s1 will become equal to s2.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


/*The idea is that when a string is concatenated with itself,
all possible rotations of the string will naturally appear as substrings within this concatenated string.*/
class Solution {
  public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string &s1, string &s2) {
        
        if (s1.length() != s2.length()) return false;
        string temp =s1+s1;
        if (temp.find(s2)!=string::npos)
            return true;
        else 
            return false;

    }

/* Optimal : Using KMP Algorithm*/
    //Function to make LPS array = Longest Proper Prefix array  Idea : is there a suffix that is also a prefix of the substring
    vector<int>computeLPS(string& pattern){
        int n  = pattern.size();
        vector<int>lps(n);
        int j  =0  ;
        lps[0]=0;
        int  i =1;
        while (i<n){
            if (pattern[i]== pattern[j]){
                lps[i] = j+1;
                i++;
                j++;
            }
            else {
                if(j!=0){
                    j = lps[j-1];
                }
                else{
                lps[i] = 0 ;
                i++;
                }
            }
        }
        return lps;
    }
    // Function to check if two strings are rotations of each other or not.
    bool Kmp(string &text ,string &pattern){
        
        int  n = text.size();
        int m = pattern.size();
        vector<int > lps = computeLPS(pattern);      // LPS array = Longest Proper Prefix
    
        int i = 0; // for text
        int j = 0; // for pattern
        
        while(i<n){
            if (pattern[j]== text[i]){
                i++;
                j++;
                
            }
            if (j == m ){
                return true ;
            }
            //Mismatch after j matches 
            else if (i<n && pattern[j] != text[i]){
                
                if (j!=0){
                    j = lps[j-1] ;
                }
                else{
                    i++;
                }
            }
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1;
        string s2;
        cin >> s1 >> s2;
        Solution sol;
        int result = sol.areRotations(s1, s2);
        if (result) {
            cout << "true" << endl;

        } else {
            cout << "false" << endl;
        }
        cout << "~"
            << "\n";
    }
    return 0;
}

// } Driver Code Ends