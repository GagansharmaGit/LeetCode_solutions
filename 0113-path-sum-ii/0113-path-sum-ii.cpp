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
    vector<vector<int>>ans;
    void solve(TreeNode* root,int sum,int &targetSum,vector<int>temp){
        if(root == NULL) return;

        sum += root->val;
        temp.push_back(root->val);
        if(root->left == NULL and root->right == NULL){
            if(sum == targetSum){
                ans.push_back(temp);
            }
            sum -= root->val;
            temp.pop_back();
        }

        solve(root->left,sum,targetSum,temp);
        solve(root->right,sum,targetSum,temp);

        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>temp;
        solve(root,0,targetSum,temp);
        return ans;
    }
};