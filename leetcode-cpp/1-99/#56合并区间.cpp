给出一个区间的集合，请合并所有重叠的区间。

示例 1:

输入: [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2:

输入: [[1,4],[4,5]]
输出: [[1,5]]
解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-intervals
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
---

class Solution {
public:
    static int cmp(const vector<int> &a,const vector<int> &b){
        if(a[0]==b[0])
            return a[1]<b[1];
        return a[0]<b[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        sort(inter.begin(),inter.end(),cmp);
        int i,j;
        vector<vector<int>> res;
        i=0;
        while(i<inter.size()){
            int s=inter[i][0],t=inter[i][1];
            j=i+1;
            while(j<inter.size() && inter[j][0]<=t){
                t=max(t,inter[j][1]);   //找下一个左边界大于t的右边界的
                j++;
            }
            res.push_back(vector<int>{s,t});
            if(j>=inter.size())
                break;
            i=j;    //看找到的j的下一个左边界
        }
        return res;
    }
};