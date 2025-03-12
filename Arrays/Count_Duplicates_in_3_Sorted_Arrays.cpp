/* Link : https://www.geeksforgeeks.org/problems/common-elements1132/1
Common in 3 Sorted Arrays
Difficulty: EasyAccuracy: 22.16%Submissions: 414K+Points: 2
You are given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
If there are no such elements return an empty array. In this case, the output will be -1.

Note: can you handle the duplicates without using any additional Data Structure?

Examples :

Input: arr1 = [1, 5, 10, 20, 40, 80] , arr2 = [6, 7, 20, 80, 100] , arr3 = [3, 4, 15, 20, 30, 70, 80, 120]
Output: [20, 80]
Explanation: 20 and 80 are the only common elements in arr, brr and crr.*/
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find common elements in three arrays.
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
                               vector<int> &arr3) {
       vector<int>result;
        int n1=arr1.size();
        int n2=arr2.size();
        int n3=arr3.size();
        int i=0,j=0,k=0;
        while(i<n1 && j<n2 && k<n3){
            if(arr1[i]==arr2[j] && arr2[j]==arr3[k]){
                if(result.empty() || result.back() != arr1[i])result.push_back(arr1[i]);
                    i++; j++; k++;
            }
            else if (arr1[i]<arr2[j])i++;
            else if (arr2[j]<arr3[k])j++;
            else k++;
            
        }
        if(result.size()==0)result.push_back(-1);
        return result;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr, crr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        string input3;
        getline(cin, input3);
        stringstream ss3(input3);
        int number3;
        while (ss3 >> number3) {
            crr.push_back(number3);
        }
        Solution ob;
        vector<int> res = ob.commonElements(arr, brr, crr);
        if (res.size() == 0)
            cout << -1;
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl << "~\n";
    }
}
// } Driver Code Ends