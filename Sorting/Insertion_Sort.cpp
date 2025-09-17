/*
Problem Statement: Given an array of N integers, write a program to implement the Insertion sorting algorithm.

Examples:

Example 1:
Input: N = 6, array[] = {13,46,24,52,20,9}
Output: 9,13,20,24,46,52
Explanation: 
After sorting the array is: 9,13,20,24,46,52*

Approach: 

Select an element in each iteration from the unsorted array(using a loop).
Place it in its corresponding position in the sorted part and shift the remaining elements accordingly (using an inner loop and swapping).
The “inner while loop” basically shifts the elements using swapping.

Time complexity: O(N2), (where N = size of the array), for the worst, and average cases.
Reason: If we carefully observe, we can notice that the outer loop, say i, is running from 0 to n-1 i.e. n times, and for each i, the inner loop j runs from i to 1 i.e. i times. For, i = 1, the inner loop runs 1 time, for i = 2, the inner loop runs 2 times, and so on. So, the total steps will be approximately the following: 1 + 2 + 3 +......+ (n-2) + (n-1). The summation is approximately the sum of the first n natural numbers i.e. (n*(n+1))/2. The precise time complexity will be O(n2/2 + n/2). Previously, we have learned that we can ignore the lower values as well as the constant coefficients. So, the time complexity is O(n2). Here the value of n is N i.e. the size of the array.

Space Complexity: O(1)
*/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution
{

public:
    
void insertion_sort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(arr[j - 1], arr[j]);
            j--;
        }
    }
}

};

//{ Driver Code Starts.
/* Function to print an array */
void printArray(const vector<int>& arr) {
    for (int num : arr)
        printf("%d ", num);
    printf("\n");
}

int main()
{

    int T;
    scanf("%d", &T);
    getchar(); // to consume newline after T

    while (T--)
    {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }

        Solution ob;
        ob.insertion_sort(arr);
        printArray(arr);
    }

    return 0;
}

// } Driver Code Ends
