/*Link : https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1
Median in a row-wise sorted Matrix
Difficulty: HardAccuracy: 55.05%Submissions: 139K+Points: 8
Given a row-wise sorted matrix where the number of rows and columns is always odd, find the median of the matrix.

Examples:

Input: mat = [[1, 3, 5], [2, 6, 9], [3, 6, 9]]
Output: 5
Explanation: Sorting matrix elements gives us {1,2,3,3,5,6,6,9,9}. Hence, 5 is median. 
Input: mat = [[1], [2], [3]]
Output: 2
Explanation: Sorting matrix elements gives us {1,2,3}. Hence, 2 is median
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int upperBound(vector<int>arr,int req,int n){
        int low =0;
        int high= n-1;
        int ans = n;
        while(low<=high){
            int mid = (low +high)/2;
            if (arr[mid]>req){
                ans=mid;
                high = mid-1;
            }
            else{
                low = mid +1;
            }
        }
        return ans;
    }
    int countSmallEqual(vector<vector<int>> &mat,int m ,int n,int mid){
        int count = 0;
        for(int i =0 ;i<m;i++){
            count+=upperBound(mat[i],mid,n);
            
        }
        return count;
    }
    int median(vector<vector<int>> &mat) {
        // Naive Way 
        int m = mat.size();
        int n = mat[0].size();
        /*
        vector<int>arr;
        for (int i = 0;i<m;i++){
            for (int j =0 ;j<n;j++){
                arr.push_back(mat[i][j]);
            }
        }
        sort(arr.begin(),arr.end());
        return arr[(m*n)/2];
        */
        int low =  INT_MAX;
        int high = INT_MIN;
    
        for (int i=0;i<mat.size();i++){
            low = min(low,mat[i][0]);
            high = max(high,mat[i][n-1]);
        }
        int req = (n*m)/2;
        while(low<=high){
            int approx_mid = (low+high)/2;
            int count = countSmallEqual(mat,m,n,approx_mid);
            if (count<=req){
                low = approx_mid+1;
            }
            else {
                high= approx_mid-1;
            }
        }
        return low ;
        
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
    int median = obj.median(matrix);
    cout<<"The median of Matrix is "<<median;

    return 0;
}


