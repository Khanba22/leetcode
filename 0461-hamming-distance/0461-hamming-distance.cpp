class Solution {
public:
    int hammingDistance(int x, int y) {
        int dist = 0;
        while(x > 0 && y > 0){
            dist+=x%2 == y%2?0:1;
            x/=2;
            y/=2;
        }
        while(x>0){
            dist+=x%2;
            x/=2;
        }
        while(y>0){
            dist+=y%2;
            y/=2;
        }
        return dist;
    }
};