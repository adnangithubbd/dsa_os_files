def sum_digit(n):
    if n==0:
        return 0
    else:
        return n%10 +sum_digit(n//10)

res=sum_digit(1293)
print(res)