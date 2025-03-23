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