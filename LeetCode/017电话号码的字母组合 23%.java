class Solution {
    
    private Map<String,Integer> res = new HashMap<>();
    private char[] str;
    private String digits;

    private void re(int i){
        if(i == digits.length()){
            res.put(String.valueOf(str),0);
            return;
        }
        char c = (char) ((digits.charAt(i)-'2')*3+'a');
        if(c=='s'||c=='v')c++;
        for(int j = 0;j<3;j++){
            str[i] = (char) (c+j);
            re(i+1);
        }
        if(c=='p'||c=='w'){
            str[i] = (char) (c+3);
            re(i+1);
        }
    }

    public List<String> letterCombinations(String digits) {
        if(digits.length()==0){
            return new ArrayList<>();
        };
        this.digits = digits;
        str = new char[digits.length()];
        re(0);
        return new ArrayList<>(res.keySet());
    }
    
}