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
    int max_diff = INT_MIN;
    int depth(TreeNode* root, int gap){
        if(max_diff>1) return gap;
        if(!root) return gap;
        int a = depth(root->left, gap + 1);
        int b = depth(root->right, gap + 1);
        max_diff = max(max_diff, abs(a-b));
        return max(a,b);
    }
    bool isBalanced(TreeNode* root) {
        depth(root, 0);
        return max_diff<2;
    }
};
