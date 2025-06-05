/*Link : https://www.geeksforgeeks.org/problems/kth-element-in-matrix/1
Kth element in Matrix
Difficulty: MediumAccuracy: 61.42%Submissions: 73K+Points: 4Average Time: 35m
Given a matrix mat[][] of size n*n, where each row and column is sorted in non-decreasing order. Find the kth smallest element in the matrix.

Examples:
Input: n = 4, mat[][] = [[16, 28, 60, 64], [22, 41, 63, 91], [27, 50, 87, 93], [36, 78, 87, 94]], k = 3
Output: 27
Explanation: 27 is the 3rd smallest element.
Input: n = 4, mat[][] = [[10, 20, 30, 40], [15, 25, 35, 45], [24, 29, 37, 48], [32, 33, 39, 50]], k = 7
Output: 30
Explanation: 30 is the 7th smallest element.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int countSmallerEqual(vector<vector<int>> &matrix, int mid){
        int n = matrix.size();
        int count =0;
        int row =0;
        int col = n-1;
        while(row<n && col>=0){
            if (matrix[row][col]<=mid){
                count+=(col+1);
                row++;
            }
            else {
                col--;
            }
        }
        return count;
    }
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        // Brute Force
        /*
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int>arr;
        for(int i = 0;i<m;i++){
            for (int j =0 ;j<n;j++){
                arr.push_back(matrix[i][j]);
            }
        }
        sort(arr.begin(),arr.end());
        return arr[k-1];
        */
        /* Naive Solution 
        priority_queue<int, vector<int>,greater<int>>minHeap;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0;i<m;i++){
            for (int j =0 ;j<n;j++){
                minHeap.push(matrix[i][j]);
            }
        }
        
        for (int i = 0;i<k-1;i++){
            minHeap.pop();
        }
        return minHeap.top();
        */
        // optimal solution USing BINARY SEARCH
        int m = matrix.size();
        int n = matrix[0].size();
        int low  = matrix[0][0] ;
        int high = matrix[m-1][n-1];
        int ans;
        while(low<=high){
            int mid =( low+high)/2;
            int count = countSmallerEqual(matrix,mid);
            if (count<k){
                low = mid+1;
            }
            else{
                ans = mid;
                high = mid-1;
            }
        }
        return ans;
        
    }
};
int main()
{
    vector<vector<int>> matrix;
    int target;
    int rows, cols;
    int k ;
    cout<<"Enter the Kth Element: ";
    cin>>k;
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
    cout << k<<"th smallest VALUE IS :" << obj.kthSmallest(matrix, k) << endl;
    return 0;
}
