# def getsum(n, sum=0, step=1):
#     if n == 0:
#         return sum
#     sum += n
 
#     return getsum(n - 1, sum, step + 1)


# result = getsum(123)
# print(f"Final sum: {result}")  


def sum(n):
    if n==0:
        return 0
    return n+sum(n-1)

print(sum(5))

def sumdigit(n):
    if n==0:
        return n 
    return n%10 +sumdigit(n//10)

print(sumdigit(12341))