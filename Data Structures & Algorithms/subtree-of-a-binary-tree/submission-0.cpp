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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        queue<TreeNode* > q ;
          q.push(root);

    

        while(!q.empty()){
            TreeNode* hero = q.front();
            q.pop();

            if(check(hero , subRoot)){
                return true;
            }

            if(hero->left != nullptr){
                q.push(hero->left);
            }

            if(hero->right != nullptr){
                q.push(hero->right);
            }
          

        }

        return false;
        
    }


    bool check ( TreeNode* hero , TreeNode* subRoot){

        if( hero == nullptr && subRoot == nullptr){
            return true;
        }
        if((hero == nullptr && subRoot != nullptr) || (hero != nullptr && subRoot == nullptr) ){
                return false;
        }
       
        if( hero-> val == subRoot->val){
             bool right , left;
            left = check(hero->left , subRoot->left);
            right = check(hero->right , subRoot->right);
            return left && right;
        }

        return false;



    }
};
