// Definition for singly-linked list.
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
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
  {
    if (list1 == nullptr)
    {
      return list2;
    }
    else if (list2 == nullptr)
    {
      return list1;
    }

    ListNode *resultList = nullptr;
    ListNode *tail = nullptr;

    if (list1->val < list2->val)
    {
      resultList = list1;
      list1 = list1->next;
    }
    else
    {
      resultList = list2;
      list2 = list2->next;
    }

    tail = resultList;

    while (list1 != nullptr && list2 != nullptr)
    {

      if (list1->val < list2->val)
      {
        tail->next = list1;
        list1 = list1->next;
      }
      else
      {
        tail->next = list2;
        list2 = list2->next;
      }

      tail = tail->next;
    }

    if (list1 != nullptr)
    {
      tail->next = list1;
    }
    else
    {
      tail->next = list2;
    }

    return resultList;
  }
};

/*

Complexity Analysis

Time complexity : O(n+m)

Because exactly one of l1 and l2 is incremented on each loop iteration, the while loop runs for a number of iterations equal to the sum of the lengths of the two lists. All other work is constant, so the overall complexity is linear.

Space complexity : O(1)

*/