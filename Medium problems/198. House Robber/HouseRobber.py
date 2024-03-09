from typing import List

class Solution:
  def rob(self, nums: List[int]) -> int:
    def solve(i):

      if i == 0:
        return nums[0]
      elif i == 1:
        return max(nums[0],nums[1])
      else:
        if i not in memo:
          memo[i] = max(solve(i - 1), solve(i - 2) + nums[i])
      return memo[i]

    memo = {}
    return solve(len(nums)-1)