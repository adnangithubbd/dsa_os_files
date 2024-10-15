myArray = [170, 45, 75, 90, 802, 24, 2, 66]

radixArray=[[],[],[],[],[],[],[],[],[],[]]
maxVal=max(myArray)

exp=1

while maxVal//exp>0:

    while len(myArray)>0:
        val=myArray.pop()
        radixIndex=(val//exp)%10
        radixArray[radixIndex].append(val)
        
    for bucket in radixArray:
        while len(bucket)>0:
            val=bucket.pop()
            myArray.append(val)
    
    exp*=10
print(myArray)

#  for i in range(len(count)):
#         while count[i]>0:
#             arr.append(i)
#             count[i]-=1