class MyQueue {
public:
    stack<int> pusher, popper;
    MyQueue() {
        while (!pusher.empty()) pusher.pop();
        while (!popper.empty()) popper.pop();        
    }
    
    void push(int x) {
       pusher.push(x); 
    }
    
    int pop() {
        int ans = peek();
        popper.pop();
        return ans;
    }
    
    int peek() {
        if(popper.empty()){
            while(!pusher.empty()){
                popper.push(pusher.top());
                pusher.pop();
            }
        }
        return popper.top();
    }
    
    bool empty() {
        return pusher.empty() && popper.empty();
    }
};
