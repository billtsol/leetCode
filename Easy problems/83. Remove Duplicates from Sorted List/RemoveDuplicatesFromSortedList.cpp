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
Complexity Analysis

Time complexity : O(n). Because each node in the list is checked exactly once to determine if it is a duplicate or not, the total run time is O(n)O(n)O(n), where nnn is the number of nodes in the list.

Space complexity : O(1). No additional space is used.
*/