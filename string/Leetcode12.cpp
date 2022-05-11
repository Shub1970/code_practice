#include <iostream>
#include <string>
#include <vector>
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
void printTree(TreeNode *root, vector<string> &ans, string t)
{
    if (root->left == nullptr && root->right == nullptr)
    {
        ans.push_back(t + to_string(root->val));
    }
    if (root->left != nullptr)
        printTree(root->left, ans, t + "->" + to_string(root->val) + "->");
    if (root->right != nullptr)
        printTree(root->right, ans, t + "->" + to_string(root->val) + "->");
}

class Solution
{

public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ans;
        if (root == nullptr)
            return ans;
        printTree(root, ans, to_string(root->val));
        return ans;
    }
};
