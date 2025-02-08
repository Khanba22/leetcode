class NumberContainers {
public:
    unordered_map<int,int>indextoval;
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> res;

    void change(int index, int number) {
        if(indextoval.find(index)!=indextoval.end()){
            int prev = indextoval[index];
            if(prev == number) return;
        }
        res[number].push(index);
        indextoval[index] = number;
    }
    
    int find(int number) {
        while(!res[number].empty() && indextoval[res[number].top()] != number){
            res[number].pop();
        }
        return res[number].empty() ? -1 : res[number].top();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */