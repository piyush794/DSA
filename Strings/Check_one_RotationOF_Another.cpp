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