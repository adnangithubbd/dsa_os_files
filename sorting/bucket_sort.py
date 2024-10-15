def bucket_sort(arr):
    if not arr:
        return arr
    
    # Step 1: Create buckets
    max_value = max(arr)
    size = max_value // len(arr) + 1  # Define bucket size
    buckets = [[] for _ in range(size)]
    
    # Step 2: Distribute elements into buckets
    for num in arr:
        index = num // len(arr)  # Determine the bucket index
        buckets[index].append(num)
    
    # Step 3: Sort individual buckets and concatenate
    sorted_array = []
    for bucket in buckets:
        sorted_array.extend(sorted(bucket))  # Sort each bucket (using built-in sort)
    
    return sorted_array


arr = [4, 2, 2, 8, 3, 3, 1]
sorted_arr_bucket = bucket_sort(arr)
print("Sorted array using Bucket Sort:", sorted_arr_bucket)