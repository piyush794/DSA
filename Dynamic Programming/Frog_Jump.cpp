#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int frogJump(int n ,vector<int>& height,vector<int>& dp){
        if (n==0)return 0 ;
        
        if (dp[n] != -1) return dp[n];
        
        int jump1=  frogJump(n-1,height,dp)+abs(height[n]-height[n-1]) ;
        
        int jump2 = INT_MAX;
        
        if (n>1){
            
                jump2 =  frogJump(n-2,height,dp)+abs(height[n]-height[n-2]) ;
            }
        dp[n] = min(jump1,jump2);
        return dp[n];
    }
    int tabulation(int n ,vector<int>& height,vector<int>& dp){
        dp[0]  =0 ;
        dp[1] = dp[0]+abs(height[1]-height[0]);
        for (int i =2 ;i<=n;i++){
            
            int jump1 = dp[i-1]+abs(height[i]-height[i-1]); 
        
            int jump2 = dp[i-2]+abs(height[i]-height[i-2]); 
            dp[i] = min(jump1,jump2);
        }
        return dp[n];
    }
    
    int spaceOptimized(int n ,vector<int>& height){
        if (n == 1) return 0;
        int prev1=  0;
        int prev2 = 0 ; // Cost to reach step -1 (not used)
        for (int i=1;i<=n;i++){
            int jump1  = prev1+abs(height[i]-height[i-1]); 
            
            int jump2 = INT_MAX;
            if (i>1)
                jump2  = prev2+abs(height[i]-height[i-2]); 
            int curr = min(jump1, jump2);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    int minCost(vector<int>& height) {
        // Code here
        int stairlen = height.size();
        // vector<int >dp(stairlen-1,-1);
        // Memoization Method 
        // return frogJump(stairlen-1,height,dp);
        
        /// Tabulation Method 
        // return tabulation(stairlen-1,height,dp);
        
        
        // SpaceOptimization Method
        return spaceOptimized(stairlen-1,height);
    }
};
int main(){
    int T;
    cin>>T;
    cin.ignore();
    while(T--){
        int n ; 
        vector<int>a;
        string input;
        getline(cin,input);
        stringstream ss(input);
        int num;
        while(ss >> num){
            a.push_back(num);

        }
        Solution obj;
        cout<< "The Minimum Cost to Reach the Top is "<<obj.minCost(a)<<endl;
        return 0 ;
    }
}