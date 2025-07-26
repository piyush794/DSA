/*Link : https://www.geeksforgeeks.org/problems/decode-the-pattern1138/1
Given an integer n. Return the nth row of the following look-and-say pattern.
1
11
21
1211
111221
Look-and-Say Pattern:

To generate a member of the sequence from the previous member, read off the digits of the previous member, counting the number of digits in groups of the same digit. For example:

1 is read off as "one 1" or 11.                                                 i -------> 1
11 is read off as "two 1s" or 21.                                               i+1 -----> one time 1 ===> 11
21 is read off as "one 2, then one 1" or 1211.                                  i+2 -----> two times 1 ===> 21
1211 is read off as "one 1, one 2, then two 1s" or 111221.                      i+3 -----> one time 2 and one time 1 ===> 1211
111221 is read off as "three 1s, two 2s, then one 1" or 312211.                 i+4 -----> one time 1 and one time 2 and 2 times 1 ===> 111221
Examples:

Input: n = 5
Output: 111221
Explanation: The 5th row of the given pattern will be 111221.

*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    
    string countAndSay(int n) {
        // code here
        
        if (n==1)
            return "1"; 

        string say =  countAndSay(n-1);
        string result = "";
        
        for (int i =0;i<say.size();i++){
            int count =1;
            while (i<say.size()-1 && say[i] == say [i+1]){
                count++;
                i++;
            }
            result+= to_string(count)+say[i];
        }
        return result ;
  }
};
int main() {
    int t;
    cin >> t;
    Solution obj;
    cout<<"CountAndSay for "<< t<<"is : "<<obj.countAndSay(t);
    return 0;
}