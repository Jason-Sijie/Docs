
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root){return true;}
        
        bool valid = true;
        if(root->left != nullptr){
            valid = isValidBST(root->left);
        }
        if(!valid)  {return valid;}

        if(lastVal == nullptr){
            lastVal = new int;
            *lastVal = root->val;
        }
        else if(*lastVal >= root->val){
            return false;
        }
        else{
            *lastVal = root->val;
        }

        if(root->right != nullptr){
            valid = isValidBST(root->right);
        }
        return valid;
    }


private:
    int* lastVal;
};
