//https://leetcode-cn.com/problems/n-queens/submissions/
class Solution {
    private List<List<String>> res = new ArrayList<>();
    private char[] str;//母串  "...."
    private int[] lines;
    private int num;

    private void swap(int i, int j){
        int t = lines[i];
        lines[i] = lines[j];
        lines[j] = t;
    }

    private boolean isValid(int index){//[0,index)
        for(int i = 0;i<index;i++){
            if(i-index==lines[i]-lines[index]||index-i==lines[i]-lines[index])return false;
        }
        return true;
    }

    private void re(int i){
        if(i>=num){
            List<String> list = new ArrayList<>();
            for(int row = 0;row<num;row++){
                str[lines[row]]='Q';
                list.add(String.valueOf(str));
                str[lines[row]]='.';
            }
            res.add(list);
            return;
        }
        for(int j = i;j<num;j++){
            swap(i,j);
            if(isValid(i)){
                re(i+1);
            }
            swap(i,j);
        }
    }

    public List<List<String>> solveNQueens(int n) {
        num = n;
        lines = new int[n];
        str = new char[n];
        for(int i = 0;i<n;i++){
            lines[i] = i;
            str[i] = '.';
        }
        re(0);
        return res;
    }
}