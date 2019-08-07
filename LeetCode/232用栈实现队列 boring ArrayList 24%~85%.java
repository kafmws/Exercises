class MyQueue {

    private List<Integer> queue;

    /** Initialize your data structure here. */
    public MyQueue() {
        queue = new ArrayList<>(100);
    }

    /** Push element x to the back of queue. */
    public void push(int x) {// [front    tail]
        queue.add(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        return queue.remove(0);//pop(size-1)
    }

    /** Get the front element. */
    public int peek() {
        return queue.get(0);//peek(size - 1)
    }

    /** Returns whether the queue is empty. */
    public boolean empty() {
        return queue.isEmpty();
    }
}