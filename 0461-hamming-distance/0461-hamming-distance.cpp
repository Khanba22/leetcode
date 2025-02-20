class Solution {
public:
    int hammingDistance(int x, int y) {
        int dist = 0;
        while(x && y){
            dist+=!(x%2 == y%2);
            x/=2;
            y/=2;
        }
        while(x){
            dist+=x%2;
            x/=2;
        }
        while(y){
            dist+=y%2;
            y/=2;
        }
        return dist;
    }
};