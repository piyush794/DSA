/*Link :https://www.geeksforgeeks.org/problems/anagram-1587115620/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
Anagram
Difficulty: EasyAccuracy: 44.93%Submissions: 388K+Points: 2Average Time: 20m
Given two strings s1 and s2 consisting of lowercase characters. The task is to check whether two given strings are an anagram of each other or not. An anagram of a string is another string that contains the same characters, only the order of characters can be different. For example, "act" and "tac" are an anagram of each other. Strings s1 and s2 can only contain lowercase alphabets.

Note: You can assume both the strings s1 & s2 are non-empty.

Examples :

Input: s1 = "geeks", s2 = "kseeg"
Output: true
Explanation: Both the string have same characters with same frequency. So, they are anagrams.
*/
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        // using brute force
/*
        if (s2.size()-1!=s1.size()-1)return false;
        
        for (int i =0;i<s1.size();i++){
            if (count(s1.begin(), s1.end(), s1[i])!=count(s2.begin(), s2.end(), s1[i])){
                return false;
            }
        }
        return true;
    */
    // using sorting
    if (s2.size()-1!=s1.size()-1)return false;
        
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        
        for (int i=0;i<s1.size();i++){
            if (s1[i]!=s2[i])return false;
        }
        return true;    
}
/*Optimal Using a Vector Array
// using a vector array 
        
        vector<int > freq(26,0);
        for (auto ch: s1){
            freq[ch-'a']++;
        }
        for (auto ch: s2){
            freq[ch-'a']--;
        }
        for (int i : freq){
            if (i!=0)return false ;
        }
        return true;
*/
    
};


//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.areAnagrams(c, d))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends