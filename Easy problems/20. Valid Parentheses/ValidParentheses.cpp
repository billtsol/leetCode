#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution
{
public:
  bool isValid(string s)
  {
    unordered_map<char, char> parentheses;

    parentheses.insert({'(', ')'});
    parentheses.insert({'{', '}'});
    parentheses.insert({'[', ']'});

    std::stack<char> stack;

    for (int i = 0; i < s.length(); i++)
    {
      if (parentheses.find(s[i]) != parentheses.end())
      {
        stack.push(s[i]);
      }
      else
      {
        if (stack.empty())
        {
          return false;
        }
        char lastPar = stack.top();

        if (parentheses[lastPar] != s[i])
        {
          return false;
        }

        stack.pop();
      }
    }

    return stack.empty();
  }
};

/*
Complexity analysis

Time complexity : O(n) because we simply traverse the given string one character at a time and push and pop operations on a stack take O(1)O(1)O(1) time.

Space complexity : O(n) as we push all opening brackets onto the stack and in the worst case, we will end up pushing all the brackets onto the stack. e.g. (((((.
*/