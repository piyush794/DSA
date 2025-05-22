/*Link :https://www.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1
Alternate Positive Negative
Difficulty: EasyAccuracy: 33.86%Submissions: 218K+Points: 2Average Time: 10m
Given an unsorted array arr containing both positive and negative numbers. Your task is to rearrange the array and convert it into an array of alternate positive and negative numbers without changing the relative order.

Note:
- Resulting array should start with a positive integer (0 will also be considered as a positive integer).
- If any of the positive or negative integers are exhausted, then add the remaining integers in the answer as it is by maintaining the relative order.
- The array may or may not have the equal number of positive and negative integers.

Examples:

Input: arr[] = [9, 4, -2, -1, 5, 0, -5, -3, 2]
Output: [9, -2, 4, -1, 5, -5, 0, -3, 2]
Explanation: The positive numbers are [9, 4, 5, 0, 2] and the negative integers are [-2, -1, -5, -3]. Since, we need to start with the positive integer first and then negative integer and so on (by maintaining the relative order as well), hence we will take 9 from the positive set of elements and then -2 after that 4 and then -1 and so on.*/

#include <bits/stdc++.h>
using namespace std ;
class Solution {
  public:
  void rearrange(vector<int>&arr){
      vector<int> neg, pos;
        int n = arr.size();
        // Separating negative and positive numbers into separate vectors.
        for (int i = 0; i < n; i++) {
            if (arr[i] < 0)
                neg.push_back(arr[i]);
            else
                pos.push_back(arr[i]);
        }

        int i = 0, j = 0, k = 0;
        // Merging the negative and positive numbers alternatively.
        while (i < neg.size() && j < pos.size()) {
            arr[k++] = pos[j++];
            arr[k++] = neg[i++];
        }

        // Adding any remaining positive numbers to the array.
        while (j < pos.size()) {
            arr[k++] = pos[j++];
        }

        // Adding any remaining negative numbers to the array.
        while (i < neg.size()) {
            arr[k++] = neg[i++];
        }
  }
  /* Without Extra Space Array 
  void rotate(vector<int> &arr,int start , int end){
        int lastVal = arr[end];
        for (int i = end-1;i>=start;i--){
            arr[i+1] = arr[i];
        }
        arr[start] = lastVal;
    }
    void rearrange(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        int k =0;   // even +ve and -ve for odd index 
        
        while(k<n){
            if ( (k%2==0 && arr[k]>=0 ) ||( k%2!=0 && arr[k]<0)){// valid condition s
             k++;
             continue ;
             
            }
            if (k%2==0 && arr[k]<0){ // even index
                int i =k,j=k; // i is +ve and j is -ve 
                while(i<n && arr[i]<0 )i++;
                if (i>=n)return ;
                rotate(arr,j,i);
                
            }
            else if (k%2 != 0 && arr[k]>=0){ // odd index 
                int i= k,j=k;
                while(j<n && arr[j]>=0)j++;
                if (j>= n)return;
                rotate(arr,i,j);
                
            }
            k++;
        }
    }
    */
};
int main(){
    int t ;
    cin>>t;
    cin.ignore();
    while(t--){
        vector<int>arr;
        string input;


        getline(cin,input);
        stringstream ss;
        int number ;
        while(ss >> number){
            arr.push_back(number);

        }
        Solution ob;
        ob.rearrange(arr);
        for (int e : arr) {
            cout << e << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}