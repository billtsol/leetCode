from typing import List, Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:

  def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
    if p == None and q == None:
      return True
    myvar = [True]

    myvar[0] = myvar[0] and self.recursive(p,q,myvar)
    return myvar[0]

  def recursive(self,root1, root2,myvar):
    var1 = True
    var2 = True

    if root1 == None or root2 == None:
      return False
    elif root1 != None and root2 != None:
      if root1.val != root2.val:
        return False

    if root1.left != None and root2.left != None:
      var1 =  self.recursive(root1.left, root2.left,myvar)
    elif (root1.left == None and root2.left != None) or (root1.left != None and root2.left == None):
      return False

    if root1.right != None and root2.right != None:
      var1 = self.recursive(root1.right, root2.right,myvar)
    elif (root1.right == None and root2.right != None) or (root1.right != None and root2.right == None):
      return False

    myvar[0] = myvar[0] and var1 and var2
    return myvar[0]
