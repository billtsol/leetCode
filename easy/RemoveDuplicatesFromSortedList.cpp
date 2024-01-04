#include <iostream>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  ListNode *deleteDuplicates(ListNode *head)
  {

    if (head == nullptr)
      return head;

    int number = head->val;
    ListNode *temp = head;
    ListNode *currentNode = head->next;

    while (currentNode != nullptr)
    {

      if (number != currentNode->val)
      {
        temp->next = currentNode;
        temp = temp->next;

        number = currentNode->val; // Change the current number
      }

      currentNode = currentNode->next;
      temp->next = nullptr;
    }

    return head;
  }
};

/*
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

Example 1:

Input: head = [1,1,2]
Output: [1,2]

Input: head = [1,1,2,3,3]
Output: [1,2,3]

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
*/