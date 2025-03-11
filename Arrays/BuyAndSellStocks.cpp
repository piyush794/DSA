/* Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
121. Best Time to Buy and Sell Stock
Solved
Easy
Topics
Companies
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
*/


#include<bits/stdc++.h>
using namespace std; 
class Solution {
    public:
    
        int maxProfit(vector<int>& prices) {
            int minimal = prices[0];
            int maximal = prices[0];
            int profit =0 ;
            for(int i =1;i<prices.size();i++){
                int cost; 
                cost = prices[i]-minimal ;
                profit= max(profit ,cost); 
                minimal = min(prices[i],minimal);
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
        cout<< "The Maximum profit to achieve from this transaction is "<<obj.maxProfit(a)<<endl;
        return 0 ;
    }
}