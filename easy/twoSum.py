class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """

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
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.



Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]


Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.


Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?

"""