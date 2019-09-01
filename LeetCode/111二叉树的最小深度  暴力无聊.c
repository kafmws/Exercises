void re(struct TreeNode* root, int curDepth, int *res){
    if(root->right == root->left && curDepth<(*res))(*res) = curDepth;
    if(root->right)re(root->right,curDepth+1,res);
    if(root->left)re(root->left,curDepth+1,res);
}

int minDepth(struct TreeNode* root){
    int res = 0x3f3f3f3f;
    if(root)re(root,1,&res);
    else res = 0;
    return res;
}