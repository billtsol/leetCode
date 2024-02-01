#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int strStr(string haystack, string needle)
  {
    size_t needleLength = 0;

    for (size_t i = 0; i < haystack.length(); i++)
    {
      if (haystack[i] == needle[0])
      {
        bool flag = true;
        for (size_t k = 1; k < needle.length(); k++)
        {
          if (haystack[i + k] != needle[k])
          {
            flag = false;
            break;
          }
        }
        if (flag)
        {
          return i;
        }
      }
    }
    return -1;
  }
};

/*

Time complexity: O(nm).

Space complexity: O(1).

*/