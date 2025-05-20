/* Link :https://www.naukri.com/code360/problems/make-it-palindrome_3189160?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTabValue=SUBMISSION
 Make It Palindrome
Easy
40/40
Average time to solve is 25m
Contributed by
47 upvotes
Asked in companies
Problem statement
You are given an array ‘A’ of length ‘N’ consisting only of positive integers. Your task is to make the given array a palindrome by using a minimum number of operations. In one operation, you can select two adjacent indexes and merge them by adding their values. After every operation, the length of the array decreases by one.

Note: An array of length ‘1’ is a palindrome.

For example:

Let’s say the array ‘A’ = [1, 2, 3, 4, 5], then after merging indexes 2 and 3, the array ‘A’ will look like [1, 5, 4, 5].

*/

#include <bits/stdc++.h> 
using namespace std;
int palindrome(vector<int > A)
{
    int n = A.size();
    vector<long long> arr(n);
    for(int i=0;i<n;i++) arr[i]=A[i];
	
    if (n==1)return 0;
    int i =0;
    int j =n-1;
    int count=0;
    while(i<j){
        int left  = arr[i];
        int right = arr[j];
        if (arr[i] == arr[j]) {
            i++;
            j--;
        }
        else if (arr[i] < arr[j]){
                
                arr[i+1] =arr[i+1]+arr[i];
                i++;
                count++;
        }
        else {
                
                arr[j-1] =arr[j-1]+arr[j];
                j--;
                count++;
            }
    }
    return count ;
}

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
        
        int ans = palindrome(arr);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends