class Solution:
  def romanToInt(self, s: str) -> int:
    symbols = {
      'I':1,
      'V':5,
      'X':10,
      'L':50,
      'C':100,
      'D':500,
      'M':1000
    }

    result = 0
    for i in range (len(s)):

      if (i != 0 and symbols[s[i]] > symbols[s[i - 1]]):
        result = result - 2*symbols[s[i - 1]]

      result += symbols[s[i]]

    return result



"""
Complexity Analysis

Let nnn be the length of the input string (the total number of symbols in it).

Time complexity : O(1).

As there is a finite set of roman numerals, the maximum number possible number can be 3999, which in roman numerals is MMMCMXCIX. As such the time complexity is O(1).

If roman numerals had an arbitrary number of symbols, then the time complexity would be proportional to the length of the input, i.e. O(n)O(n)O(n). This is assuming that looking up the value of each symbol is O(1).


Space complexity : O(1).

Because only a constant number of single-value variables are used, the space complexity is O(1).

"""