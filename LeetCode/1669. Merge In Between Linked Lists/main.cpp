#include <bits/stdc++.h>
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
  ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
  {
    ListNode *temp = list1;
    ListNode *temp2 = list1;
    for (int i = 0; i < a - 1; i++)
    {
      temp = temp->next;
    }
    for (int i = 0; i < b + 1; i++)
    {
      temp2 = temp2->next;
    }
    temp->next = list2;
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = temp2;
    return list1;
  }
};

int main()
{
  int a = 3;
  int b = 4;

  ListNode *list1 = new ListNode(10);
  list1->next = new ListNode(1);
  list1->next->next = new ListNode(13);
  list1->next->next->next = new ListNode(6);
  list1->next->next->next->next = new ListNode(9);
  list1->next->next->next->next->next = new ListNode(5);

  ListNode *list2 = new ListNode(1000000);
  list2->next = new ListNode(1000001);
  list2->next->next = new ListNode(1000002);

  Solution s;
  ListNode *result = s.mergeInBetween(list1, a, b, list2);
  while (result != NULL)
  {
    cout << result->val << " ";
    result = result->next;
  }

  return 0;
}