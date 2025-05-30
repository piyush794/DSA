/*Link:https://www.geeksforgeeks.org/problems/sorted-matrix2333/1
Sorted matrix
Difficulty: BasicAccuracy: 63.49%Submissions: 58K+Points: 1
Given an NxN matrix Mat. Sort all elements of the matrix.

Example 1:

Input:
N=4
Mat=[[10,20,30,40],
[15,25,35,45] 
[27,29,37,48] 
[32,33,39,50]]
Output:
10 15 20 25 
27 29 30 32
33 35 37 39
40 45 48 50
Explanation:
Sorting the matrix gives this result.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> mat) {
        // code here
        vector<int>temp;
        int m = mat.size();
        int n = mat[0].size();
        for (int i =0 ;i<m;i++){
            for (int j = 0 ;j<n;j++){
                temp.push_back(mat[i][j]);
            }
        }
        sort(temp.begin(),temp.end());
        int index = 0;
        for (int i =0 ;i<m;i++){
            for (int j = 0 ;j<n;j++){
                mat[i][j] = temp[index];
                index++;
            }
        }
        return mat;
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
    vector<vector<int>> sorted_matrix = obj.sortedMatrix(matrix.size(),matrix);
    int m = sorted_matrix.size();
    int n = sorted_matrix[0].size();
    cout<<"The Sorted Matrix is : \n";
    for (int i =0 ;i<m;i++){
            for (int j = 0 ;j<n;j++){
                cout<<sorted_matrix[i][j]<<" ";
            }
            cout<<"\n";
        }

    return 0;
}
