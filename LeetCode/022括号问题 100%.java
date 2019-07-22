//https://leetcode-cn.com/problems/generate-parentheses/	
class Solution{	
	private char[] sb;
    private List<String> res = new ArrayList<>();
    private int len;
    private int left;
    private int right;


    private void re(int i) {
        if(i>len){
            res.add(String.valueOf(sb));
            return;
        }
        if(left>0){
            sb[i] = '(';
            left--;
            re(i+1);
            left++;
        }
        if(left<right){
            sb[i] = ')';
            right--;
            re(i+1);
            right++;
        }
    }

    public List<String> generateParenthesis(int n) {
        len = 2*n-1;//[0,len]
        sb = new char[len+1];
        left = right = n;
        re(0);
        return res;
    }
}