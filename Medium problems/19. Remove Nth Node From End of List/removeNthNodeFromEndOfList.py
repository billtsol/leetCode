
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:

        size = 0

        tempList = head
        while tempList is not None:
            size += 1
            tempList = tempList.next

        resultList = head

        deleted_index = size - n
        tempList = head


        if deleted_index == 0:
            if size == 1:
                return None
            else:
                return head.next

        i = 0
        while tempList is not None:
            if i == deleted_index - 1:
                tempList.next = tempList.next.next
                break

            tempList = tempList.next
            i += 1

        return resultList
