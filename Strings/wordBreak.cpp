/*https://www.geeksforgeeks.org/problems/word-break1352/1
Word Break
Difficulty: MediumAccuracy: 40.86%Submissions: 164K+Points: 4
You are given a string s and a list dictionary[] of words. Your task is to determine whether the string s can be formed by concatenating one or more words from the dictionary[].

Note: From dictionary[], any word can be taken any number of times and in any order.

Examples :

Input: s = "ilike", dictionary[] = ["i", "like", "gfg"]
Output: true
Explanation: s can be breakdown as "i like".
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
  
    // Brute Force Method O(2^n)+O(nlogn)  
    bool solve (string &s , int i ,int n,unordered_set<string> &dict){
        if (i >= n){
            return true ;
        }
        if (dict.find(s.substr(i,n)) != dict.end()){
            return true ;
        }
        for (int l =1 ; l <=n ; l++){
            string temp = s.substr(i ,l );
            if ((dict.find(temp)!= dict.end() ) &&  solve(s,i + l,n ,dict)){
                return true;
            }
        }
        return false;
    }
    bool BrutewordBreak(string &s, vector<string> &dictionary) {
        
        unordered_set<string> dict;
        
        for (string &word  : dictionary ){
            dict.insert(word);
        }
        int n = s.size();
        return solve(s,0,n-1 , dict);
    }
    // Optimal Solution Using Memoization 
    vector<int>dp;
    int n ;
    unordered_set<string>dict;
    bool memo_solve(string s , int idx){
        if (idx == n )return true ;
        if (dp[idx] != -1)return dp[idx];
        if (dict.find(s.substr(idx,n))!= dict.end())return dp[idx] =1 ;
        for (int i = 1 ;i< n-idx ;i++){
            string temp = s.substr(idx ,i );
            if ( dict.find(temp)!= dict.end() && memo_solve(s,i+idx))return dp[idx] =1;
        }
        return dp[idx] =0 ;
    }
    bool tabulation_solve ( string s ,int idx ,int n  ){
        dp.assign(n+1,false);
        dp[0] = true ; //empty string can always be segmented 
        int maxlen   = 0 ;
        for (const string word : dict){
            maxlen = max(maxlen , (int)word.size());
        }
        for (int i = 1 ;i<=n ;i++){
            for (int j = i-1 ; j >= max(0, i - maxlen) ; j--){
                if (dp[j] && dict.find(s.substr(j,i-j)) != dict.end()){
                    dp[i] = 1 ;
                    break;
                }
            }
        }
        return dp[n];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        
        n = s.size();
        for (string &word : wordDict){
            dict.insert(word);
        }
        // dp.resize(n,-1); //dp[i] means if substring s[0..i-1] can be segmented.
        // return solve(s,0);
        return tabulation_solve(s,0,n);
    }
};
int main(){
    int n ; 

    cin >> n;
    while(n--){
        string s;
        cin >> s;
        cin.ignore();
        string input;
        getline(cin ,input);
        stringstream ss(input);
        string word;
        vector<string>dictionary;
        while (ss >> word){
            dictionary.push_back(word);
        }
        Solution obj;
        cout << "Ans is : "<<obj.wordBreak(s,dictionary)<<endl;
    } 
}






