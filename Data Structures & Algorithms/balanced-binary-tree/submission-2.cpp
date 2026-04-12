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
   solve(root , ans , 0);

    return ans;
        
    }

    int solve( TreeNode* root , bool &ans , int count){

        if( root == nullptr || ans == false){
            return 0 ;
        }

        int left = solve(root->left , ans , count);
        int right = solve( root->right , ans , count);

        if( abs(left - right) > 1 ){
            ans = false;
            return 0 ; 
        }

        return max(left , right) + 1;


    }
};
