/*Link : https://www.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1
Merge Without Extra Space

Given two sorted arrays a[] and b[] of size n and m respectively, the task is to merge them in sorted order without using any extra space. Modify a[] so that it contains the first n elements and modify b[] so that it contains the last m elements.

Examples:

Input: a[] = [2, 4, 7, 10], b[] = [2, 3]
Output:
2 2 3 4
7 10
Explanation: After merging the two non-decreasing arrays, we get, 2 2 3 4 7 10*/

//{ Driver Code Starts
#include <queue>
#include<climits>
#include<sstream>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void mergeArrays(vector<int>& nums1, vector<int>& nums2) {
    
/* /* Naive Approach 
        vector<int >arr3;
        int i=0;
        int j=0;
        while(i<nums1.size()&&j<nums2.size()){
            if(nums1[i]<=nums2[j]){
                arr3.push_back(nums1[i]);
                i++;
            }
            else{
                arr3.push_back(nums2[j]);
                j++;
            }
        }
        while(i<nums1.size()){
            arr3.push_back(nums1[i]);
        }
        while(j<nums2.size()){ arr3.push_back(nums2[j]);}

        for(int i= 0 ;i<arr3.size();i++){
            nums1[i]=arr3[i];
        }

        */

        // Optimal Approach 2 Using two pointers 
        int m = nums1.size();
        int n= nums2.size();
        int i = m-1;
        int j=0;
        while(i>=0&& j<n){
            if(nums1[i]>nums2[j]){
                swap(nums1[i],nums2[j]);
                i--;
                j++;
            }
           else{
            break;
           }
            

        }
        sort(nums1.begin(), nums1.begin() + m);
        sort(nums2.begin(),nums2.end());
        j=0;
        for(int i=m;i<m+n;i++){
            nums1[i]=nums2[j];
            j++;
        }
        
    
/*    // Approach 3 Gap Method
    int n = nums1.size();
    int m = nums2.size();
    int total = n + m;

    int gap = (total / 2) + (total % 2);
    while (gap > 0) {
        int left = 0;
        int right = left + gap;

        while (right < total) {
            if (left < n && right < n) {
                // Both elements are in nums1
                if (nums1[left] > nums1[right]) {
                    swap(nums1[left], nums1[right]);
                }
            } else if (left < n && right >= n) {
                // left is in nums1, right is in nums2
                if (nums1[left] > nums2[right - n]) {
                    swap(nums1[left], nums2[right - n]);
                }
            } else {
                // Both elements are in nums2
                if (nums2[left - n] > nums2[right - n]) {
                    swap(nums2[left - n], nums2[right - n]);
                }
            }

            left++;
            right++;
        }

        if (gap == 1) break;
        gap = (gap / 2) + (gap % 2);
    }*/

}
};

//{ Driver Code Starts.

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Inputting the test cases

    while (t--) {
        vector<int> a, b;

        // Reading the first array as a space-separated line
        string arr1;
        getline(cin >> ws, arr1); // Use ws to ignore any leading whitespace
        stringstream ss1(arr1);
        int num;
        while (ss1 >> num) {
            a.push_back(num);
        }

        // Reading the second array as a space-separated line
        string arr2;
        getline(cin, arr2);
        stringstream ss2(arr2);
        while (ss2 >> num) {
            b.push_back(num);
        }

        Solution ob;
        ob.mergeArrays(a, b);

        // Output the merged result
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < b.size(); i++) {
            cout << b[i] << " ";
        }
        cout << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends