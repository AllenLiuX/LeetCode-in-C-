Tags: 递归
给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: [1,2,2]
输出:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subsets-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
---

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret = {{}};
        if(nums.empty()) return ret;
        sort(nums.begin(), nums.end());     // 排序
        int start = 0;
        for (int i = 0; i < nums.size(); i++) {
            int len = ret.size();
            if (i>0 && nums[i]!=nums[i-1])
                start = 0;          // 新数字，全部遍历
            for(int j = start; j < len; j++){
                vector<int> tmp = ret[j];
                tmp.push_back(nums[i]);
                ret.push_back(tmp);
            }
            start = ret.size() - (len - start); // 重复数字,从上一轮新添加的部分开始
        }

        return ret;

    }
};