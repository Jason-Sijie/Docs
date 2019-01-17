#include <iostream>
#include <string>
using namespace std;

struct TreeNode{
    char val;
    struct TreeNode* left;
    struct TreeNode* right;
};
typedef struct TreeNode TNode;

class Solution {
public:
    int calculate(string s) {
        for(int i = 0; i<s.size(); i++){
            TNode* newNode = NewTreeNode(s[i]);
            
        }
    }

private:
    TNode* NewTreeNode(char s){
        TNode* newNode = new TNode;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->val = s;
        return newNode;
    }
};