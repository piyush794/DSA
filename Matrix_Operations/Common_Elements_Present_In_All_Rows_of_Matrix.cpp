
#include<bits/stdc++.h>
using namespace std;
vector<int> findCommonElements(vector<vector<int>> &mat)
{
    // ///
    int m = mat.size();
    int n = mat[0].size();
    unordered_map<int,int>mapy;
    vector<int>ans;
    
    for (int i = 0;i<m;i++){
        set<int>s;
        for (int j =0 ;j<n;j++){
            s.insert(mat[i][j]);
        }
        for (auto i: s){
            mapy[i]++;
        }
    }
    for(auto i : mapy){
        if (i.second >=m)
            ans.push_back(i.first) ;
    }
    return ans;

}

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

    vector<int> result = findCommonElements(matrix);
    int m = matrix.size();
    int n = matrix[0].size();
    cout<<"The Duplicates in  Matrix are : \n";
    for (int i =0 ;i<m;i++){
            cout<<result[i]<<" ";
        }

    return 0;
}