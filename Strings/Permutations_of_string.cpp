/*Link : https://www.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1#expected-approach-generating-only-unique-permutations
Permutations of a String
Difficulty: MediumAccuracy: 34.65%Submissions: 327K+Points: 4
Given a string s, which may contain duplicate characters, your task is to generate and return an array of all unique permutations of the string. You can return your answer in any order.

Examples:

Input: s = "ABC"
Output: ["ABC", "ACB", "BAC", "BCA", "CAB", "CBA"]
Explanation: Given string ABC has 6 unique permutations.
*/
#include<bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
  public:

    // Optimal Approach Getting all the Permutations even duplicate ones 
    vector<string>result;
    unordered_set<string> st;
    int n;
    void solve (string &s , string &temp, vector<bool> & used ){
        if (temp.size() == n ){
            st.insert(temp);
            return ;
        }
        for (int i =0 ;i < n;i++){
            if (used[i]==1)continue;
            
            temp+=s[i];
            used[i] = true;
            //explore
            solve(s,temp,used);
            //BackTrack
            temp.pop_back();
            used[i]= false;
            
        }
    }
    vector<string> findPermutation(string &s) {
        n = s.size();
        vector<bool>used(n,0);
        string temp="";
        solve(s,temp,used);
        for (auto i : st){
            result.push_back(i);
        }
        return result;
    }

    
    /*
    // Using C++ Built-In Function
    vector<string> findPermutation(string &s) {
        
        set<string> ans;
        ans.insert(s);
        next_permutation(s.begin(),s.end());
        
        while(ans.find(s) == ans.end()){
            ans.insert(s);
            next_permutation(s.begin(),s.end());
        }
        vector<string > final;
        for (auto i : ans){
            final.push_back(i);
        }
        return final;
    }
    */
};
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s1;
        cin>> s1;
        Solution obj;
        vector<string>ans = obj.findPermutation(s1);
        for (auto i :ans)
            cout << i << " ";
        cout <<endl<< "~" << endl;
    }
    return 0;
}