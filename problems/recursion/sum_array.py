def sum(ar):
    if len(ar)==0:
        return 0
    else:
        return ar[0]+sum(ar[1:])

arr = [1, 2, 3, 4, 5]

res=sum(arr)
print(res)
