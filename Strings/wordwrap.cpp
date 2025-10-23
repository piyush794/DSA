/*
Word Wrap
Link : https://www.geeksforgeeks.org/problems/word-wrap1646/1
Difficulty: HardAccuracy: 29.74%Submissions: 48K+Points: 8Average Time: 20m
Given an array arr[], where arr[i] denotes the number of characters in one word. Let k be the limit on the number of characters that can be put in one line (line width). Put line breaks in the given sequence such that the lines are printed neatly.
Assume that the length of each word is smaller than the line width. When line breaks are inserted there is a possibility that extra spaces are present in each line. The extra spaces include spaces put at the end of every line except the last one. 

You have to minimize the following total cost where total cost = Sum of cost of all lines, where cost of line is = (Number of extra spaces in the line)2.

Examples:

Input: arr[] = [3,2,2,5], k = 6
Output: 10
Explanation: Given a line can have 6 characters,
Line number 1: From word no. 1 to 1
Line number 2: From word no. 2 to 3
Line number 3: From word no. 4 to 4
So total cost = (6-3)2 + (6-2-2-1)2 = 32+12 = 10. 
As in the first line word length = 3 thus extra spaces = 6 - 3 = 3 and in the second line there are two word of length 2 and there already 1 space between two word thus extra spaces = 6 - 2 -2 -1 = 1. 
As mentioned in the problem description there will be no extra spaces in the last line. 
Placing first and second word in first line and third word on second line would take a cost of 02 + 42 = 16 (zero spaces on first line and 6-2 = 4 spaces on second),
 which isn't the minimum possible cost.
 */
class Solution {
  public:
    vector<vector<int>> dp;
    
    int rec(vector<int>&arr, int i, int rem, int k) {
        
        int n = arr.size();
        if (i == n) {
            return 0;  // No penalty for last line
        }
        
        if (dp[i][rem] != -1) {
            return dp[i][rem];
        }
        
        int ans = INT_MAX;
        
        // Calculate total space used if we add current word to this line
        int spacesNeeded = (rem == 0) ? 0 : 1;  // Need 1 space before word if line not empty
        int totalUsed = rem + spacesNeeded + arr[i];
        
        // Option 1: Add current word to current line (if it fits)
        if (totalUsed <= k) {
            int newLen = rem + spacesNeeded + arr[i];
            ans = min(ans, rec(arr, i + 1, newLen, k));
        }
        
        // Option 2: Start new line with current word (only if current line has words)
        if (rem > 0) {
            int remaining = k - rem;
            int cost = remaining * remaining;
            ans = min(ans, cost + rec(arr, i, 0, k));
        }
        
        return dp[i][rem] = ans;
    }
    
    int solveWordWrap(vector<int> arr, int k) {
        int n = arr.size();
        dp.assign(n + 1, vector<int>(k + 1, -1));
        return rec(arr, 0, 0, k);
    }
};
int main(){

}