class Solution(object):
  def longestCommonPrefix(self, strs):
    """
    :type strs: List[str]
    :rtype: str
    """


    minString = strs[0]
    for i in range(1,len(strs)):
      if strs[i] < minString:
          minString = strs[i]

    strs.remove(minString)

    stop = False
    notCommon = False
    charRange = 1
    while (not stop):
      letter = minString[0:charRange]

      for i in strs:
        if i[0:charRange] == letter:
          pass
        else:
          notCommon = True
          break

      if charRange > len(minString)+1:
        stop = True
      elif not notCommon:
        charRange +=1
      else:
        stop = True

    if charRange >= 1:
        return minString[0:charRange-1]
    return "There is no common prefix among the input strings."


"""
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.
"""