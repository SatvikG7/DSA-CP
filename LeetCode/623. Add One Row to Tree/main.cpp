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
  TreeNode *addOneRow(TreeNode *root, int val, int depth)
  {
    if (depth == 1)
    {
      TreeNode *newRoot = new TreeNode(val);
      newRoot->left = root;
      return newRoot;
    }

    queue<TreeNode *> q;
    q.push(root);
    int d = 1;

    while (!q.empty())
    {
      int size = q.size();

      for (int i = 0; i < size; i++)
      {
        TreeNode *node = q.front();
        q.pop();

        if (d == depth - 1)
        {
          TreeNode *left = new TreeNode(val);
          TreeNode *right = new TreeNode(val);

          left->left = node->left;
          right->right = node->right;

          node->left = left;
          node->right = right;
        }
        else
        {
          if (node->left)
            q.push(node->left);
          if (node->right)
            q.push(node->right);
        }
      }

      if (d == depth - 1)
        break;

      d++;
    }

    return root;
  }
};

int main()
{
  //  root = [4,2,null,3,1], val = 1, depth = 3
  TreeNode *root = new TreeNode(4);
  root->left = new TreeNode(2);
  root->right = nullptr;
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(1);

  Solution sol;
  TreeNode *newRoot = sol.addOneRow(root, 1, 3);

  //  verify
  //  root = [4,1,1,2,null,null,3,null,1]
  cout << newRoot->val << endl;
  cout << newRoot->left->val << endl;
  cout << newRoot->right->val << endl;
  cout << newRoot->left->left->val << endl;
  cout << newRoot->left->right->val << endl;
  cout << newRoot->right->left << endl;
  cout << newRoot->right->right->val << endl;
  cout << newRoot->left->left->left << endl;
  cout << newRoot->left->left->right->val << endl;

  return 0;
}