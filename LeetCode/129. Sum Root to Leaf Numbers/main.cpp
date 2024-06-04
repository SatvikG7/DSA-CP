#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  int sumNumbers(TreeNode *root)
  {
    return dfs(root, 0);
  }

  int dfs(TreeNode *node, int sum)
  {
    if (!node)
      return 0;

    sum = sum * 10 + node->val;

    if (!node->left && !node->right)
      return sum;

    return dfs(node->left, sum) + dfs(node->right, sum);
  }
};

int main()
{
  // tree is [4,9,0,5,1]
  TreeNode *root = new TreeNode(4);
  root->left = new TreeNode(9);
  root->right = new TreeNode(0);
  root->left->left = new TreeNode(5);
  root->left->right = new TreeNode(1);

  Solution sol;
  cout << sol.sumNumbers(root) << endl;

  return 0;
}