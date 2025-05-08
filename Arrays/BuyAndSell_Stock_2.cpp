/*Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
Best Time to Buy and Sell Stock II         ( DO IT AGAIN WITH OPTIMIZATION AND TABULATION METHOD )
Solved                                       ( DO IT WITH GREEDY APPROACH TOO )
Medium
Topics
Companies
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
*/

 /// There is Another Dynamic Programming Approach in that folder
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        
        int maxProfit(vector<int>& arr) {
            /// Greedy Approach 
            int profit  =0 ;
            for (int i=1;i<arr.size();i++){
                if (arr[i]>arr[i-1]){
                    profit+=arr[i]-arr[i-1];
                }
            }
            return profit ;
    
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
        cout<< "The Maximum profit to achieve  is "<<obj.maxProfit(a)<<endl;
        return 0 ;
    }
}