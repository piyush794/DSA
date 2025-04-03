/* Link  :https://www.geeksforgeeks.org/problems/reverse-a-string/1

Reverse a String
Difficulty: BasicAccuracy: 69.49%Submissions: 397K+Points: 1Average Time: 15m
You are given a string s, and your task is to reverse the string.

Examples:

Input: s = "Geeks"
Output: "skeeG"

*/

// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    string reverseString(string& s) {
        // code here
        
        
        // Brute force 
        string ans = "";
        for (int i =s.size()-1;i>=0;i--){
            ans+=s[i];
        }
        return ans;
        /// Two Pointer technique
        // int i=0;
        // int e = s.size()-1;
        // while(i<e){
        //     swap(s[i],s[e]);
        //     i++;
        //     e--;
        // }
        // return s;
        
        // Recursive Approach
        
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.reverseString(s) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends