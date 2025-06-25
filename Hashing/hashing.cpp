#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cin >> n;
    int arr[n];
    cout<<" Please Enter Values Only between 1 to 5\n";
    for (int i =0 ;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Our Array to find out the count the occurrences of elements :\n";
    for (auto i : arr){
        cout<<i<<" ";
    }

    // Hash array to count occurrences
    int hash[n] = {0};
    for (int i =0;i<n ;i++){
        hash[arr[i]] +=1;
    }
    cout<<"\n OUTPUT OCCURRENCES:\n";
    for(int i = 1 ;i<6;i++){
        cout<<i<<" : "<<hash[i]<<endl;
    }
    return 0 ;

}