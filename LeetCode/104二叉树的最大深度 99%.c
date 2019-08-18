void measureDepth(struct TreeNode *root, int depth, int *max){
    if(depth>(*max))(*max)=depth;
    if(root->left)measureDepth(root->left,depth+1,max);
    if(root->right)measureDepth(root->right,depth+1,max);
}

int maxDepth(struct TreeNode* root){
    int max = 0;
    if(root)measureDepth(root,1,&max);
    return max;
}