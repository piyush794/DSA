//{ Driver Code Starts
/*
Link : https://www.geeksforgeeks.org/problems/intersection-of-two-arrays2404/1
Intersection of Arrays with Distinct
Difficulty: EasyAccuracy: 32.83%Submissions: 218K+Points: 2Average Time: 20m
Given two unsorted integer arrays a[] and b[] each consisting of distinct elements, the task is to return the count of elements in the intersection (or common elements) of the two arrays.

Intersection of two arrays can be defined as the set containing distinct common elements between the two arrays. 

Examples:

Input: a[] = [89, 24, 75, 11, 23], b[] = [89, 2, 4]
Output: 1
Explanation: 89 is the only element in the intersection of two arrays.

*/
#include<climits>
#include<sstream>
#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;


// } Driver Code Ends
// User function template for C++

// Function to return the count of the number of elements in
// the intersection of two arrays.

class Solution {
  public:
  /* Approach 0  Brute Force Unga Bunga 
  int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
        // Your code goes here
        
       int count=0;
        
        for(int i=0;i<n;i++){
            if(i>0 && a[i]==a[i-1]) continue;
            for(int j=0;j<m;j++){
                if(a[i]==b[j]){ 
                    count++;
                    break;
                }
            }
        }
  */
  
  //Approach 2; set most optimal
  int numberofElementsInIntersection(vector<int> &a, vector<int> &b) {
        unordered_set<int>s;
        for(int i =0 ;i<a.size();i++){
            s.insert(a[i]);
        }
        int count =0;
        for(int i =0 ;i<b.size();i++){
            if (s.find(b[i])!= s.end()){
                count++;
            }
        }
        return count;
         }   /*
         
        // Approach 1 map not optimal due to collisions in Hashing Learn about it 
    int numberofElementsInIntersection(vector<int> &a, vector<int> &b) {
        unordered_map<int ,int>mapy;
        for(int i =0 ;i<a.size();i++){
            mapy[a[i]]++;
        }
        
        for(int i =0 ;i<b.size();i++){
            
            mapy[b[i]]++;
        }
        int count=0;
        for(auto i : mapy){
            if(i.second==2){
                count++;
            }
        }
        return count;
    }
    */
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr1, arr2;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            arr2.push_back(number);
        }

        Solution ob;
        int res = ob.numberofElementsInIntersection(arr1, arr2);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends