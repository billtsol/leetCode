"""
Dynamic Programming solution.
Top-Down approach.
"""
class Solution:
  def longestCommonSubsequence(self, text1: str, text2: str) -> int:

    length_text1 = len(text1)
    length_text2 = len(text2)

    memo = {}

    def dp(i: int, j: int) -> int:

      if length_text1 == i or length_text2 == j:
        return 0

      if text1[i] == text2[j]:
        return dp(i + 1, j + 1) + 1

      if ( i, j ) not in memo:
        memo[ ( i, j ) ] = max( dp(i + 1, j), dp(i, j + 1) )

      return memo[ ( i, j ) ]

    return dp(0,0)