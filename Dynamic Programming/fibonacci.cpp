/*Fibonacci = 0,1,1,2,3,5,8..
*/
#include<bits/stdc++.h>
using namespace std;
//Memoization Method     store and go from n to base case
int f(int n , vector<int>&dp){
    if (n<=1)return n;
    if (dp[n]!=-1)return dp[n];
    dp[n] =  f(n-1,dp)+f(n-2,dp);
    return dp[n];
}
// Tabulation Method base case to n and no recursion
int tabulation_f(int n , vector<int>&dp){
    /// First add base cases 
    dp[0]=0;
    dp[1]= 1;
    for (int i = 2;i<=n;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}
// Space Optimization Method
int space_optimized_f(int n ){
    int prev = 1;
    int prev2 =0;
    for (int i = 2 ;i<=n;i++){
        int curr_i = prev2+prev;
        prev2 = prev;
        prev = curr_i;

    }
    return prev;
}
int main(){
    int n ;
    cin >> n;
    vector<int>dp(n+1,-1); 
    /// This is a memoization method
    cout<<"BY MEMOIZATION answer is : "<<f(n,dp)<<endl;
    // Tabulation Method Bottom
    cout<<"BY Tabulation answer is : "<<tabulation_f(n,dp)<<endl;

    cout<<"By doing Space Optimization answer is : "<<space_optimized_f(n);
}