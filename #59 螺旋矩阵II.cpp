class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n==0) return {{}};
        vector<vector<int> > res(n,vector<int>(n,0));
        int down=0,up=n-1,left=0,right=n-1;
        int itm=1;
        while(left<=right && down<=up){
            for(int i=left;i<=right;i++) 
                res[down][i]=itm++;
            for(int i=down+1;i<=up;i++) 
                res[i][right]=itm++;
            for(int i=right-1;i>=left;i--) 
                res[up][i]=itm++;
            for(int i=up-1;i>=down+1;i--) 
                res[i][left]=itm++;
            down++;
            up--;
            left++;
            right--;
        }
        return res;
    }
};