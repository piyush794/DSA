/* Link : https://www.naukri.com/code360/problems/rabin-carp_1813576
Search Pattern (Rabin-Karp Algorithm)
Moderate
76/80
Average time to solve is 20m
Contributed by
93 upvotes
Asked in companies
Problem statement
You’re given two strings, 'text' of length 'n' and 'pattern' of length 'm', consisting of lowercase characters.



Find all the occurrences of the string ‘pattern’ in ‘text’.



For each occurrence, print the index from where it starts in the string ‘text’ (1 - indexed).



Example:
Input: ‘text’ = “cxyzghxyzvjkxyz” and ‘pattern’ = “xyz”

Output: 2 7 13

Explanation: The pattern ‘pattern’ = “xyz” appears at 3 positions in ‘text’.
*/

#include<iostream>
#include <cmath>
using namespace std ;
vector<int>ans;
int n ;
/* Brute Force through Sliding Window + String Compare 
*/

vector <int > Brute_stringMatch(string text, string pattern) {
	int m = pattern.size();
	int n = text.size();
	for (int i = 0 ;i<= n-m ; i++ ){
		string temp = text.substr(i, m);
		if (temp == pattern){
			ans.push_back(i+1);
		}
	}
	return ans;
}

/* Basic Rabin Karp Technique without Rolling Hash */
long long ipow(long long base, int exp) {
    long long result = 1;
    while (exp--) result *= base;
    return result;
}

long long  lps(string pattern){
	long long hashcode = 0 ;
	int m =	pattern.size();
	for (int i = 0 ;i<pattern.size();i++){
		hashcode = hashcode +(long long)pattern[i] * (ipow(127,m-i-1));
	}
	return hashcode;
}
vector<int> RabinBrutestringMatch(string text, string pattern) {

	n = text.size();
	int m = pattern.size();
	long long  hashcode = lps(pattern);
	for (int i = 0 ;i<= n-m  ;i++){
		long long  temp =0;
		for (int j = 0 ;j<m;j++){
			temp =temp+ (long long )text[j+i] * (ipow(127,m-j-1));
		}
		
		if (temp == hashcode){
			ans.push_back(i+1);
		}
	}
	return ans;
}


/* Most Optimal Rabin Karp Algorithm with Double Rolling HASH correctly implemented*/
#define ll long long int 

const ll RADIX_1 = 26;
const ll RADIX_2 = 27;
const ll MOD_1 = 1000000029;
const ll MOD_2 = 1000000033;


pair<ll ,ll > get_hash_Pair(string pattern , int m ){
	ll  hash1 = 0 , hash2 = 0 ;
	ll factor1 =  1  ,factor2 = 1;
	
	for (ll i = m-1 ; i>=0 ;i--){
		hash1 += ((int)pattern[i]*factor1)%MOD_1 ; 
		factor1 = (factor1 * RADIX_1) %MOD_1 ; 
		hash2 += ((int)pattern[i] * factor2 )%MOD_2 ;
		factor2 = (factor2 * RADIX_2 ) % MOD_2 ; 

	}
	return {hash1 % MOD_1, hash2%MOD_2 } ;

}
vector<int> stringMatch(string text, string pattern) {
	
	int n = text.size() ;
	int m = pattern.size() ;
	if (n<m )return {-1};
	ll MAX_WEIGHT_1 = 1 ;
	ll MAX_WEIGHT_2 = 1 ;
	for (int i=1 ;i<m ;i++){
		MAX_WEIGHT_1 = (MAX_WEIGHT_1 * RADIX_1) % MOD_1 ; 
		MAX_WEIGHT_2 = (MAX_WEIGHT_2 * RADIX_2) % MOD_2 ;
	}
	pair<ll , ll>hashcode = get_hash_Pair(pattern ,m);
	pair<ll , ll>texthash = {0 , 0 };

	for (int i =0 ;i<=n-m ;i++ ){
		if (i == 0 ){
			texthash = get_hash_Pair(text , m);
		}
		else{
			texthash.first =
						(
							( (texthash.first
								- ( (long long)(text[i-1]) * MAX_WEIGHT_1 ) % MOD_1
								+ MOD_1 ) % MOD_1
							* RADIX_1)
							+ (long long)(text[i+m-1])
						) % MOD_1;

					texthash.second =
						(
							( (texthash.second
								- ( (long long)(text[i-1]) * MAX_WEIGHT_2 ) % MOD_2
								+ MOD_2 ) % MOD_2
							* RADIX_2)
							+ (long long)(text[i+m-1])
						) % MOD_2;
		}
		if (texthash.first == hashcode.first && texthash.second == hashcode.second){
			ans.push_back(i+1);
		}
	}
	return ans;

}
int main(){
	string pattern;
	string text;
	cin>> text ;
	cin >> pattern ; 
	vector<int> result  = stringMatch(text , pattern);
	for (auto I : result){
		cout << I << " ";
	}
}