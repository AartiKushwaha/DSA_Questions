class FreqStack {
public:
    map<int, int> f;
    map<int, stack<int>> m;
    int mf;
    FreqStack() {
        f.clear();
        m.clear();
        mf=INT_MIN;
    }
    
    void push(int x) {
        f[x]++;
        mf=max(mf, f[x]);
        m[f[x]].push(x);
    }
    
    int pop(){
        int x=m[mf].top();
        m[mf].pop();
        f[x]--;
        if(m[mf].size()==0){
            mf--;
        }
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */