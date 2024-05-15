"""
Dynamic Programming solution.
Bottom-Up approach.
"""
class Solution:
  def longestCommonSubsequence(self, text1: str, text2: str) -> int:

    length_text1 = len(text1)
    length_text2 = len(text2)

    grid = [ [0] * (length_text2 + 1) for i in range(length_text1 + 1)]

    for i in range((length_text1 - 1), -1, -1):

      for j in range((length_text2 - 1), -1, -1):

        if text1[i] == text2[j]:
          grid[i][j] = grid[i + 1][j + 1] + 1
        else:
          grid[i][j] = max( grid[i + 1][j], grid[i][j + 1])

    return grid[0][0]