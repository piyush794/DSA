#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<climits>
using namespace std;
class Solution {
    public:
        int findDuplicate( vector <int>& arr) {
            // Brute Force 
            /*unordered_map<int ,int >mapy;
            for(int i =0 ;i<arr.size();i++){
                mapy[arr[i]]++;
            }
            for(int i =0 ;i<arr.size();i++){
                if (mapy[arr[i]]>1){
                    return arr[i];
                }
            }
            return 0;
            */
            // Optimal Solution Floyd's Cycle Detection method is used
            int slow = arr[0];
            int fast = arr[0];
            while (true) {
                slow = arr[slow];
                fast = arr[arr[fast]];
    
                if (slow == fast) {
                    break;
                }
            }
            int slow2 = arr[0];
            while(slow != slow2){
                slow= arr[slow];
                slow2= arr[slow2];
    
            }
            return slow ;
        
        }
    };

int main(){
    int n ;
    cin>>n;
    cin.ignore();
    while(n--){
        string ip;
        vector<int>arr;
        getline(cin,ip);
        stringstream ss(ip);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout <<"The Duplicate is : " <<obj.findDuplicate(arr) << endl << "~\n";
    
    return 0;

    }
}