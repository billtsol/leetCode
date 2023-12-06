class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """

        if x < 0:
            return False
        if x <= 9:
            return True

        if x <= 99:
            return int(x/10) == x%10
        else:
            numbers = []
            temp = x
            while(temp != 0):
                numbers.append(temp%10)
                temp = int(temp/10)

            length = len(numbers)
            y = 0

            pw = 0
            for i in range(length - 1, -1,-1):
                power = 10 ** pw
                pw+=1
                y = y + numbers[i] * power

            return x == y


"""
Given an integer x, return true if x is a palindrome, and false otherwise.

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.


Constraints:

-231 <= x <= 231 - 1

Follow up: Could you solve it without converting the integer to a string?
"""