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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        TreeNode* parent = nullptr;
        TreeNode* temp = root;
        while(temp){
            parent = temp;
            if(temp->val < val){
                temp = temp->right;
            } else {
                temp = temp->left;
            }
        }
        if(parent->val > val){
            parent->left = new TreeNode(val);
        } else {
            parent->right = new TreeNode(val);
        }
        return root;
    }
};