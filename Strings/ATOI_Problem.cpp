/*Link: https://www.geeksforgeeks.org/problems/implement-atoi/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
Implement Atoi
Difficulty: MediumAccuracy: 32.58%Submissions: 259K+Points: 4Average Time: 15m
Given a string s, the objective is to convert it into integer format without utilizing any built-in functions. Refer the below steps to know about atoi() function.

Cases for atoi() conversion:

Skip any leading whitespaces.
Check for a sign (‘+’ or ‘-‘), default to positive if no sign is present.
Read the integer by ignoring leading zeros until a non-digit character is encountered or end of the string is reached. If no digits are present, return 0.
If the integer is greater than 231 – 1, then return 231 – 1 and if the integer is smaller than -231, then return -231.
Examples:

Input: s = "-123"
Output: -123
Explanation: It is possible to convert -123 into an integer so we returned in the form of an integer
*/
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int myAtoi(char *s) {
           int i = 0  , sign = 1; long long ans =0;
        // whitespaces
        while(s[i]==' ') i++;
        
        // checking sign
        if(s[i]=='-'){
            sign = -1 ; 
            i++;
        }
        
        // check for starting 0
        while(s[i]=='0') i++;
        
        // converting string to int
        while(s[i]>='0'&&s[i]<='9'){
            int d = s[i] - '0';
            ans = ans *10+d;
            i++;
        }
        
        // handling limit of the answer
        if(ans*sign>INT_MAX) return INT_MAX*sign;
        if(ans*sign<INT_MIN) return INT_MIN*sign;
        
        return (int)ans*sign;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[20];
        cin >> s;
        Solution ob;
        int ans = ob.myAtoi(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends