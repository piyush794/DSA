#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
    bool binarysearch(vector<int > &arr, int target){
        int n = arr.size();
        int i = 0;
        int high = n-1;
        while(i<=high){
            int mid = (i+high)/2;
            if (arr[mid]==target)return true;
            else if (target>arr[mid])i=mid+1;
            else high = mid-1;
        }
        return false ;
    }
      bool matSearch(vector<vector<int>> &mat, int target) {
          //Naive Approach ////////////////////////////////////////

          for (int i = 0;i<mat.size();i++){
              for (int j=0;j<mat[i].size();j++){
                  if (mat[i][j]==x)return true;
              }
          }

          return false;
          //////////////////////////////////////////////////////////
          // Approach 1: using Binary search on rows
          if (mat.empty() || mat[0].empty()) return false;
          int m = mat.size(); // row size
          int n = mat[0].size() ;// columns size
          for (int i =0;i<m;i++){
              if (mat[i][0]<=target && target<=mat[i][n-1]){
                  if (binarysearch(mat[i], target)) return true;
              }
          }
          return false;
      }
      */
    //   Optimal Solution
    bool matSearch(vector<vector<int>> &mat, int target)
    {
        // This method works only when matrix is orted in strictly increasing order from left to right, top to bottom.
        // GFG   matrix violates that condition. So use this in Leetcode
        if (mat.empty() || mat[0].empty())
            return false;
        int matsize = mat.size() * mat[0].size();

        int n = mat[0].size();
        int low = 0;
        int high = matsize - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2; // mid[mid/2] == row number and mid[mid%n] gives column number here n is number of columns
            int row = mid / n;
            int col = mid % n;
            if (mat[row][col] == target)
                return true;
            else if (target > mat[row][col])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
};

int main()
{
    vector<vector<int>> matrix;
    int target;
    int rows, cols;

    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    cin.ignore(); // To handle newline character after cin >> cols

    cout << "Enter matrix rows, space-separated:\n";
    for (int i = 0; i < rows; i++)
    {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        vector<int> row;
        while (ss >> number)
        {
            row.push_back(number);
        }
        matrix.push_back(row);
    }

    cout << "Enter the Target: ";
    cin >> target;

    Solution obj;
    if (obj.matSearch(matrix, target))
    {
        cout << "ELEMENT IS PRESENT\n";
    }
    else
    {
        cout << "Target is NOT Present\n";
    }

    return 0;
}
