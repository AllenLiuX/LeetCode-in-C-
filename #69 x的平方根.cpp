class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1)
            return x;
        int l=0;
        int r=x;
        while(l<=r){
            int mid = l+(r-l)/2;    //放在循环里面！每次调整
            int low = x/mid; //用来判断mid大于目标还是小于目标，或等于目标
            int high = x/(mid+1);
            if(low==mid || (low>mid && high<mid+1)) //刚好是他的算术平方根or之间
                return mid;
            if(low>mid){    //mid太小
                l=mid+1;
            }
            if(low<mid)     //mid太大
                r=mid-1;
        }
        return l;   
    }
};