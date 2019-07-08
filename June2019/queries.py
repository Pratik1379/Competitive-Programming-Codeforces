n,m = input().split()
n = int(n)
m = int(m)
ar = list(map(int,input().split()))
mypro=1
for i in range(n):
    mypro=mypro*ar[i]
'''for i in range(1,n):
	pro.append(pro[i-1]*ar[i])
for i in range(n-2,-1,-1):
    pro2[i]=pro2[i+1]*ar[i+1]'''
for _ in range(m):
    br = list(map(int,input().split()))
    if br[0]==2:
        ind=0
        temp2=ar[0]*ar[0]
        dif=abs(temp2-mypro)
        for j in range(1,n-1):
            temp2=temp2*ar[j]*ar[j]
           # print(temp2,temp3)
            temp=abs(temp2-mypro)
            if temp<dif:
                dif=temp
                ind=j
            else:
                break
        print(ind+1)
    else:
        x=br[1]-1
        y=br[2]
        ar[x]=ar[x]*y
        mypro=mypro*y            