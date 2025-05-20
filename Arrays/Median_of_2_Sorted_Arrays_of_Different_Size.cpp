/* Link : https://www.geeksforgeeks.org/problems/median-of-2-sorted-arrays-of-different-sizes/1
Median of 2 Sorted Arrays of Different Sizes
Difficulty: HardAccuracy: 28.4%Submissions: 131K+Points: 8Average Time: 35m
Given two sorted arrays a[] and b[], find and return the median of the combined array after merging them into a single sorted array.

Examples:

Input: a[] = [-5, 3, 6, 12, 15], b[] = [-12, -10, -6, -3, 4, 10]
Output: 3
Explanation: The merged array is [-12, -10, -6, -5, -3, 3, 4, 6, 10, 12, 15]. So the median of the merged array is 3.
Input: a[] = [2, 3, 5, 8], b[] = [10, 12, 14, 16, 18, 20]
Output: 11
Explanation: The merged array is [2, 3, 5, 8, 10, 12, 14, 16, 18, 20]. So the median of the merged array is (10 + 12) / 2 = 11.*/
#include <bits/stdc++.h> 
using namespace std;
class Solution {
public:
    double medianOf2(vector<int>& a, vector<int>& b) {
        /*
        // Using Merge Function of Merge Sort
        int n = a.size();
        int m = b.size();
        vector<int>temp;
        int i =0;
        int j=0;
        while(i<n && j<m ){
            if(a[i]<b[j]){
                temp.push_back(a[i]);
                i++;
            }
            else {
                temp.push_back(b[j]);
                j++;
            }
        }
        while(i<n){
            temp.push_back(a[i]);
            i++;
            
        }
        while(j<m){
            temp.push_back(b[j]);
            j++;
        }
        
    int sz = temp.size();
    double median;

    if (sz % 2 == 0) {
        median = (temp[sz / 2 - 1] + temp[sz / 2]) / 2.0;  // Use 2.0 to ensure float division
    } else {
        median = temp[sz / 2];
    }
        return median;
    }
    */
    // Optimal Using Binary Search as Valid Symmetry
        int n1 = a.size();
        int n2 = b.size();
        if (n1>n2)return medianOf2(b,a); /// a is always smaller array
        int left = (n1+n2+1)/2;
        int low =0, high =n1;
        
        int n =n1+n2;
        while (low <=high){
            int mid1 = (low+high) /2;
            int mid2 = left-mid1;
            
            int l1 = INT_MIN,l2 = INT_MIN;
            int r1 = INT_MAX , r2  = INT_MAX;
            
            if (mid1<n1)r1 = a[mid1];
            if (mid2<n2) r2 = b[mid2];
            if (mid1-1 >= 0 ) l1 = a[mid1 -1 ];
            if (mid2 -1 >= 0 ) l2 = b[mid2-1];
            if (l1<= r2 && l2<= r1){
                if (n%2 == 1)return max(l1,l2);
                return ((double)(max(l1,l2)+min(r1,r2)))/2.0;
            }
            else if (l1>r2)high = mid1-1;
            else low = mid1+1;
            
            
        }
        return 0 ;
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
        cout<<"The Median of Two Arrays is :"<<ob.medianOf2(a, b);
        
        cout << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends