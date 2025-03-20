/* Link : https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
Count Inversions 
Difficulty: Medium
Given an array of integers arr[]. Find the Inversion Count in the array.
Two elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.
If an array is sorted in the reverse order then the inversion count is the maximum. 

Examples:

Input: arr[] = [2, 4, 1, 3, 5]
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    // Optimal Force Approach 
    int merge(vector<int>&arr,int left,int mid,int right){
        int n1 = mid-left+1,n2 = right-mid;
        
        vector<int>temp1(n1),temp2(n2);
        for(int i=0;i<n1;i++){
            temp1[i] = arr[i+left];
        }
        for(int j=0;j<n2;j++){
            temp2[j] = arr[j+mid+1];
        }
        int i=0,j=0,k=left,count=0;
        while(i<n1 && j<n2){
            if(temp1[i]<=temp2[j]){
                arr[k] = temp1[i];
                k++;
                i++;
            }else{
                count+=(n1-i);
                arr[k] = temp2[j];
                k++;
                j++;
            }
        }
        while(i<n1){
            arr[k] = temp1[i];
            i++;
            k++;
        }
        while(j<n2){
            arr[k] = temp2[j];
            j++;
            k++;
        }
        return count;
    }

    int mergesort(vector<int>&arr,int left,int right){
        if(left>=right){
            return 0;
        }
        int mid=left+(right-left)/2;
        int left1 = mergesort(arr,left,mid);
        int right1 = mergesort(arr,mid+1,right);
        
        int mer=merge(arr,left,mid,right);
        // cout<<left1<<" "<<right1<<" "<<mer<<endl;
        return left1+right1+mer;
    }
  public:
  // Brute Force Approach 2
    /*int i;
  int count =0;
  for (i=1;i<arr.size();i++){
      int j =i-1;

      while(j>=0){
          if (arr[j]>arr[i]){
              count ++;
          }
          j--;
      }
  }
  return count;
}*/
    // Brute Force Approach 1
    int count=0;
    int inversionCount(vector<int>arr){
        /*for(int i=0 ;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                if(arr[i]>arr[j]){
                    count++;
                }
            }
        }
        return count;
        */
        // Optimal Approach Through merge  Sort 

    int low =0;
    int high = arr.size()-1;
    return mergesort(arr,low ,high);
    }
    
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends