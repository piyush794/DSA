#include <iostream>
#include <vector>
using namespace std;

int main(){
    int  n; 
    cin>> n;
    int arr[n];
    int hash[n+1] = {0};
    for (int i=0;i<n;i++){
        cin >> arr[i];
        hash[arr[i]] = hash[arr[i]]+ 1;
    }
    int q ;

    cout << "VALUE of q \n";
    cin >> q ;
    while (q--){
    int query;
    cout<< "\nAsking Query -----";
    cin >> query;
    cout << "   " << hash[query];
        }
    return 0;
}
