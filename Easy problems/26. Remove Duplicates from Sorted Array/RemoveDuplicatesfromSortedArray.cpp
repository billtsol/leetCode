#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int removeDuplicates(vector<int> &nums)
  {
    int length = nums.size();
    int insertIndex = 1;

    for (int i = 1; i < nums.size(); i++)
    {
      if (nums[i - 1] != nums[i])
      {
        nums[insertIndex] = nums[i];
        insertIndex++;
      }
    }
    return insertIndex;
  }
};

/*

Complexity Analysis

Let N be the size of the input array.

Time Complexity: O(N), since we only have 2 pointers, and both the pointers will traverse the array at most once.

Space Complexity: O(1), since we are not using any extra space.

*/