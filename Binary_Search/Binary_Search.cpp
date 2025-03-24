
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int binary(vector<int> &nums, int s, int e, int target)
    {
        int mid = s + (e - s) / 2;
        if (s > e)
        {
            return -1;
        }
        if (nums[mid] == target)
        {
            return mid;
        }
        if (nums[mid] > target)
        {
            return binary(nums, s, mid - 1, target);
        }
        if (nums[mid] < target)
        {
            return binary(nums, mid + 1, e, target);
        }
    }

    int search(vector<int> &nums, int target)
    {
        // Write your code here.
        int e = nums.size();
        int s = 0;
        int ans = binary(nums, s, e, target);
        return ans;
    }
};
int main(){
int test_case;
cin >> test_case;
cin.ignore();
while (test_case--)
{

    int k;
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number)
    {
        arr.push_back(number);
    }
    string in;
    getline(cin, in);
    stringstream sss(in);
    int num;
    while (sss >> num)
    {
        k = num;
    }
    Solution ob;
    int ans = ob.search(arr, k);
    cout << ans << endl;
    cout << "~" << endl;
}
return 0;
}

// } Driver Code Ends