#include <iostream>

using namespace std;

class Solution
{
public:
  int climbStairs(int n)
  {
    int memo[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
      memo[i] = 0;
    }
    return clim_stairs(0, n, memo);
  };

  int clim_stairs(int i, int n, int memo[])
  {
    if (i > n)
    {
      return 0;
    }
    if (i == n)
    {
      return 1;
    }

    if (memo[i] > 0)
    {
      return memo[i];
    }

    memo[i] = clim_stairs(i + 1, n, memo) + clim_stairs(i + 2, n, memo);
    return memo[i];
  }
};
