def linearsearch(arr,target):
    
    for i in range(len(arr)):
        if arr[i]==target:
            return i
    return -1

arr = [3, 7, 2, 9, 5]
targetVal = 2
print(linearsearch(arr,targetVal))