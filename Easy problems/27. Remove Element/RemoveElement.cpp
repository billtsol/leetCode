#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int removeElement(vector<int> &nums, int val)
  {

    int reader = 0, writer = 0;

    int length = nums.size();

    while (reader < length)
    {
      if (nums[reader] != val)
      {
        nums[writer] = nums[reader];
        writer++;
      }
      reader++;
    }

    return writer;
  }
};


/*
Complexity analysis

Time complexity : O(n).
Assume the array has a total of n elements, both i and j traverse at most 2n steps.

Space complexity : O(1).

*/