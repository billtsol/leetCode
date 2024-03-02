from typing import List, Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
  def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
    return self.newNode(root)

  def newNode(self,root):
    currList = []
    if root == None:
      return []

    if root.left != None:
      currList = self.newNode(root.left)

    currList.append(root.val)

    if root.right != None:
      currList = currList + self.newNode(root.right)

    return currList
