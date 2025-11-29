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
/* Brute Force Technique without Rolling Hash */
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
vector<int> stringMatch(string text, string pattern) {

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

