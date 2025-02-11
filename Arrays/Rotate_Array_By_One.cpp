/* Link - https://www.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1
Rotate Array by One
Difficulty: Basic
Given an array arr, rotate the array by one position in clockwise direction.

Examples:

Input: arr[] = [1, 2, 3, 4, 5]
Output: [5, 1, 2, 3, 4]
Explanation: If we rotate arr by one position in clockwise 5 come to the front and remaining those are shifted to the end.*/


#include<climits>
#include<sstream>
#include<iostream>
#include<vector>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void rotate(vector<int> &arr) {
        // code here
        int lastvar = arr[arr.size()-1];   
        for (int i =arr.size()-1;i>0;i--){
            arr[i]= arr[i-1];
        }
        arr[0]= lastvar;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        ob.rotate(arr);
        for (long long i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends