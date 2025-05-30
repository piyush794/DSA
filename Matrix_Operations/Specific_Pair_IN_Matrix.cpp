/*Link :https://www.naukri.com/code360/problems/find-a-specific-pair-in-the-matrix_1115467?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTabValue=PROBLEM&customSource=studio_nav
Problem statement
You have been given a 2-D matrix ‘MAT’ of size ‘N’ x ‘N’ i.e. N rows and N columns. Your task is to find the maximum value of ‘MAT[a][b]’ - ‘MAT[c][d]’ over all possible indices (0 <= ‘a’, ‘b’, ‘c’, ‘d’ < ‘N’) such that . ‘a’ > ‘c’ and ‘b’ > ‘d’.

For example:
Input:
mat[N][N] = {{ 1, 2, -1, -4, -20 },
            { -8, -3, 4, 2, 1 },
            { 3, 8, 6, 1, 3 },
            { -4, -1, 1, 7, -6 },
            { 0, -4, 10, -5, 1 }};
Output: 18
The maximum value is 18 as mat[4][2]
- mat[1][0] = 18 has maximum difference.

*/
#include <bits/stdc++.h>
using namespace std;
int findMaxValue(vector<vector<int>> &mat, int n)
{
    // BRUTE FORCE SOLUTION
    /*
    int m = mat.size();
    n = mat[0].size();
    int maxVal = INT_MIN ;
    int minVal = INT_MAX;
    int ans  = INT_MIN;
    for(int a=0;a<n;a++){
        for (int b = 0;b<n;b++){
            for (int c = 0;c<n;c++){
                for (int d =0  ;d<n ;d++){
                    // ?a? > ?c and
                    if (a>c && b>d){
                        ans = max(ans,mat[a][b]-mat[c][d]);
                    }
                }
            }

        }
    }
    */

    vector<vector<int>> MaxMat(n, vector<int>(n));
    MaxMat[n - 1][n - 1] = mat[n - 1][n - 1];
    // row fix and column change for last row
    for (int i = n - 2; i >= 0; i--)
    {
        MaxMat[n - 1][i] = max(MaxMat[n - 1][i + 1], mat[n - 1][i]);
    }
    // row change and column fixed for last column
    for (int j = n - 2; j >= 0; j--)
    {
        MaxMat[j][n - 1] = max(MaxMat[j + 1][n - 1], mat[j][n - 1]);
    }
    // now filling rest of columns and rows
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        { // row is one more in MaxMat,,when column is one more in MAxmat , just current mat
            MaxMat[i][j] = max({MaxMat[i + 1][j], MaxMat[i][j + 1], mat[i][j]});
        }
    }

    int ans = INT_MIN;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {

            ans = max(ans, MaxMat[i + 1][j + 1] - mat[i][j]);
        }
    }
    return ans;
}

/*------ Main function --------*/

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
    cout << "MAX VALUE IS :" << findMaxValue(matrix, cols) << endl;
    return 0;
}
