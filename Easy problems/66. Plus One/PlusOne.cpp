#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> plusOne(vector<int> &digits)
  {

    int length = digits.size();
    bool isNine = false;

    for (int i = length - 1; i >= 0; i--)
    {
      if (digits[i] == 9)
      {
        digits[i] = 0;
        isNine = true;
      }
      else
      {
        digits[i] = digits[i] + 1;
        isNine = false;
        break;
      }
    }

    if (isNine)
    {
      digits.insert(digits.begin(), 1);
    }

    return digits;
  }
};

/*
Complexity Analysis

Time complexity: O(N)

Space complexity: O(N).

*/