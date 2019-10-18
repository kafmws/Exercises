//https://leetcode-cn.com/problems/palindrome-partitioning/submissions/
class Solution {

    private List<List<String>> res = new LinkedList<>();
    private int[]position;
    private String str;

    private boolean isPalindrome(int begin, int end){//[begin, end]
        while (begin<end){
            if(str.charAt(begin)==str.charAt(end)){
                begin++;
                end--;
            }else return false;
        }
        return true;
    }

    private void re(int i, int lastOne){
        if(i==position.length){
//            System.out.println(Arrays.toString(position));
            List<String> stringList = new LinkedList<>();
            int lastIndex = 0;
            for(int j = 0;j<position.length;j++){
                if(position[j]==1){
                    stringList.add(str.substring(lastIndex,j+1));
                    lastIndex = j+1;
                }
            }
            if(!isPalindrome(lastIndex,position.length))return;
            stringList.add(str.substring(lastIndex,position.length+1));
            res.add(stringList);
            return;
        }
        position[i] = 1;
        if(isPalindrome(lastOne,i)){ re(i+1, i+1); }
//        re(i+1, i);
        position[i] = 0;
        re(i+1, lastOne);
    }

    public List<List<String>> partition(String s) {
        if(s.equals("")){ res.add(new LinkedList<>());return res; }
        position = new int[s.length()-1];
        str = s;
        re(0, 0);
        return res;
    }
}