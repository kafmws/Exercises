class Solution {
    private Set<String> set = new HashSet<>();

    private Set<String> deadends = new HashSet<>();

    private boolean isInDeadEnds(String t){
        return deadends.contains(t);
    }

    public int openLock(String[] deadends, String target) {
        String tem = "0000";
        if(tem.equals(target))return 0;
        this.deadends.addAll(Arrays.asList(deadends));
        if(this.deadends.contains(tem))return -1;
        Queue<String> queue = new LinkedList<>();
        int cnt = 1;
        queue.offer(tem);
        set.add(tem);
        queue.offer(null);
        while(!queue.isEmpty()){
            tem = queue.remove();
            if(tem==null){
                cnt++;
                if(!queue.isEmpty()) queue.offer(null);
                continue;
            }
            for(int i = 0;i<4;i++){
                char[] t = tem.toCharArray();
                t[i] = t[i]=='9'?'0': (char) (t[i] + 1);
                String str = String.valueOf(t);
                if(!set.contains(str)&&!isInDeadEnds(str)){
                    if(str.equals(target))return cnt;
                    queue.offer(str);
                    set.add(str);
                }
                t[i] = t[i]=='0'?'9': (char) (t[i] - 1);
                t[i] = t[i]=='0'?'9': (char) (t[i] - 1);
                str = String.valueOf(t);
                if(!set.contains(str)&&!isInDeadEnds(str)){
                    if(str.equals(target))return cnt;
                    queue.offer(str);
                    set.add(str);
                }
            }
        }
        return -1;
    }
}       