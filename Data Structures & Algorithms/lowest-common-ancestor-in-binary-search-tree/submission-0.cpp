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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        TreeNode* ans = nullptr;

        int l = solve( root , p , q  , ans);

        return ans;
        
    }

    int solve( TreeNode* root, TreeNode* p, TreeNode* q  , TreeNode* &ans){


            if( ans != nullptr ){
                return 0;
            }

            if( root == nullptr){
                return 0 ;
            }

            int current = 0 ;

            if( root==p ){
                current = 1;
            }else if ( root==q){
                current = 2;
            }

            int left = solve( root->left , p , q , ans);
            int right = solve( root->right , p , q , ans);

            if(( left == 1 && right == 2) || ( left == 2 && right == 1) ){
                // found 
                ans = root;
              
            }

            if(( current == 1 && left == 2) || ( current == 2 && left == 1) || ( current == 1 && right == 2) || ( current == 2 && right == 1) ){
                ans = root;
            }

            if(current > 0 ){
                return current;
            }else if(left > 0 ){
                return left;
            }else if ( right > 0 ){
                return right;
            }

            return 0;


    }
};
