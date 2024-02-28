#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    unordered_map<char, int> hashmap;

    int result = 0;
    int currentResult = 0;

    for (int i = 0; i < s.length(); i++)
    {
      char c = s.at(i);

      if (hashmap.find(c) == hashmap.end())
      {
        hashmap[c] = i;
        currentResult = currentResult + 1;
      }
      else
      {

        if (currentResult > result)
        {
          result = currentResult;
        }

        if (i - hashmap[c] <= currentResult)
        {
          currentResult = i - hashmap[c];
        }
        else
        {
          currentResult = currentResult + 1;
        }
        hashmap[c] = i;
      }
    }

    if (currentResult > result)
    {
      result = currentResult;
    }

    return result;
  }
};
