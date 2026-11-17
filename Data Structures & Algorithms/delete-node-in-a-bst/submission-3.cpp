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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* nodeParent = nullptr;
        TreeNode* curr = root;
        while(curr && curr->val != key){
            nodeParent = curr;
            if(curr-> val < key){
                curr = curr->right;
            } else {
                curr = curr->left;
            } 
            
        }

        if(!curr) return root;
        
        if(curr->left){
            TreeNode* parent = curr;
            TreeNode* pred = curr->left;
            while(pred->right){
                parent = pred;
                pred = pred->right;
            }
            if(parent == curr) {
                parent->left = pred->left;
                parent->val = pred->val;
            } else {
                parent->right = pred->left;
                curr->val = pred->val;
            }
            delete pred;
        } else if (curr->right){
            TreeNode* parent = curr;
            TreeNode* successor = curr->right;
            while(successor->left){
                parent = successor;
                successor = successor->left;
            }
            if(parent == curr){
                parent->right = successor->right;
                parent->val = successor->val;
            } else {
                parent->left = successor->right;
                curr->val = successor->val;
            }
            delete successor;
        } else {
            if(!nodeParent){
                delete curr;
                return nullptr;
            }
            if(nodeParent->left == curr){
                nodeParent->left = nullptr;
            } else {
                nodeParent->right = nullptr;
            }
            
            delete curr;
        }
        return root;
    }
};