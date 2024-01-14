# python3

class Solution:
  def isPalindrome(self, x: int) -> bool:
    if x < 0 or (x % 10 == 0 and x != 0):
      return False

    revertedNumber = 0
    while x > revertedNumber:
      revertedNumber = revertedNumber * 10 + x % 10

      x = x // 10

    return x == revertedNumber or x == revertedNumber // 10


"""
Algorithm

Παιρνουμε το μεχρι την μεση, αλλα καθε νουμερο του βαζουμε μπορστα στον revertedNumber. Εαν φτασουμε στην μεση του αριθμου και οι δυο αριθμοι ειναι ιδιοι ή ο revertedNumber ειναι μεγαλυτερος απο τον x αλλα αφαιρωντας το τελευταιο στοιχειο εινα ιδιοι, τοτε ειναι παλινδρομος.


Complexity Analysis

Time complexity : O(log10(n))
We divided the input by 10 for every iteration, so the time complexity is O(log10(n))

Space complexity : O(1).
"""