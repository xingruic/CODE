# do not submit this this will not work
a,b,n=input().split()
a=int(a)
b=int(b)
n=int(n)
s=input()
d=dict()
for i in range(len(s)):
    for j in range(a-1,b):
        if i+j>=len(s):
            break
        if s[i:i+j+1] not in d:
            d[s[i:i+j+1]]=1
        else:
            d[s[i:i+j+1]]+=1
print(d)