class MyStack {
public:
    queue<int> q1, q2;
    MyStack() {

    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while(q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }
        //last element in q1
        int x = q1.front(); q1.pop();
        q1.swap(q2);
        return x;        
    }
    
    int top() {
        return q1.back();
    }
    
    bool empty() {
        return q1.empty(); 
    }
};

