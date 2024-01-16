# python3
from typing import List

class Solution:
  def longestCommonPrefix(self, strs: List[str]) -> str:

    if (strs == None or len(strs) == 0 ):
      return ""

    # Search for the min string.
    minString = strs[0]
    for i in range(1,len(strs)):
      if strs[i] < minString:
          minString = strs[i]

    strs.remove(minString)

    notCommon = True
    charRange = len(minString) + 1

    while (notCommon):
      notCommon = False
      charRange-=1
      letter = minString[:charRange]

      for i in strs:
        if i[0:charRange] == letter:
          pass
        else:
          notCommon = True
          break

    if charRange >= 1:
      return minString[0:charRange]

    return ""