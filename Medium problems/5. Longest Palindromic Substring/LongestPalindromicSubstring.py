class Solution:
  def longestPalindrome(self, s: str) -> str:

    if self.isPalindromicString(s):
      return s

    longest = [0,1] # Start char, last char

    for i in range(1,len(s)):

      front = i
      back = i + 1

      while front-1 >= 0 and back + 1 <= len(s):
        if self.isPalindromicString(s[front - 1:back + 1]):
          front -= 1
          back += 1
        elif self.isPalindromicString(s[front:back + 1]):
          back += 1
        elif self.isPalindromicString(s[front - 1:back]):
          front -= 1
        else:
          break

      if back + 1 < len(s):
        if self.isPalindromicString(s[front:back + 1]):
          back += 1

      if front > 0:
        if self.isPalindromicString(s[front - 1:back]):
          front -= 1

      if back - front > longest[1] - longest[0]:
        longest[0] = front
        longest[1] = back

    return s[ longest[0]: longest[1] ]

  def isPalindromicString(self,myStr: str) -> bool:
    front = 0
    back = len(myStr) - 1

    while (front < back):
      if myStr[front] != myStr[back]:
        return False
      front += 1
      back -= 1
    return True