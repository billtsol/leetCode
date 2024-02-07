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
Complexity Analysis

Time complexity: O(max⁡(N,M))

Space complexity: O(max⁡(N,M))

*/