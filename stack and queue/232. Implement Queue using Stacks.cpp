// steps
// push
// 1. s1 -> s2 swap
// 2. x -> s1
// 3. s2 -> s1 swap

// pop
// 1. s1.pop

class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> s1;
    stack<int> s2;
    
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int n = s1.top();
        s1.pop();
        return n;
    }
    
    /** Get the front element. */
    int peek() {
        return s1.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty();
    }
};

// optimized
// make 2 stack input and output

// push
// add x to input

// pop
// if !output.empty()
//      output.pop()
// else
//      input -> output
//      output.pop()

// top
// if !output.empty()
//      return output.top()
// else
//      input -> output
//      output.pop()

class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> input;
    stack<int> output;
    
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        input.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(!output.empty())
        {
            int n = output.top();
            output.pop();
            return n;
        }
        else
        {
            while(!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
            int n = output.top();
            output.pop();
            return n;
        }
    }
    
    /** Get the front element. */
    int peek() {
        if(!output.empty())
        {
            return output.top();
        }
        else
        {
            while(!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
            return output.top();
        }
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return output.empty() && input.empty();
    }
};
