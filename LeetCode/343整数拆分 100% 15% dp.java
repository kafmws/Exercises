class Solution {
    public int integerBreak(int n) {
        int[] table = new int[59];
        table[2] = 1;
        table[3] = 2;
        table[4] = 4;
        table[5] = 6;
        table[6] = 9;
        for(int i = 7;i<=n;i++){
            table[i] = 2* table[i-2];
            if(3* table[i-3]> table[i]){
                table[i] = 3* table[i-3];
            }
            for(int x = 4,y = i-4;x<=y;x++,y--){
                if(table[x]* table[y]> table[i]){
                    table[i] = table[x]* table[y];
                }
            }
        }
        return table[n];
    }
}