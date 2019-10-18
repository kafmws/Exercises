class Solution {

    private HashSet<String> dict = new HashSet<>();
    private boolean [] len;

    public boolean wordBreak(String s, List<String> wordDict) {
        dict.addAll(wordDict);
        len = new boolean[s.length()+1];
        StringBuilder sb = new StringBuilder(s);
        for(int i = 1;i<=s.length();i++){
            len[i] = dict.contains(sb.substring(0,i));
            if(!len[i]){
                for(int j = 1;j<i;j++){
                    if(len[j]&&dict.contains(sb.substring(j,i))){
                        len[i] = true;
                        break;
                    }
                }
            }
        }
        // for(boolean b : len){
        //     System.out.printf(b+" ");
        // }
        return len[s.length()];
    }
}