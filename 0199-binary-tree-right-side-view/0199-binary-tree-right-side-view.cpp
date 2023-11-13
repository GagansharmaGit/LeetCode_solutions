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
    vector<int>result;
    void solve(TreeNode* root,int &mxlevel,int currlevel){
        if(root == NULL) return;

        if(currlevel > mxlevel) result.push_back(root->val);
        mxlevel = max(mxlevel,currlevel);
        solve(root->right,mxlevel,currlevel+1);
        solve(root->left,mxlevel,currlevel+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        int mxlevel = -1;
        solve(root,mxlevel,0);
        return result;
    }
};