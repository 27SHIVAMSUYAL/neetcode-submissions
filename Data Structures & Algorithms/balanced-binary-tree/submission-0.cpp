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
    bool isBalanced(TreeNode* root) {

    
        bool ans = true;
    int len = solve(root , ans , 0);

    return ans;
        
    }

    int solve( TreeNode* root , bool &ans , int count){

        if( root == nullptr){
            return 0 ;
        }

        int left = solve(root->left , ans , count);
        int right = solve( root->right , ans , count);

        if( abs(left - right) > 1 ){
            ans = false;
        }

        return max(left , right) + 1;


    }
};
