//{ Driver Code Starts
#include <queue>
#include<climits>
#include<sstream>
#include<iostream>
#include<vector>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    void segregateElements(vector<int>& arr) {
        // Your code goes here
        
        vector<int >pos;
        vector<int >neg;
        for(int i=0;i<arr.size();i++){
            if (arr[i]>=0)pos.push_back(arr[i]);
        
            if(arr[i]<0)neg.push_back(arr[i]);
        }   
        int i=0;
        int j=0;
        while(i<pos.size()){
            arr[j]=pos[i];
            i++;
            j++;
        }
        i=0;
        while (i<neg.size()){
            arr[j]=neg[i];
            i++;
            j++;
        }
        
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        ob.segregateElements(nums);

        for (int x : nums)
            cout << x << " ";
        cout << "\n~\n";
    }
}
// } Driver Code Ends