n = int(input())
arr =  [int(input()) for _ in  range(n)]
hash_arr = [0]*(n+1)
for i in range(n):
    hash_arr[arr[i]] =hash_arr[arr[i]] + 1

query = int(input("Enter the queery")) 
print(hash_arr[query])