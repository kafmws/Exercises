https://leetcode-cn.com/problems/triangle/submissions/
int minimumTotal(int** triangle, int triangleRowSize, int triangleColSize) {
    for(int i = triangleRowSize-2;i>=0;i--){//从倒数第二层开始
        for(int j = 0;j<=i;j++){
            triangle[i][j] += triangle[i+1][j]>triangle[i+1][j+1]?triangle[i+1][j+1]:triangle[i+1][j];
        }
    }
    return triangle[0][0];
}