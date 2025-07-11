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
    // Hashing Technique Optimal
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

    /*    // optimal solution for this first count the freaquency of every word then pair it with its char use of two loop here

    int k=255; //we take 255 as we know the word will not be bigger than 255
    vector<int> freq(k);
    for(int i=0;i<n;i++){
        freq[s[i]]++; //it tells the frequency of each character
    }
    vector<pair<char,int>> ans;

    this loop will be only till k
    for(int i=0;i<k;i++){
        if(freq[i]>1){
        ans.push_back({char(i),freq[i]});
        }
    }

    return ans;
    */
    /*brute force Approach
    sort(s.begin(),s.end());
    vector<pair<char, int>> result;
    n=s.size();
    for(int i=0;i<n;){
    int count=1;
    while( s[i]==s[i+1])
    {
        count++;
        i++;
    }
    if(count>1)
    {
        result.push_back(make_pair(s[i], count));
    }
    i++;
    }


    return result;

     }
     */
}
int main()
{
    string s = "hello world";
    vector<pair<char, int>> result = duplicate_char(s, s.size());

    // Print results
    for (auto p : result)
    {
        cout << "Character: " << p.first << ", Count: " << p.second << endl;
    }

    return 0;
}