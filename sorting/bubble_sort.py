my_array = [64, 34, 25, 12, 22, 11, 90, 5]

n=len(my_array)

for i in range(n-1):
    for j in range(n-i-1):
        if my_array[j]>my_array[j+1]:
            my_array[j],my_array[j+1]=my_array[j+1],my_array[j]

print(my_array)

for i in range(n-1):
    swapped=False
    for j in range(n-i-1):
        if my_array[j]>my_array[j+1]:
            swapped=True
            my_array[j],my_array[j+1]=my_array[j+1],my_array[j]
    
    if not swapped:
        break
print(my_array)