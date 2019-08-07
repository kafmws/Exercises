class Solution {
    public String decodeString(String s) {
        //先展开最内层的
        StringBuilder sb = new StringBuilder(s);
        int begin;
        int end;
        while((begin = sb.lastIndexOf("["))!=-1){
            end = sb.indexOf("]",begin);
            String str = sb.substring(begin+1,end);//[]中重复内容
            begin--;//begin数字位置
            int numEnd = begin;
            while(begin>=0&&sb.charAt(begin)>='0'&&sb.charAt(begin)<='9'){
                begin--;
            }
            begin++;
            int times = Integer.parseInt(sb.substring(begin,numEnd+1));
            //先replace再insert
            sb.replace(begin,end+1,str);
            int border = begin + str.length();
            for(int i = 1;i<times;i++){
                sb.insert(border,str);
                border+=str.length();
            }
        }
        return sb.toString();
    }
}