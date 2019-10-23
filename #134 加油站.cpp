class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total = 0, cur = 0, start = 0;
        for(int i=0; i<n; i++){
            total += gas[i] - cost[i];
            cur += gas[i] - cost[i];
            if(cur<0){  //跑一圈找到一个cur永远不小于0的
                start = i+1;
                cur=0;
            }
        }

        return total >=0 ? start : -1;  //只要转一圈total gas>cost，就一定成立
    }
};