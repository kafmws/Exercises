//放进数组   由数组比较
//交换左右子树  比较相等
//放进数组  交换后与数组比较
//同时遍历

void compare(struct TreeNode* left, struct TreeNode* right, int *result){
    if(*result == 0 || left==NULL&&right==NULL)return;
    if((!left) || (!right) || left->val!=right->val){
        *result = 0;
        return;
    }
    compare(left->left,right->right,result);
    compare(left->right,right->left,result);
}

bool isSymmetric(struct TreeNode* root){
    if(!root)return true;
    int result = 1;
    compare(root,root,&result);
    return result;
}

