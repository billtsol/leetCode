# python3
from typing import List

class Solution:
  def twoSum(self, nums: List[int], target: int) -> List[int]:
    hashmap = {}
    for i in range(len(nums)):
      # To y einai to noymero poy psaxno gia na trexei i praksi
      y = target - nums[i]
      # Ean to y yparxei sto hashmap tote epistrefo tin thesi toy nums[i] kai tin thesi toy y
      if y in hashmap:
        return [i,hashmap[y]]
      # To hashmap krataei ta noymera tis listas poy exo perasei kai tin thesi toys
      hashmap[nums[i]] = i

"""

Algorithm

It turns out we can do it in one-pass. While we are iterating and inserting elements into the hash table, we also look back to check if current element's complement already exists in the hash table. If it exists, we have found a solution and return the indices immediately.

Complexity Analysis

Time complexity: O(n).
We traverse the list containing nnn elements only once. Each lookup in the table costs only O(1)O(1)O(1) time.

Space complexity: O(n).
The extra space required depends on the number of items stored in the hash table, which stores at most nnn elements.

"""