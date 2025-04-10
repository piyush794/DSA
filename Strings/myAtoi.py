'''// LInk : 

Intuition :
The goal is to parse the input string to extract an integer while handling:

Leading whitespace
Optional sign (+ or -)
Conversion of digits into an integer
Clamping the result within the 32-bit integer range [-2^31, 2^31 - 1]
Approach :
Ignore Leading Whitespace: Skip over any leading spaces in the string.
Sign Detection: Check for a + or - sign immediately after the whitespace.
Convert Digits to Integer: Start reading consecutive digits, stopping when a non-digit is encountered.
Clamp to 32-bit Integer Range: If the integer exceeds 2^31 - 1 or goes below -2^31, clamp it to fit within these bounds.
Return the Result.
Solution Steps :
Define the bounds for 32-bit integers.
Remove leading whitespace using indexing.
Set the sign based on the first character, if it's + or -.
Traverse through each character of the string to build the integer.
If an overflow is detected during the process, clamp the result.'''
#User function template for Python
class Solution:
    def myAtoi(self, s: str) -> int:
        i=0
        a=0
        n=len(s)
        flag =0
        while i < n and s[i]==' ':
            i+=1
        if i< n and (s[i]=='+'or s[i]=='-'):
            if s[i] == '-':
                flag = 1

        while i<n and '0'<=s[i]<='9':

            if a>2**31-1 :
                return 2**31 -1
            if  a<-2**31:
                return -2**31
            a = a*10 + int(s[i])
            i+=1
        if flag == 1:
            return -1*a 
        return a 


#{ 
 # Driver Code Starts
#Initial template for Python

if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        s = input()
        ob = Solution()
        print(ob.myAtoi(s))
        print("~")

# } Driver Code Ends