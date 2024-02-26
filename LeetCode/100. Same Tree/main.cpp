#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// class Solution
// {
// public:
//   bool dfs(TreeNode *p, TreeNode *q)
//   {
//     if (p == nullptr && q == nullptr)
//       return true;
//     if (p == nullptr || q == nullptr)
//       return false;
//     if (p->val != q->val)
//       return false;

//     return dfs(p->left, q->left) && dfs(p->right, q->right);
//   }

//   bool isSameTree(TreeNode *p, TreeNode *q)
//   {
//     return dfs(p, q);
//   }
// };


class Solution
{
public:

  bool isSameTree(TreeNode *p, TreeNode *q)
  {
    return p == nullptr && q == nullptr ? true : p == nullptr || q == nullptr ? false : p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }
};

int main()
{

  TreeNode *p = new TreeNode(1, new TreeNode(2), new TreeNode(3));
  TreeNode *q = new TreeNode(1, new TreeNode(2), new TreeNode(3));

  Solution s;
  cout << s.isSameTree(p, q) << endl;

  return 0;
}