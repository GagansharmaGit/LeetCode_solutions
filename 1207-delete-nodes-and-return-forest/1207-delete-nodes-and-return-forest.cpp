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
    vector<TreeNode*>ans;
    TreeNode* solve(TreeNode* root,unordered_map<int,bool>&mp){
        if(root == NULL) return NULL;

        root->left = solve(root->left,mp);
        root->right = solve(root->right,mp);

        if(mp.find(root->val) != mp.end()){
            if(root->left != NULL) ans.push_back(root->left);
            if(root->right != NULL) ans.push_back(root->right);
            return NULL;
        }else {
            return root;
        }    
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    
        unordered_map<int,bool>mp;
        for(auto i:to_delete){
            mp[i] = true;
        }
         if(mp.find(root->val) == mp.end()) ans.push_back(root);
        solve(root,mp);
        
        return ans;
    }
};