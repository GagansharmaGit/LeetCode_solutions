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
    vector<TreeNode*> solve(int n){
        if(n%2 == 0) return {};
        if(n == 1) return {new TreeNode(0)};
        vector<TreeNode*>ans;
        for(int i=1;i<n;i+=2){
            vector<TreeNode*> left_full_b_tree =solve(i);
            vector<TreeNode*> right_full_b_tree = solve(n-i-1);
            for(auto left:left_full_b_tree){
                for(auto right:right_full_b_tree){
                    TreeNode* node = new TreeNode(0);
                    node->left = left;
                    node->right = right;
                    ans.push_back(node);
                }
            } 

        }
        return ans;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        return solve(n);
    }
};