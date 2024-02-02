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
Complexity Analysis

Time complexity : O(log⁡N).

Space complexity: O(1).

*/