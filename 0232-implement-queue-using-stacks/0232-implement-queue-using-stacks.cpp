class MyQueue {
public:

    stack<int>s1,s2;
    MyQueue() {}
    
    void push(int x) {
        //moving all s1 -> s2
        while(s1.size()){
            s2.push(s1.top());
            s1.pop();
        }
        //pushing the new element to s1
        s1.push(x);
        //pushing s2->s1
        while(s2.size()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int val = s1.top();
        s1.pop();
        return val;
    }
    
    int peek() {
     return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */