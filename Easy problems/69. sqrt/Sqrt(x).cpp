#include <iostream>

using namespace std;

class Solution
{
public:
  int mySqrt(int x)
  {

    if (x < 2)
      return x;

    int left = 1;
    int right = (x / 2);
    long int number;
    int middle;

    while (left <= right)
    {
      middle = left + (right - left) / 2;

      number = (long)middle * middle;

      if (number == x)
      {
        return middle;
      }
      else if (number > x)
      {
        right = middle - 1;
      }
      else
      {
        left = middle + 1;
      }
    }
    return right;
  }
};

/*
Complexity Analysis

Time complexity : O(log⁡N).

Space complexity : O(1).

*/