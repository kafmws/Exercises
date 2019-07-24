//https://leetcode-cn.com/problems/regular-expression-matching/submissions/
class Solution {
    
    private static String s;
    private static String p;
    private static char []chars;
    private static boolean []isRepeated;
    private static int charsLen;

    public boolean isMatch(String s, String p) {
        if(p.contains("**"))return false;
        if(p.length()>0&&p.charAt(0)=='*')return false;
        Solution.s = s;
        Solution.p = p;
        examP();
        charsLen = 0;
        chars = new char[p.length()];//[0,charsLen)
        isRepeated = new boolean[p.length()];//[0,charsLen)
        for(int i = 0;i<p.length();i++){
            if(p.charAt(i)=='*'){
                isRepeated[charsLen-1] = true;
            }else{
                chars[charsLen++] = p.charAt(i);
            }
        }
        if(s.length()==0&&charsLen!=0){
            charsLen--;
            while (charsLen>=0){
                if(!isRepeated[charsLen--])return false;
            }
            return true;
        }
        return tryMatch(0,0);
    }

    private boolean tryMatch(int i, int j){//i→s,j→p
        while(i<s.length()&&j<charsLen) {
            if (s.charAt(i) == chars[j] || chars[j] == '.') {//匹配成功
                if (!isRepeated[j]) {i++;j++;}
                else {//可以任意次重复
                    return tryMatch(i, j+1) || tryMatch(i+1, j+1) || tryMatch(i+1, j);//0,1,多次
                }
            }
            else if(isRepeated[j]) {j++;}
            else return false;
        }
        if(i==s.length()&&j==charsLen)return true;
        if(i<s.length())return false;
        while(j<charsLen){
            if(!isRepeated[j]){
                return false;
            }
            j++;
        }
        return true;
    }

    private void examP(){
        char []chars = p.toCharArray();
        for(int i = 0;i<chars.length;i++){
            if(chars[i]=='*'){
                if(i<chars.length-1&&chars[i-1]==chars[i+1]){
                    chars[i] = chars[i+1];
                    chars[i+1] = '*';
                }
            }
        }
        p = String.valueOf(chars);
    }
}