from typing import List

class Solution:
  def minCostClimbingStairs(self, cost: List[int]) -> int:
    def dp(i):
      if i >= len(cost) - 2:
        return cost[i]
      else:
        if i not in memo:
          memo[i] = cost[i] + min(dp(i + 1), dp(i + 2))

      return memo[i]

    memo = {}
    return min(dp(0),dp(1))