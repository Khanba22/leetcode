class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int left = 0, right = n-1;
        int top = 0, bottom = n-1;
        int val = 0;
		
        vector<vector<int>> v(n, vector<int> (n));
        while(left <= right && top <= bottom)
        {
            for(int i = left; i <= right; ++i)
                v[top][i] = ++val;
				
            for(int i = top+1; i <= bottom; ++i)
                v[i][right] = ++val;
				
            if(top < bottom && left < right)
            {
                for(int i = right-1; i>left; --i)
                    v[bottom][i] = ++val;
					for(int i = bottom; i>top; --i) 
                    v[i][left] = ++val;
            }
            ++top;
            --bottom;
            ++left;
            --right;
        }
        return v;
    }
};