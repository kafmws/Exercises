import java.util.LinkedList;
import java.util.List;

class MyStack {

    //push to back, peek/pop from front, size, 和 is empty
    private List<Integer> stack;

    /** Initialize your data structure here. */
    public MyStack() {
        stack = new LinkedList<>();
    }

    /** Push element x onto stack. */
    public void push(int x) {//[    top]
        stack.add(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        return stack.remove(stack.size()-1);
    }

    /** Get the top element. */
    public int top() {
        return stack.get(stack.size()-1);
    }

    /** Returns whether the stack is empty. */
    public boolean empty() {
        return stack.isEmpty();
    }
}