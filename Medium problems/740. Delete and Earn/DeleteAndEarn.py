from collections import defaultdict
from functools import cache
from typing import List

class Solution:
  def deleteAndEarn(self, nums: List[int]) -> int:

    points = defaultdict(int)
    max_number = 0

    # Precompute how many points we gain from taking an element
    for num in nums:
      points[num] += num
    max_number = max(max_number, num)

    @cache
    def maxPoints(num: int) -> int:
      if num == 0:
        return 0
      if num == 1:
        return points[1]

      return max(maxPoints(num - 1), maxPoints(num - 2) + points[num])

    return maxPoints(max_number)
