def binary_search(arr,left,right,target):
    if left<=right:
        mid=(left+right)//2
        
        if arr[mid]==target:
            return mid 
        elif arr[mid]>target:
            return binary_search(arr,left,mid-1,target)
        else:
            return binary_search(arr,mid+1,right,target) 
    return -1

arr = [1, 3, 5, 7, 9]
res=binary_search(arr,0,len(arr)-1,7)
print(res)