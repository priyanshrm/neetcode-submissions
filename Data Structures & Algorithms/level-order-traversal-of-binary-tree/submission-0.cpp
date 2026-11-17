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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<TreeNode*>> ans;
        vector<vector<int>> values;
        if(!root) return values;
        ans.push_back({root});
        queue<int> q;
        q.push(0);

        while(!q.empty()){
            int k = q.front();
            q.pop();
            vector<TreeNode*> temp;
            for(int i = 0; i<ans[k].size(); i++){
                if(!ans[k][i]) break;
                if(ans[k][i]->left){
                    temp.push_back(ans[k][i]->left);
                }
                if(ans[k][i]->right){
                    temp.push_back(ans[k][i]->right);
                }    
            }
            if(temp.size()>0) {
                ans.push_back(temp);
                q.push(k+1);
            }
        }

        
        for(int i = 0; i<ans.size(); i++){
            vector<int> temp;
            for(int j = 0; j<ans[i].size(); j++){
                temp.push_back(ans[i][j]->val);
            }
            values.push_back(temp);
        }
        return values;
    }
};
