class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (true) System.out.println(new Solution().numSquares(in.nextInt()));
    }

    public int numSquares(int n) {
        int cnt = 1;
        Queue<Integer> queue = new LinkedList<>();
        Set<Integer> set = new LinkedHashSet<>(1024);
        queue.offer(n);
        set.add(n);
        queue.offer(null);
        Integer num;
        while (true) {
            num = queue.remove();
            if (num == null) {
                cnt++;
                if (!queue.isEmpty()) queue.offer(null);
                continue;
            }
            int max = (int) Math.sqrt(num);
            while (max != 0) {
                int t = num - max * max;
                if (t == 0) return cnt;
                if(!set.contains(t)){
                    queue.offer(t);
                    set.add(t);
                }
                max--;
            }
        }
    }
}