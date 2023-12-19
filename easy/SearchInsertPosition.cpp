#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int searchInsert(vector<int> &nums, int target)
  {

    int start = 0;
    int center = nums.size() / 2;
    int end = nums.size() - 1;
    int lastCheck = 0;

    while (start != end)
    {

      if (nums[center] == target)
      {
        return center;
      }
      else if (nums[center] > target)
      {
        end = center - 1;
        if (end < 0)
        {
          end = 0;
        }
      }
      else
      {
        start = center + 1;
        if (center == end)
        {
          start = end;
        }
      }

      lastCheck = center;
      center = (end + start) / 2;
    }

    if (nums[start] < target)
    {

      return start + 1;
    }

    return start;
  }
};

/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104

*/