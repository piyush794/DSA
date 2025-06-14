/*Link : https://leetcode.com/problems/set-matrix-zeroes/submissions/
Set Matrix Zeroes
Difficulty: MediumAccuracy: 52.54%Submissions: 40K+Points: 4
You are given a 2D matrix mat[][] of size n×m. The task is to modify the matrix such that if mat[i][j] is 0, all the elements in the i-th row and j-th column are set to 0 and do it in constant space complexity.

Examples:

Input: mat[][] = [[1, -1, 1],
                [-1, 0, 1],
                [1, -1, 1]]
Output: [[1, 0, 1],
        [0, 0, 0],
        [1, 0, 1]]
Explanation: mat[1][1] = 0, so all elements in row 1 and column 1 are updated to zeroes.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    /*
    void markRow(vector<vector<int>> &mat,int i) {
        int n = mat[0].size();
        for (int col = 0;col<n;col++){
            if (mat[i][col]!=0)
            mat[i][col] = -1000000;
        }

    }
    void markCol(vector<vector<int>> &mat,int j ) {
        int m = mat.size();
        for (int row = 0;row<m;row++){
            if (mat[row][j]!=0)
            mat[row][j] = -1000000;
        }

    }
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // Brute Force Solution
        int m = mat.size();
        vector<pair<int,int>>zeros;
        int n = mat[0].size();
        for (int i =0 ;i<m;i++){
            for(int j = 0 ;j<n;j++){
                if (mat[i][j]==0){
                    zeros.push_back({i,j});
                }
            }
        }
        for (auto &p :zeros){
            int i = p.first;
            int j = p.second;
            markRow(mat,i);
            markCol(mat,j);
        }
        for (int i =0 ;i<m;i++){
            for(int j = 0 ;j<n;j++){
                if (mat[i][j]==-1000000){
                    mat[i][j]=0;
                }
            }
        }

    }
    */
    void setMatrixZeroes(vector<vector<int>> &mat)
    {
        /// Optimal Solution with INPLACE WORKING
        int m = mat.size();
        int n = mat[0].size();
        bool firstRow = false;
        bool firstCol = false;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    if (i == 0)
                        firstRow = true;
                    if (j == 0)
                        firstCol = true;
                    mat[i][0] = 0;
                    mat[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (mat[i][0] == 0 || mat[0][j] == 0)
                {
                    mat[i][j] = 0;
                }
            }
        }
        if (firstRow)
        {
            for (int i = 0; i < n; i++)
            {
                mat[0][i] = 0;
            }
        }

        if (firstCol)
        {
            for (int i = 0; i < m; i++)
            {
                mat[i][0] = 0;
            }
        }
    }
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

        Solution obj;

        obj.setMatrixZeroes(matrix);
        int m = matrix.size();
        int n = matrix[0].size();
        cout << "The New  Matrix  is : \n";
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }

        return 0;
    }
};