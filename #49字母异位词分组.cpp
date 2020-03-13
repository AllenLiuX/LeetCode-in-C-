给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/group-anagrams
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
---

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
    for(auto s : strs){
        string temp = s;
        sort(temp.begin(), temp.end());
        hash[temp].push_back(s);
    }
    int n = hash.size();
    vector<vector<string>> res(n);
    int i=0;
    for(auto v : hash){
        res[i] = v.second;
        i++;
    }
    return res;
    }
};