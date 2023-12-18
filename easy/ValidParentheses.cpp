#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  bool isValid(string s)
  {
    unordered_map<char, int> parentheses;

    parentheses.insert({'(', 0});
    parentheses.insert({')', 1});
    parentheses.insert({'{', 2});
    parentheses.insert({'}', 3});
    parentheses.insert({'[', 4});
    parentheses.insert({']', 5});

    std::vector<int> start;
    int pointer = -1;

    for (size_t i = 0; i < s.length(); i++)
    {
      if (pointer == -1)
      {
        if (parentheses[s[i]] % 2 == 1)
          return false;
        pointer = pointer + 1;
        start.push_back(parentheses[s[i]]);
      }
      else
      {
        if (parentheses[s[i]] % 2 == 1)
        {
          if ((parentheses[s[i]]) - 1 != start[pointer])
          {
            return false;
          }
          else
          {
            start.pop_back();
            pointer = pointer - 1;
          }
        }
        else if (parentheses[s[i]] % 2 == 0)
        {
          pointer = pointer + 1;
          start.push_back(parentheses[s[i]]);
        }
        else if ((start[pointer] + 1) != parentheses[s[i]])
        {
          return false;
        }
      }
    }
    return start.size() == 0;
  }
};
