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

class Solution {
public:
    int diameter = INT_MIN;
    int depth(TreeNode* root){
        if(!root) return -1;
        int a = depth(root->left) + 1;
        int b = depth(root->right) + 1;
        diameter = max(diameter, a+b);
        return max(a,b);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return diameter;
    }
};
