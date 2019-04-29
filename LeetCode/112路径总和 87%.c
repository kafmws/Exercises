bool re(struct TreeNode* root, int currentSum,int sum){
    if(!root)return false;
    currentSum+=root->val;
    if(root->left==NULL&&root->right==NULL){//是叶子结点
        if(currentSum == sum)return true;
    }
    return re(root->left,currentSum,sum)||re(root->right,currentSum,sum);
}

bool hasPathSum(struct TreeNode* root, int sum){
    if(root==NULL)return false;
    return re(root,0,sum);
}