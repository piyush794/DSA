/* Link :https://www.geeksforgeeks.org/problems/parenthesis-checker2744/1#approach-2-without-using-stack
Parenthesis Checker
Difficulty: EasyAccuracy: 28.56%Submissions: 702K+Points: 2
Given a string s, composed of different combinations of '(' , ')', '{', '}', '[', ']'. Determine whether the Expression is balanced or not.
An expression is balanced if:

Each opening bracket has a corresponding closing bracket of the same type.
Opening brackets must be closed in the correct order.
Examples :

Input: s = "[{()}]"
Output: true
Explanation: All the brackets are well-formed.
#include<bits/stdc++.h>
#include <iostream>
using namespace std;
*/
class Solution {
  public:
    bool isBalanced(string& s) {
        // With Stack 
        /*stack<char> st;
        
        for (int i = 0 ;i< s.length() ; i++){
            if (s[i] == '(' || s[i] == '{' || s[i] == '[' ){
                st.push(s[i]);
            }
            else 
            {if  (st.empty())
                return false;
            if ((s[i] == ')' && st.top() == '(') || (s[i] == '}' && st.top() == '{') || (s[i] == ']' && st.top() == '[')){ 
                st.pop();
            }
            else 
                return false;
            }
        }
        return st.empty();
        */
        // Without Stack
        int top =-1;
        for (int i =0 ;i< s.length();i++){
            if (s[i] == '(' || s[i] == '{' || s[i] == '[' ){
                top++;
                s[top] =s[i];
            }
            else if (s[i] == '}' || s[i] == ']' || s[i]==')'){
                if (top == -1 )return false;
                
                if ((s[i] == ')' && s[top] != '(') || 
                (s[i] == '}' && s[top] != '{') || 
                (s[i] == ']' &&  s[top] != '[')){ 
                    return false ;
                }
                top--;
            }
            
        }
        return top == -1 ;
    }
};
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s1;
        cin>> s1;
        Solution obj;
        bool ans = obj.isBalanced(s1);
        cout<<  ans;
        cout <<endl<< "~" << endl;
    }
    return 0;
}