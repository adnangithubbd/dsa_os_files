def coinchange(coins,n):
    dp=[0]*(n+1)
    
    dp[0]=1
    
    for coin in coins:
        for i in range(coin,n+1):
            dp[i]+=dp[i-coin]
    return dp[n]


coins = [1, 2, 5]
amount = 5
result = coinchange(coins, amount)
print(f"The number of ways to make change for {amount} is: {result}")   