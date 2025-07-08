/*Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-gfg-160/problem/search-pattern0205
Search Pattern (KMP-Algorithm)

Difficulty: HardAccuracy: 45.04%Submissions: 119K+Points: 8
Given two strings, one is a text string txt and the other is a pattern string pat. The task is to print the indexes of all the occurrences of the pattern string in the text string. Use 0-based indexing while returning the indices. 
Note: Return an empty list in case of no occurrences of pattern.

Examples :

Input: txt = "abcab", pat = "ab"
Output: [0, 3]
Explanation: The string "ab" occurs twice in txt, one starts at index 0 and the other at index 3. 
Input: txt = "abesdu", pat = "edu"
Output: []
Explanation: There's no substring "edu" present in txt.

*/
/*Time Complexity: O(n + m), where n is the length of the text and m is the length of the pattern. This is because creating the LPS (Longest Prefix Suffix) array takes O(m) time, and the search through the text takes O(n) time.

Auxiliary Space: O(m), as we need to store the LPS array of size m.*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> calculateLPS(string &pat){
        int n  = pat.size();
        int j =0 ;
        int i =1 ;
        vector<int>lps(n) ;
        lps[0] = 0;
        while(i<n){
            if(pat[j] ==pat[i]){
                lps[i] = j+1;
                i++;
                j++;
            }
            else{
                if (j!=0){
                    j = lps[j-1];
                }
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
    vector<int> search(string& pat, string& text) {
        // code here
        int n = text.size();
        int m = pat.size();
        vector<int>lps = calculateLPS(pat);
        vector<int>ans;
        int i  =0 ;//for text 
        int j = 0 ;//for pattern 
        while(i<n){
            if (text[i]==pat[j]){
                i++;
                j++;
            }
            if (j==m){ //// Found the substring 
                ans.push_back(i-m);  
                j=lps[j-1];
            } 
            else if (i<n && text[i]!=pat[j]){
                if (j!=0){
                    j = lps[j-1];
                    
                }
                else{
                    i++;
                }
            }
        }
        return ans;
    }
};
int main(){
    int n ;
    cin >>n ;
    int i =0;
    while(n--){
        string pat;
        string text ;
        cout<<"Enter text string : ";
        cin >> text ;
        cout<<"Enter pattern substring : ";
        cin >> pat;
        Solution sol ;
        vector<int>ans = sol.search(pat,text);
        
        cout<<"Index where substring "<<i+1<<" are : ";
        for (auto a : ans){
            cout<<a<<" ";
        }
        i++;
        cout<<endl;
    }
}