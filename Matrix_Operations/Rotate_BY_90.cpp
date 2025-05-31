/*Link: https://www.geeksforgeeks.org/problems/rotate-by-90-degree0356/1
Rotate by 90 degree
Difficulty: MediumAccuracy: 66.8%Submissions: 63K+Points: 4Average Time: 20m
Given a square mat[][]. The task is to rotate it by 90 degrees in clockwise direction without using any extra space.

Examples:

Input: mat[][] = [[1 2 3], [4 5 6], [7 8 9]]
Output:
7 4 1 
8 5 2
9 6 3
*/
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
void rotate(vector<vector<int> >& mat) {
    // Your code goes here
    
    /*Naive Approach with opitonal int n = mat[0].size();
    int m = mat.size();
    vector<vector<int>>temp(n,vector<int>(m));
    for(int i  =0 ;i<m;i++){
        for (int j = 0;j<n;j++){
            temp[j][n-1-i] = mat[i][j];  // every value of mat[i][j ]  after rotation goes to -> temp[j][n-1]          
        }
    }
    for(int i  =0 ;i<m;i++){
        for (int j = 0;j<n;j++){
            mat[i][j] = temp[i][j];
        }
    }
    */
     // Optimal Approach 1st Transpose the matrix and then reverse all of its rows
     // Your code goes here
    int n = mat[0].size();
    int m = mat.size();
    for(int i  =0 ;i<m-1;i++){
        for (int j = i+1;j<n;j++){
           swap(mat[i][j],mat[j][i]);// its for the transpose 
        }
    }
    for(int i  =0 ;i<m;i++){
        reverse(mat[i].begin(),mat[i].end());
    }
}
};
int main() {
    vector<vector<int>> matrix;
    int target;
    int rows, cols;

    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    cin.ignore(); // To handle newline character after cin >> cols

    cout << "Enter matrix rows, space-separated:\n";
    for (int i = 0; i < rows; i++) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        vector<int> row;
        while (ss >> number) {
            row.push_back(number);
        }
        matrix.push_back(row);
    }

    Solution obj;
    
    obj.rotate(matrix);
    int m = matrix.size();
    int n = matrix[0].size();
    cout<<"The Rotated Matrix in Clockwise Direction is : \n";
    for (int i =0 ;i<m;i++){
            for (int j = 0 ;j<n;j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<"\n";
        }

    return 0;
}
