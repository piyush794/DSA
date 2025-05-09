/*Link :https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/rotate-array-by-n-elements-1587115621
Rotate Array
Difficulty: MediumAccuracy: 37.06%Submissions: 496K+Points: 4Average Time: 20m
Given an array arr[]. Rotate the array to the left (counter-clockwise direction) by d steps, where d is a positive integer. Do the mentioned change in the array in place.

Note: Consider the array as circular.

Examples :

Input: arr[] = [1, 2, 3, 4, 5], d = 2
Output: [3, 4, 5, 1, 2]
Explanation: when rotated by 2 elements, it becomes 3 4 5 1 2.*/
#include <bits/stdc++.h>
using namespace std;

// Learn This Technique Too
//  [Expected Approach 1] Using Juggling Algorithm - O(n) Time and O(1) Space

class Solution
{
public:
    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int> &arr, int d)
    {
        // Naive Approach
        /*
        int n = arr.size();
        for (int i=0 ;i<d;i++){
            int  first  = arr[0];
            for(int j = 0 ;j<arr.size();j++){
                arr[j]=arr[j+1];
            }

            arr[n-1] = first ;
        }
        */

        // using Temporary Array
        int n = arr.size();
        vector<int> temp(n);
        d %= n;
        if (d == 0)
            return;
        for (int i = 0; i < d; i++)
        {
            temp.push_back(arr[i]);
        }
        int i;
        for (i = 0; i < n - d; i++)
        {
            arr[i] = arr[d + i];
        }

        for (int j = 0; j < d; j++)
        {
            arr[i++] = temp[j];
        }

        //

        // Using Rotational Algo

        /*  int n = arr.size();
        if (d>arr.size()){
            d = d%n ;
        }
        reverse(arr.begin(),arr.begin()+d);
        reverse(arr.begin()+d,arr.end());

        reverse(arr.begin(),arr.end());
         */
    }
};

//{ Driver Code Starts.

int main()
{
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--)
    {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number)
        {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        // calling rotateArr() function
        ob.rotateArr(arr, d);

        // printing the elements of the array
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends