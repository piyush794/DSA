// User function Template for C++
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
