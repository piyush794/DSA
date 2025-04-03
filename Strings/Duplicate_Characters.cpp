/* Link :https://www.naukri.com/code360/problems/duplicate-characters_3189116?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTabValue=PROBLEM
Duplicate Characters
Problem statement
You are given a string ‘S’ of length ‘N’. You have to return all the characters in the string that are duplicated and their frequency.

Example:-
N = 5
S = ‘GEEK’

ANSWER:- The answer should be [(‘E’,2)] because ‘E’ is the only character that is duplicated and has frequency 2.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 5
1 <= N <= 10^5 

Time Limit = 1 sec
Sample Input 1 :
2
5
APPLE
6
BANANA
Sample Output 1 :
P 2
A 3
N 2
Explanation for Sample Output 1 :
In the first test case, the character ‘P’ has frequency 2 and is the only duplicate character in the string.
 In the second test case, the character ‘A’ has frequency 3 and the character ‘N’ has frequency 2. 
Sample Input 2 :
1
5
AAAAA
Sample Output 2 :
A 5
*/
#include <bits/stdc++.h>
using namespace std;
vector<pair<char, int>> duplicate_char(string s, int n)
{
    // Hashing Technique 
    unordered_map<char, int> mp;
    vector<pair<char, int>> ans;

    for (int i = 0; i < n; i++)
    {

        mp[s[i]]++;
    }

    for (auto mps : mp)
    {
        if (mps.second > 1)
        {
            ans.push_back(make_pair(mps.first, mps.second));
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{
    string s = "hello world";
    vector<pair<char, int>> result = duplicate_char(s,s.size());

    // Print results
    for (auto p : result)
    {
        cout << "Character: " << p.first << ", Count: " << p.second << endl;
    }

    return 0;
}