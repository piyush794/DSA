/*Link : https://leetcode.com/problems/climbing-stairs/description/
Climbing Stairs
Difficulty: MediumAccuracy: 21.9%Submissions: 234K+Points: 4
There are n stairs, a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Your task is to count the number of ways, the person can reach the top (order does matter).

Examples:

Input: n = 1
Output: 1
Explanation: There is only one way to climb 1 stair. 4Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 
*/
#include<vector>

#include<iostream>
using namespace std;

class Solution {
  public:
  // Using memoization
  int stairs (int n , vector<int>&dp ){
        if (n==0)return 1 ;
        if (n==1 )return 1;
        if (dp[n]!=-1)return dp[n];
        dp[n] = stairs(n-1,dp)+stairs(n-2,dp);
        return dp[n]; 
    }
    // Tablulation Method 
    int tabulationStairs(int n , vector<int>&dp){
        dp[0] = 1 ;
        dp[1] = 1;
        for (int  i = 2;i<=n;i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    //Using Space Optimization and dynamic Programming 
    int spaceOptiStairs(int n){
        int prev1 = 1; // 2 3
        int prev2  = 1; // 1 2
        for (int i = 2;i<=n;i++ ){
            int curr = prev1+ prev2;
            prev2=prev1;
            prev1 = curr;
        }
        return prev1;
    }
    
    int countWays(int n) {
        // your code here
        vector < int>dp(n+1,-1) ;
        // Using memoization
        // int ans =  stairs(n,dp) ;

        // Tablulation Method 
        // int ans  = tabulationStairs(n,dp);
        
        // Using Space Optimization 
        int ans  = spaceOptiStairs(n);

        return ans; 
    }
};
int main(){
    int n ;
    cout<<"Enter the number of Stairs : ";
    cin >> n;
    Solution obj; 
    int ans = obj.countWays(n);

    cout<<"By doing Space Optimization answer is : "<<ans;
}
