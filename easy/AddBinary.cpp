#include <iostream>

using namespace std;

class Solution
{
public:
  string addBinary(string a, string b)
  {
    string result = "";

    char carry = '0';

    int maxLength = std::max(a.length(), b.length());

    string a1 = string(maxLength - a.length(), '0') + a;
    string b1 = string(maxLength - b.length(), '0') + b;

    int minLength = min(a.length(), b.length());

    for (int i = maxLength - 1; i >= 0; i--)
    {

      if (a1[i] == b1[i])
      {
        result = carry + result;
        carry = a1[i];
      }
      else
      {
        if (carry == '1')
        {
          result = '0' + result;
        }
        else
        {
          result = '1' + result;
        }
      }
    }

    if (carry == '1')
    {
      result = '1' + result;
    }

    return result;
  }
};

/*
Given two binary strings a and b, return their sum as a binary string.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"

Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
*/