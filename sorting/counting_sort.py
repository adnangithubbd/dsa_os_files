def counting_sort(arr):
    count=[0]*(max(arr)+1)
    
    while len(arr)>0:
        num=arr.pop(0)
        count[num]+=1
    
    for i in range(len(count)):
        while count[i]>0:
            arr.append(i)
            count[i]-=1
    return arr

Arr = [4, 2, 2, 6, 3, 3, 1, 6, 5, 2, 3]
res=counting_sort(Arr)
print(res)

 