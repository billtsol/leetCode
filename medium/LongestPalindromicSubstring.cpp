#include <iostream>

using namespace std;

class Solution
{
public:
  string longestPalindrome(string s)
  {
    if (s.length() < 2)
    {
      return s;
    }

    int end = s.length();
    string currStr;

    for (int i = 0; i < s.length(); i++)
    {
      int numberOfChars = end - i;
      currStr = s.substr(i, numberOfChars);

      if (this->isPalindromic(currStr))
      {
        return currStr;
      }

      for (int j = 1; j <= i; j++)
      {
        currStr = s.substr(i - j, numberOfChars);

        if (this->isPalindromic(currStr))
        {
          return currStr;
        }
      }
    }
    return "";
  }

  bool isPalindromic(string s)
  {
    int left = 0;
    int right = s.length() - 1;

    while (left < right)
    {

      if (s[left] != s[right])
      {
        return false;
      }

      left++;
      right--;
    }

    return true;
  }
};