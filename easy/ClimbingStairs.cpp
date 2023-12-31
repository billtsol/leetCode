#include <iostream>

using namespace std;

class Solution
{
public:
  int climbStairs(int n)
  {

    if (n == 1 || n == 2 || n == 3)
      return n; // Stis protes periptoseis einai o idios o arithmos

    unsigned long long result = 1; // Einai 1 poy einai ola asoi

    int numbersTwo = 1; // Stin arxi exo 1 dyari

    int numbersOne = n - 2; // Ara exo n - 1 assoys, ean einai monos

    for (int i = 1; numbersOne > 0; i++)
    {
      result = result + binomialCoefficients(numbersOne + i, i);
      numbersOne -= 2; // afairo enan asso
    }

    if (n % 2 == 0)
      return result + 1;

    return result;
  }

  int binomialCoefficients(int n, int k)
  {
    if (k == 0 || k == n)
      return 1;
    return binomialCoefficients(n - 1, k - 1) + binomialCoefficients(n - 1, k);
  }
};

/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

Constraints:

1 <= n <= 45
*/