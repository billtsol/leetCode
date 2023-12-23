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

/*
3. Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without repeating characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.


Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.

*/