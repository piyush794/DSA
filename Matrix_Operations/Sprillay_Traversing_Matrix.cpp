#include<bits/stdc++.h>
using namespace std; 

class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        // code here
        int  m =  mat.size();
        int n  = mat[0].size();
        vector<int> ans;
        
        int top  = 0 ;
        int bottom = m-1;
        int left =0 ;
        int right = n-1;
        while(top<= bottom && left <= right)
        {
        // right
        for (int i = left;i<=right;i++){
            ans.push_back(mat[top][i]);
            
        }
        top++;
        // top to bottom 
        for(int i = top;i<=bottom;i++){
            ans.push_back(mat[i][right]);
            
        }
        right--;
        // bottom right to bottom  left
        if (top<=bottom){
        for(int  i = right;i>=left;i--){
            ans.push_back(mat[bottom][i]);
        }
        bottom--;
        }
        if (left<=right){
        // bottom left to top left 
        for(int i = bottom;i>=top;i--){
            ans.push_back(mat[i][left]);
        }
        left++;
        }
        
            
        }
        return ans;        
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
    vector<int> result = obj.spirallyTraverse(matrix);
    int k = result.size();
    cout<<"The Spiral Travesal in  Matrix are : \n";
    for (int i =0 ;i<k;i++){
            cout<<result[i]<<" ";
    }
    return 0;
}