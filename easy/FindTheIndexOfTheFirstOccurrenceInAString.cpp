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
        size_t j = i + 1;
        bool flag = true;
        for (size_t k = 1; k < needle.length(); k++)
        {
          if (haystack[j] != needle[k])
          {
            flag = false;
            break;
          }
          j++;
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
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.



Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.


Constraints:

1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.
*/