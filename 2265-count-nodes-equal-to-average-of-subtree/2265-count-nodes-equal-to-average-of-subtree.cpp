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
    int ans = 0;
    pair<int,int> dfs(TreeNode* root){
        if(root==NULL){
            return {0, 0};
        }

        auto[leftSum, leftCount] = dfs(root->left); 
        auto[rightSum, rightCount] = dfs(root->right);


        int currSum = leftSum+rightSum+root->val;
        int currCnt = leftCount+rightCount+1;
        int avg = currSum/currCnt;
        if(avg == root->val) ans++;

        return{currSum, currCnt};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};