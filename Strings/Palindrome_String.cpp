/* Link : https://www.geeksforgeeks.org/problems/palindrome-string0817/1
Palindrome String
Difficulty: EasyAccuracy: 51.21%Submissions: 388K+Points: 2
You are given a string s. Your task is to determine if the string is a palindrome. A string is considered a palindrome if it reads the same forwards and backwards.

Examples :

Input: s = "abba"
Output: true
Explanation: "abba" reads the same forwards and backwards, so it is a palindrome.*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    // Function to check if a string is a palindrome.
    bool isPalindrome(string& s) {
        // using brute force 
       /* string ans ="";
        for (int i =s.size()-1;i>=0;i--){
            ans+=s[i];
        }
        if (ans==s){
            return true ;
            
        }
        else {
            return false;
        }*/
        
        // Two Pointer Approach
        int i =0;
        int j=s.size()-1;
        while(i<j){
            if (s[i]==s[j]){
                i++;
                j--;
            }
            else {
                return false;
            }
        }
        return true;
        
    }
};


//{ Driver Code Starts.

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) {
        string s;
        cin >> s; // Read the string

        Solution ob; // Create an instance of Solution
        if (ob.isPalindrome(s)) {
            cout << "true"; // Print true if palindrome
        } else {
            cout << "false"; // Print false if not a palindrome
        }
        cout << "\n~\n"; // Print newline after each result
    }

    return 0;
}

// } Driver Code Ends

