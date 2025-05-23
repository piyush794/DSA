/*Link : https://www.geeksforgeeks.org/problems/array-subset-of-another-array2317/1
Array Subset
Difficulty: BasicAccuracy: 44.05%Submissions: 429K+Points: 1Average Time: 20m
Given two arrays a[] and b[], your task is to determine whether b[] is a subset of a[].

Examples:

Input: a[] = [11, 7, 1, 13, 21, 3, 7, 3], b[] = [11, 3, 7, 1, 7]
Output: true
Explanation: b[] is a subset of a[]
*/
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b)
    {
        // Brute Force
        /*bool ans;
        for (int i  =0  ;i<b.size();i++){
            for (int j = 0;j<a.size();){
                if (b[i]==a[j]){
                    ans  =true;
                    a.erase(a.begin() + j);
                }

            }
            if (ans ==false){
                return false;
            }
        }
        return true;
    }
    */
        // Optimal
        unordered_map<int, int> a_map;

        for (int i = 0; i < a.size(); i++)
        {
            a_map[a[i]]++;
        }

        for (int i = 0; i < b.size(); i++)
        {
            if (a_map[b[i]] == 0)
            {
                return false;
            }
            else
            {
                a_map[b[i]]--;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        vector<int> a1, a2;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            a1.push_back(number);
        }
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number)
        {
            a2.push_back(number);
        }
        Solution s;
        bool ans = s.isSubset(a1, a2);
        if (ans)
        {
            cout << "true"
                << "\n";
        }
        else
        {
            cout << "false"
                << "\n";
        }
        cout << "~"
            << "\n";
    }
    return 0;
}
// } Driver Code Ends