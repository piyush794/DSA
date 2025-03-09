/* Link : https://www.geeksforgeeks.org/problems/overlapping-intervals--170633/1
 Overlapping Intervals
Difficulty: MediumAccuracy: 57.41%Submissions: 95K+Points: 4
Given an array of Intervals arr[][], where arr[i] = [starti, endi]. The task is to merge all of the overlapping Intervals.

Examples:

Input: arr[][] = [[1,3],[2,4],[6,8],[9,10]]
Output: [[1,4], [6,8], [9,10]]
Explanation: In the given intervals we have only two overlapping intervals here, [1,3] and [2,4] which on merging will become [1,4]. Therefore we will return [[1,4], [6,8], [9,10]].*/




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
     /*    
    /// Approch 1 : Not optimal 
    sort(arr.begin(),arr.end());
    int n=arr.size();
     for (int i = 0; i < n; i++) { // select an interval:
        int start = arr[i][0];
        int end = arr[i][1];

        //Skip all the merged intervals:
        if (!ans.empty() && end <= ans.back()[1]) {
            continue;
        }

        //check the rest of the intervals:
        for (int j = i + 1; j < n; j++) {
            if (arr[j][0] <= end) {
                end = max(end, arr[j][1]);
            }
            else {
                break;
            }
        }
        ans.push_back({start, end});}*/
     
    // Approac 2 : Optimal     
        sort(arr.begin(),arr.end());
        	vector<vector<int>>ans ;
	
	int n=arr.size();
	
	for(int i=0;i<n;i++){
		if(ans.empty() || ans.back()[1]<arr[i][0]){
			ans.push_back(arr[i]);
		}
		else {
			ans.back()[1] = max(arr[i][1],ans.back()[1]);

		}

	}
	return ans;
    }

};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        Solution obj;
        vector<vector<int>> ans = obj.mergeOverlap(arr);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends