import numpy as np

def knapsack(W, weights, values, n):
    # Create a 2D DP array where dp[i][w] represents the maximum value 
    # that can be achieved with i items and a weight limit of w.
    dp = np.zeros((n+1,W+1),dtype=int)
  
    # Build the dp array in a bottom-up manner
    for i in range(n + 1):
        for w in range(W + 1):
            if i == 0 or w == 0:
                dp[i][w] = 0  # Base case: no items or weight capacity 0
            elif weights[i - 1] <= w:
                # Include the item and take the max value
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w])
            else:
                # Exclude the item
                dp[i][w] = dp[i - 1][w]

    return dp[n][W]  # The bottom-right corner contains the answer

# Example usage
values = [60, 100, 120] 
weights = [10, 20, 30]   
W = 50                  
n = len(values)           

max_value = knapsack(W, weights, values, n)
print(f"The maximum value that can be put in a knapsack of capacity {W} is {max_value}")
