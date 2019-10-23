class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int m = prices[0];  //空的时候不能[0]
        int p = 0;
        int s = prices.size();
        for(int i=1; i<s; i++){ //每个点前后一共四种情况
            if(prices[i] < prices[i-1]){    //只要比前一个低就买
                m = prices[i];
            }
            if(i==s-1 || prices[i] > prices[i+1]){  //只要比后一个高就卖
                p += prices[i] - m;
                m = prices[i];

            }
        }
        return p;
    }
};


//更简单的方法：只求高度差
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1])
                maxprofit += prices[i] - prices[i - 1];
        }
        return maxprofit;
    }
};