/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(TreeNode* root,TreeNode* p,TreeNode* q){
        if(root == NULL) return NULL;

        if(root == p or root == q) return root;

        TreeNode* leftAns = solve(root->left,p,q);
        TreeNode* rightAns = solve(root->right,p,q);
        if(leftAns != NULL and rightAns != NULL){
            return root;
        }else if(leftAns != NULL and rightAns == NULL){
            return leftAns;
        }else{
            return rightAns;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root,p,q);
    }
};