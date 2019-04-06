class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Set<List<Integer>> results = new LinkedHashSet<>();
        Arrays.sort(nums);
        List<Integer> list = null;
        if(nums.length>=3){
            for(int i = 0;nums[i]<=0&&i<nums.length-2;i++){
                int j = i+1,k = nums.length-1;
                while(j<k){
                    int t = nums[i]+nums[j]+nums[k];
                    if(t==0){
                        // list = List.of(nums[i],nums[j],nums[k]);
                        list = new ArrayList<>();
                        list.add(nums[i]);
                        list.add(nums[j]);
                        list.add(nums[k]);
                        results.add(list);
                        j++;
                        k--;
                    }else if(t>0)
                        k--;
                    else
                        j++;
                }
            }
        }
        return new ArrayList<>(results);
    }
}