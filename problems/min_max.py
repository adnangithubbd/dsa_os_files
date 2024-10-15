def find_min_max(arr,low,high):
    if low==high:
        return arr[low],arr[high]
    if high==low+1:
        return (min(arr[low],arr[high]),max(arr[low],arr[high]))
    
    mid=(low+high)//2
    min1,max1=find_min_max(arr,low,mid)
    min2,max2=find_min_max(arr,mid+1,high)
    
    return(min(min1,min2),max(max1,max2))

arr = [3, 5, 1, 8, 2, 7, 4]

low,high=find_min_max(arr,0,high=len(arr)-1)
print(low)
print(high)