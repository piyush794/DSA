
/*Link : https://www.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1
Factorials of large numbers
Difficulty: MediumAccuracy: 36.57%Submissions: 163K+Points: 4Average Time: 20m
Given an integer n, find its factorial. Return a list of integers denoting the digits that make up the factorial of n.

Examples:

Input: n = 5
Output: [1, 2, 0]
Explanation: 5! = 1*2*3*4*5 = 120
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> factorial(int n) {
        // code 
        vector<int>ans;
        ans.push_back(1);
        int x =2;
        
        while(x<=n){
            int i = ans.size()-1;
            int carry = 0 ;
            // int 
            while(i>=0){
                int num = x*ans[i]+carry;
                int digit = num%10;
                 carry = num/10;
                ans[i]= digit;
                i--;
            }
            while (carry> 0 ){
                
                ans.insert(ans.begin(),carry%10); // Equivalent to push_front
            
                carry = carry/10;
            }
            x++;
        }
        return ans;
    }
};
int main(){
    int t ;
    cin>>t;
    cin.ignore();
    while(t--){
        int num;
        cin >> num;
        Solution ob;
        vector<int>arr;
        arr = ob.factorial( num);
        for (int e : arr) {
            cout << e << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}