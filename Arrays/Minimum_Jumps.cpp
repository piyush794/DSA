//{ Driver Code Starts
/* Link : https://www.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1
Minimum Jumps
Difficulty: Medium
You are given an array arr[] of non-negative numbers.
 Each number tells you the maximum number of steps you can jump forward from that position.

For example:

If arr[i] = 3, you can jump 1 step, 2 steps, or 3 steps forward from position i.
If arr[i] = 0, you cannot jump forward from that position.
Your task is to find the minimum number of jumps needed to move from the first position in the array to the last position.

Note:  Return -1 if you can't reach the end of the array.

Examples : 

Input: arr[] = [1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9]
Output: 3 
Explanation: First jump from 1st element to 2nd element with value 3.
 From here we jump to 5th element with value 9, and from here we will jump to the last.
*/
#include<climits>
#include<sstream>
#include<iostream>
#include<vector>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution {
  public:
    int minJumps(vector<int>& arr) {
    
        // code here
    if(arr[0]==0){
        return -1;
    }
    if(arr.size()==1){
        return -1;
    }
    
        
        int maxReach = arr[0];
        int steps = arr[0];
        int jump=1;
        int i = 1;
        for (i;i<arr.size();i++){
            if(i==arr.size()-1){
                return jump;
            }
            maxReach=max(maxReach,arr[i]+i);
            steps--;
            // if(max)
            if(steps == 0 ){
                jump++;
                if(i>=maxReach)return -1;
                steps = maxReach-i;
            }
            if(steps+i >arr.size()){
                return jump;
            }
        }
        return jump;
    }
    
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends