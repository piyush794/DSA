
#include <climits>
#include <sstream>
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    /*
  int minimizeHeight(vector<int>& arr, int k, int index) {
      if (index == arr.size()) {  // Base case: all towers processed
          int maxH = INT_MIN, minH = INT_MAX;
          for (int h : arr) {
              maxH = max(maxH, h);
              minH = min(minH, h);
          }
          return maxH - minH;
      }

      // Try increasing the current tower by K
      arr[index] += k;
      int increase = minimizeHeight(arr, k, index + 1);
      arr[index] -= k;  // Backtrack

      // Try decreasing the current tower by K (only if non-negative)
      arr[index] -= k;
      int decrease = INT_MAX;
      if (arr[index] >= 0) {
          decrease = minimizeHeight(arr, k, index + 1);
      }
      arr[index] += k;  // Backtrack

      // Return the minimum difference found
      return min(increase, decrease);
  }
      */
    int getMinDiff(vector<int> &arr, int k)
    {

        // Approach 1 Brute Force
        // return minimizeHeight(arr,k,0);

        // Optimal Approach
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int ans = arr[n - 1] - arr[0];
        int smallest = arr[0] + k;
        int largest = arr[n - 1] - k;
        int maxi = 0, mini = 0;
        for (int i = 0; i < n - 1; i++)
        {

            maxi = max(largest, arr[i] + k);
            mini = min(smallest, arr[i + 1] - k);
            if (mini < 0)
            {
                continue;
            }

            ans = min(ans, (maxi - mini));
        }
        return ans;
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
        int n, k;
        cin >> k;
        cin.ignore();
        vector<int> a, b, c, d;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution ob;
        auto ans = ob.getMinDiff(a, k);
        cout << ans << "\n";
        cout << '~' << endl;
    }
    return 0;
}
// } Driver Code Ends