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

    int result;

    pair<int,int> solve(TreeNode* root,int &result){
        if(root == NULL){
            return make_pair(0,0);
        }
        int count = 0;
        auto left = solve(root->left,result);
        auto right = solve(root->right,result);

        int sum = left.first + right.first + root->val;
         count = left.second + right.second + 1;

        if(sum/count == root->val) result++;

        return make_pair(sum,count);
    }
    int averageOfSubtree(TreeNode* root) {
        result = 0;

        solve(root,result);
        return result;
    }
};