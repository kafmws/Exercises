class Solution {
    
    int getMin(int a, int b){
        return a>b?b:a;
    }
    
    public int minFallingPathSum(int[][] A) {
        for(int i = 1;i<A.length;i++){
            for(int j  = 0;j<A[0].length;j++){
                if(j == 0){
                    A[i][j] += getMin(A[i-1][j],A[i-1][j+1]);
                }else if(j == A[0].length-1){
                    A[i][j] += getMin(A[i-1][j],A[i-1][j-1]); 
                }else{
                    A[i][j] += getMin(getMin(A[i-1][j],A[i-1][j-1]), A[i-1][j+1]);
                }
            }
        }
        
        // for(int i = 0;i<A.length;i++){
        //     for(int j  = 0;j<A[0].length;j++){
        //         System.out.printf("%d ",A[i][j]);
        //     }
        //     System.out.println();
        // }
        
        
        
        int min = A[A.length-1][0];
        for(int i = 0;i<A[0].length;i++){
            if(A[A.length-1][i]<min){
                min = A[A.length-1][i];
            }
        }
        return min;
    }
}