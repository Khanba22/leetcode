class Solution {
public:
    int maxDepth(string s) {
        int maxi = 0;
        vector<int>stack;
        int curr = 0;
        for(char & c:s){
            if(c == '('){
                if(stack.empty()){
                     stack.push_back(1);
                }else{
                    stack.push_back(stack.back() + 1);
                }
            }else if(c == ')'){
                maxi = max(stack.back(),maxi);
                stack.pop_back();
            }
        }
        return maxi;
    }
};