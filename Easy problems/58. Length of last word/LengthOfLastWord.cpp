#include <iostream>

using namespace std;

class Solution
{
public:
  int lengthOfLastWord(string s)
  {
    int length = s.size() - 1;
    int foundletter = 0;

    for (size_t i = length; i >= 0; i--)
    {
      if (s[i] != ' ')
      {
        foundletter = i;
        break;
      }
    }

    int count = 0;
    for (int i = foundletter; i >= 0; i--)
    {
      if (s[i] == ' ')
      {
        break;
      }
      count++;
    }

    return count;
  }
};

/*
Complexity Analysis

Time Complexity: O(N).

Space complexity: O(1).
*/