//https://leetcode-cn.com/problems/lru-cache/submissions/
class LRUCache {

    private Map<Integer, Integer> cache;
    private Map<Integer, Integer> indexMap;//[key, index]
    private List<Integer> list;
    private int capacity;
    private int size;

    public LRUCache(int capacity) {
        cache = new HashMap(capacity);
        list = new ArrayList(capacity);
        this.capacity = capacity;
        size = 0;
    }
    
    public int get(int key) {
        if(!cache.keySet().contains(key))return -1;
        int re = cache.get(key);
        list.remove((Integer)key);
        list.add(key);
        return re;
    }
    
    public void put(int key, int value) {
        if(cache.keySet().contains(key)){
            cache.put(key, value);
            list.remove((Integer)key);
            list.add(key);
        }else if(size == capacity){
            int removeKey = list.get((int)0);
            cache.remove((Integer)removeKey);
            list.remove((int)0);
            cache.put(key, value);
            list.add(key);
        }else{
            cache.put(key, value);
            list.add(key);
            size++;
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */