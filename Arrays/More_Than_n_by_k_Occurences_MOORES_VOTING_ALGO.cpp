/*Link :  https://www.geeksforgeeks.org/problems/count-element-occurences/1
        https://leetcode.com/problems/majority-element/description/

More than n/k Occurrences
Difficulty: EasyAccuracy: 58.35%Submissions: 119K+Points: 2Average Time: 45m
Given an array arr and an element k. The task is to find the count of elements in the array that appear more than n/k times and n is length of arr.

Examples :

Input: arr = [3, 1, 2, 2, 1, 2, 3, 3], k = 4
Output: 2
Explanation: In the given array, 3 and 2 are the only elements that appears more than n/k times.
*/
//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:

    // Function to find all elements in array that appear more than n/k times.
    int countOccurence(vector<int>& arr, int k) {
        // Brute Force 
        int ans=0;
        int count;
        set<int>s;
        for (int i = 0 ;i<arr.size();i++){
            if (s.find(arr[i]) != s.end())
                continue;
            count  = 0;
            for (int j=0;j<arr.size();j++){
                    if (arr[i]==arr[j])count++;
            }
            if (count>arr.size()/k){
                ans++;
                s.insert(arr[i]);
            }
        }
        return ans;
        /* Better Approach Hashing 
        int n = arr.size();
        unordered_map<int,int >mpp;
        for(int i=0;i<n;i++){
            mpp[arr[i]]++;
        }
        int count =0;
        for(auto i : mpp){
            int target = n/k;
            if (i.second>target)count++;
        }
        return count;
        */
    }
    // Not Correct Right now NEED CHANGES!!!!!
    /*Moore's Voting for k 
    int countOccurence(vector<int>& arr, int k) {
        int n= arr.size();
        //1 Create a temp arr size k-1 to store poss cand
          
        vector<Pair>temp;
        for (int i = 0; i < k - 1; i++)
            temp[i] = new Pair(MIN_VALUE,0);

        
       //2 traversing in input arr
        for (int i = 0; i < n; i++) {
            int j;
 
            //if arr[i] already in temp, incerase count
            for (j = 0; j < k - 1; j++) {
                if (temp[j]->e == arr[i]) {
                    temp[j].c += 1;
                    break;
                }
            }
 
             //if arr[i] not in temp, place it first availble position in temp
             //if all postions filled, decrease freq of all by 1.
            if (j == k - 1) {
                int l;
 
                for (l = 0; l < k - 1; l++) {
                    if (temp[l].c == 0) {
                        temp[l].e = arr[i];
                        temp[l].c = 1;
                        break;
                    }
                }
 
                 //if all postions filled, decrease freq of all by 1.
                if (l == k - 1)
                    for (l = 0; l < k - 1; l++)
                        temp[l].c -= 1;
            }
        }
 
        //check if potential candiates actually have freq more than n/k;
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < k - 1; i++) {
 
            int ac = 0;
            for (int j = 0; j < n; j++)
                if (arr[j] == temp[i].e)
                    ac++;
 
            if (ac > n / k)
                ans.add(temp[i].e); // 
        }
        return ans;
    }*/
};



//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.countOccurence(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends