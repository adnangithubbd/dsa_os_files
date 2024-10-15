def product(arr,n):
    if n==0:
        return 1
    return product(arr,n-1)*arr[n]

ar=[1,2,3,4,3]
# print(product(ar,len(ar)-1))

 
def count_zeros(n):
    if n==0:
        return 1
    if n<10:
        return 0
    return (1 if n%10==2 else 0)+ count_zeros(n//10)

# print(count_zeros(1200220320))

def permute(arr,l,r,count):
    if l==r:
        print(arr)
        count[0]+=1
    else:
        for i in range(l,r):
            arr[l],arr[i]=arr[i],arr[l]
            permute(arr,l+1,r,count)
            arr[l],arr[i]=arr[i],arr[l]

arr=[1,2,3]
count=[0]
permute(arr,0,len(arr),count)
print(count)